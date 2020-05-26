
#include <iostream>
using namespace std;

struct Node{
    int data;
    struct  Node *next;
};

void push(struct Node *  &head,int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    head = temp;
}

void printlist(struct Node *& head){
    struct Node * temp = head;
    while(temp) {cout<<temp->data<<" "; temp = temp->next;}
}

void Sort(struct Node *& head){

    if(head == NULL || head->next == NULL) return;
    struct Node dummyZero,dummyOne,dummyTwo;
    dummyZero.next = dummyOne.next = dummyTwo.next = NULL;

    struct Node *zero = &dummyZero,*one = &dummyOne,*two = &dummyTwo;
    struct Node* temp = head;

    while(temp != NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next =  temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = (dummyOne.next)? dummyOne.next: dummyTwo.next;
    one->next = dummyTwo.next;
    two->next = NULL;

    head = dummyZero.next;
}
int main()

{
    int arr[] = { 1, 2, 0, 0, 1, 2, 1, 2, 1 };
    int size = (*(&arr + 1) - arr);
    struct Node * head = NULL;
    for (int i = 0; i < size ; ++i) push(head,arr[i]);
   // printlist(head);
    Sort(head);
    printlist(head);

    return 0;
}