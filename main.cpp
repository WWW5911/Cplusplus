#include <iostream>
#include <stdlib.h>
//我要有 單向鏈結串列、插入、刪除、反轉、複製、合併
using namespace std;

typedef struct node* pointer;

typedef struct node{
    int data;
    pointer next;
} Node;
void intital(pointer head, pointer tail){
    head->next = NULL;
    head->data = 7777777;
    tail->next = NULL;
    tail->data = 1111111;
}
void insert(int data, int node, pointer head, pointer tail){
    pointer temp = (pointer)malloc(sizeof(Node));
    pointer ptr = head;
    temp->data = data;
    temp->next = NULL;
    while(ptr->next && node-- > 0)//定位
        ptr = ptr->next;
    if(ptr->next)
        temp->next = ptr->next;
    ptr->next = temp;
    if(temp->next == NULL)
        tail->next = temp;
}
void Delete(int node, pointer head, pointer tail){
    pointer cur = head, pre = NULL;
    while(node-- > 0 && cur->next){
        pre = cur;
        cur = cur->next;
    }
    if(pre)
        pre->next = cur->next;
    else head->next = cur;
    free(cur);
    if(!pre->next)
        tail->next = pre;
}
bool Move_n_right(int n, pointer L, pointer R){
	pointer temp;
	while(n > 0 && R !=NULL){
		temp = L;
		L->next->next = R->next;
		R->next = R->next->next;
		L->next ->next ->next  = temp;
		n--;
	}
	return true;
}

int main(){
    pointer head = (pointer)malloc(sizeof(Node));
    pointer tail = (pointer)malloc(sizeof(Node));
    intital(head, tail);
	pointer RR = (pointer)malloc(sizeof(Node));
    pointer RT = (pointer)malloc(sizeof(Node));
	intital(RR, RT);
    insert(20, 0, head, tail);
    insert(21, 5, head, tail);
    insert(22, 7, head, tail);
    insert(23, 2, head, tail);
    insert(100, 0, RR, RT);
	insert(101, 1, RR, RT);
	insert(102, 2, RR, RT);
	insert(103, 3, RR, RT);
	Move_n_right(2, tail, RR);
	return 0;
}