#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct listNode {
    T data; 
    struct listNode<T> *nextPtr; 
    bool operator==(const T i) const { 
        return data == i; 
    }
};
template <typename T> //type defind
using ListNode = listNode<T>;
template <typename T>
using ListNodePtr = listNode<T>*;

template <class Node>
class node_wrap{
public:
    Node* ptr;
    node_wrap(Node* p = nullptr) : ptr(p) { }

    class iterator{
    public:
        typedef iterator self_type;
        typedef Node value_type;
        typedef Node& reference;
        typedef Node* pointer;
        typedef forward_iterator_tag iterator_category;
        typedef Node difference_type;
        iterator(pointer p ) : ptr_(p) { }
        self_type operator++() { self_type i = *this; ptr_++; return i; }
        self_type operator++(int) { ptr_++; return *this; } 
        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }
        bool operator==(const self_type& i) const { 
            return ptr_ == i.ptr_; 
        }
        bool operator!=(const self_type& i) const { 
            return ptr_ != i.ptr_; 
        }
        friend ostream& operator<<(ostream& os, const iterator& dt){
        os << dt.ptr_;
        return os;
    }
    private:
        Node* ptr_;
    };
    bool operator!=(const node_wrap& i) const { 
            return ptr != i.ptr; 
    }
    bool operator==(const node_wrap& i) const { 
            return ptr == i.ptr; 
    }
    Node& operator*() const { return *ptr; }
    Node* operator->() const { return ptr; }

    iterator begin(){
        return iterator(ptr);
    }
    iterator end(){
        node_wrap temp = ptr;
        while(temp -> nextPtr!=NULL)
            temp = temp->nextPtr;
        return iterator(temp.ptr);
    }
};

void instructions( void );
template <typename T>
void Choice(node_wrap<ListNode<T>> &startPtr, unsigned int choice, string type);
template <typename T>
void Insert(node_wrap<ListNode<T>> &sPtr, T value, string type );
template <typename T>
bool Delete(node_wrap<ListNode<T>> &sPtr, T value );
template <typename T>
int isEmpty(node_wrap<ListNode<T>> sPtr );
template <typename T>
void printList(node_wrap<ListNode<T>> currentPtr );
template <typename T>
void Testfind(node_wrap<ListNode<T>> sPtr , T value);

int main(){
    string type;
    unsigned int choice; 

    while(!cin.eof()){
        cout<<"Enter Type Int, Double, String, Char"<<endl;
        cin>>type;
        if(cin.eof()) break;
        instructions(); 
        printf( "%s", "? " );
        cin>>choice;
        if(type.at(0) == 'S'){
            node_wrap<ListNode<string>> startPtr(nullptr);
            while(choice != 3){
                Choice<string>(startPtr, choice, type); //傳的是指向node的ptr
                printf( "%s", "? " );
                cin>>choice;
            }
        }
        if(type.at(0) == 'I'){
            node_wrap<ListNode<int>> startPtr(nullptr);
            while(choice != 3){
                Choice<int>(startPtr, choice, type); //傳的是指向node的ptr
                printf( "%s", "? " );
                cin>>choice;
            }
        }
        if(type.at(0) == 'D'){
            node_wrap<ListNode<double>> startPtr(nullptr);
            while(choice != 3){
                Choice<double>(startPtr, choice, type); //傳的是指向node的ptr
                printf( "%s", "? " );
                cin>>choice;
            }
        }
        if(type.at(0) == 'C'){
            node_wrap<ListNode<char>> startPtr(nullptr);
            while(choice != 3){
                Choice<char>(startPtr, choice, type); //傳的是指向node的ptr
                printf( "%s", "? " );
                cin>>choice;
            }
        }
        
    }

}

void instructions( void )
{
   puts( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" 
      "   4 to test find.");
} 

template <typename T>
void Choice(node_wrap<ListNode<T>> &startPtr, unsigned int choice, string type){
    T item;
    switch ( choice ) {
        case 1:
            cout<<"Enter "<<type<<" to be inserted: ";
            cin>>item;
            Insert<T>( startPtr, item , type); 
            printList( startPtr );
            break;
        case 2: 
            if ( !isEmpty( startPtr ) ) {
                cout<<"Enter "<<type<<" to be deleted: ";
                cin>>item;

                if ( Delete( startPtr, item ) ) {
                    cout<<item<<" deleted"<<endl;
                    printList( startPtr );
               } 
               else {
                   cout<<item<<" not found."<<endl<<endl;
               } 
            } 
            else {
               puts( "List is empty.\n" );
            } 

            break;
        case 4:
            cout<<"Enter "<<type<<" to find: ";
            cin>>item;
            auto ans = find(startPtr.begin(), startPtr.end(), item);
            if(ans->data != item) cout<<"Cannot find " << item <<endl;
            else cout<<"Find "<<item <<" at "<<ans<<endl;
            break;
    }
}

template <typename T>
void Insert(node_wrap<ListNode<T>> &sPtr, T value, string type ){
    ListNodePtr<T> newPtr; 
    node_wrap<ListNode<T>> previousPtr; 
    node_wrap<ListNode<T>> currentPtr; 

    if(type.at(0) != 'S')
        newPtr = (listNode<T>*)malloc( sizeof( listNode<T> ) ); // create node
    else{
        newPtr = new listNode<T>;
    }
    if ( newPtr != NULL ){
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = sPtr;
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }
        if ( previousPtr == NULL ) {//insert
            newPtr->nextPtr = sPtr.ptr;
            sPtr.ptr = newPtr;
        }else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr.ptr;
        } // end else
    }else {
        cout<<value<<" not inserted. No memory available."<<endl;
   }

}

template <typename T>
bool Delete(node_wrap<ListNode<T>> &sPtr, T value ){
    node_wrap<ListNode<T>> tempPtr; 
    node_wrap<ListNode<T>> previousPtr; 
    node_wrap<ListNode<T>> currentPtr; 
   if ( value == ( sPtr )->data ) {
      tempPtr = sPtr; // hold onto node being removed
      sPtr = ( sPtr )->nextPtr; // de-thread the node
      return true;
   }
   else {
      previousPtr = sPtr;
      currentPtr = ( sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while
      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         return true;
      } // end if
   } // end else

   return false;
}


template <typename T>
int isEmpty(node_wrap<ListNode<T>> sPtr ){
   return sPtr == NULL;
}

template <typename T>
void printList(node_wrap<ListNode<T>> currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr != NULL ) {
          cout<<currentPtr->data<<" -->";
         currentPtr = currentPtr->nextPtr;
      } // end while

      puts( "NULL\n" );
   } // end else
} 