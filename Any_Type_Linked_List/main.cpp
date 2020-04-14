#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct listNode {
    T data;
    struct listNode *nextPtr;
    bool operator==(const T& a) const{
        return (data == a);
    }
    listNode &operator++(){
        *this = *((*this).nextPtr);
        return *this;
    }
    listNode operator++(int){
        *this = *((*this).nextPtr);
        return *this;
    }
};




// prototypes
template <typename T>
void Insert_( listNode<T>* *sPtr, T value , string type);
template <typename T>
void Choice(listNode<T>* *startPtr, unsigned int choice, string type);
template <typename T>
bool LLDelete( listNode<T>* *sPtr, T value );
template <typename T>
int isEmpty( listNode<T>* sPtr );
template <typename T>
void printList( listNode<T>* currentPtr );
template <typename T>
void Testfind( listNode<T>* sPtr , T value);

void instructions( void );

int main( void )
{
    string type;
    unsigned int choice; 
    char item; 
    while(!cin.eof()){
    cout<<"Enter Type Int, Double, String, Char"<<endl;
    cin>>type;
    if(cin.eof()) break;
    instructions(); 
    printf( "%s", "? " );
    scanf( "%u", &choice );
    if(type.at(0) == 'S'){
        listNode<string> * startPtr = NULL;
        while(choice != 3){
            Choice(&startPtr, choice, type);
            printf( "%s", "? " );
            scanf( "%u", &choice );
        }
    }
    if(type.at(0) == 'I'){
        listNode<int> * startPtr = NULL;
        while(choice != 3){
            Choice(&startPtr, choice, type);
            printf( "%s", "? " );
            scanf( "%u", &choice );
        }
    }
    if(type.at(0) == 'D'){
        listNode<double> * startPtr = NULL;
        while(choice != 3){
            Choice(&startPtr, choice, type);
            printf( "%s", "? " );
            scanf( "%u", &choice );
        }
    }
    if(type.at(0) == 'C'){
        listNode<char> * startPtr = NULL;
        while(choice != 3){
            Choice(&startPtr, choice, type);
            printf( "%s", "? " );
            scanf( "%u", &choice );
        }
    }

    puts( "End of run." );
    }
} // end main

template <typename T>
void Choice(listNode<T>* *startPtr, unsigned int choice, string type){
        T item;
    switch ( choice ) {
        case 1:
            cout<<"Enter "<<type<<" to be inserted: ";
            cin>>item;
            Insert_( startPtr, item , type); 
            printList( *startPtr );
            break;
        case 2: 
            if ( !isEmpty( *startPtr ) ) {
                cout<<"Enter "<<type<<" to be deleted: ";
                cin>>item;

                if ( LLDelete( startPtr, item ) ) {
                    cout<<item<<" deleted"<<endl;
                    printList( *startPtr );
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
            cin>>item;
            Testfind(*startPtr, item);
            break;
            
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
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
void Testfind( listNode<T>* sPtr, T value ){
    listNode<T>* currentPtr = sPtr;
   // ++*currentPtr;
    while ( currentPtr->nextPtr != NULL ) {
        currentPtr = currentPtr->nextPtr;
    }
    listNode<T>* ans = find(sPtr, currentPtr, value);
    if(ans->data != value) cout<<"Cannot find " << value <<endl;
    else cout<<"find "<<value << " at "<<ans <<endl;
}

template <typename T>
void Insert_( listNode<T>* *sPtr, T value , string type)
{
    listNode<T>* newPtr; // pointer to new node
    listNode<T>* previousPtr; // pointer to previous node in list
    listNode<T>* currentPtr; // pointer to current node in list

    if(type.at(0) != 'S')
        newPtr = (listNode<T>*)malloc( sizeof( listNode<T> ) ); // create node
    else{
        newPtr = new listNode<T>;
    }
    if ( newPtr != NULL ) { // is space available
        newPtr->data = value; // place value in node
        newPtr->nextPtr = NULL; // node does not link to another node

        previousPtr = NULL;
        currentPtr = *sPtr;

        // loop to find the correct location in the list
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        } // end while

        // insert new node at beginning of list
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } // end if
        else { // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } // end else
    } // end if
    else {
        cout<<value <<" not inserted. No memory available."<<endl;
    } // end else
} // end function insert

// delete a list element
template <typename T>
bool LLDelete( listNode<T>* *sPtr, T value )
{
   listNode<T>* previousPtr; // pointer to previous node in list
   listNode<T>* currentPtr; // pointer to current node in list
   listNode<T>* tempPtr; // temporary node pointer

   // delete first node
   if ( value == ( *sPtr )->data ) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      free( tempPtr ); // free the de-threaded node
      return true;
   } // end if
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->data != value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return true;
      } // end if
   } // end else

   return false;
} // end function delete

// return 1 if the list is empty, 0 otherwise
template <typename T>
int isEmpty( listNode<T>* sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
template <typename T>
void printList( listNode<T>* currentPtr )
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
} // end function printList


