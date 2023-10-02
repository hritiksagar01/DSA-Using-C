#include<stdio.h>
#include <malloc.h>
#include<stdlib.h>

 struct Node {
    struct Node* next;
    int data;
};
typedef struct Node Node;

 Node* addtofront(struct Node* head, int data) {
    Node* newNode = malloc(sizeof( Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {

        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

 Node* addtoend(struct Node* head, int data) {
     Node* newNode =malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void display(Node* head) {
     Node* temp = head;
    while (temp != NULL)
    {
        printf("%d, ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 Node* addbetweenf( Node* head , int data , int position){
     Node* newNode = malloc(sizeof( Node));
    newNode->next = NULL;
    newNode->data = data;
    int count =1;
     Node* temp = head ;
     Node* prev = NULL;
    while (temp->next != NULL && count != position)
    {
        if(count == position)
        break;

        prev = temp;
        temp = temp->next;
        
        
        count++;
        
    }
    newNode->next = temp;
    prev->next = newNode;
    return head;
}
 Node* deletefromfront( Node* head){
    if( head == NULL){
        return NULL;
    }
    head = head->next;
}
 Node* deletefromend( Node* head ){
    if( head->next == NULL){
        printf("list empty");
        return NULL;
    }
     Node* temp = head;
     Node* prev = NULL;
    while (temp->next != NULL)
    {
        prev =temp;
        temp = temp->next;
    }
    prev->next = NULL;
    return head;
    
}
Node* deleteBetween(Node* head , int position){
    Node* temp = head;
    Node* prev  = NULL;
    int count =1;
    if(position == 1)
    head = head->next;

    while (temp->next !=NULL && count != position)
    {   prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    return head;
    
}
Node* reverse( Node* head){
    Node* curr  =head;
    Node* prev  =NULL;
    Node* next ;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr ;
        curr = next;
    }
    display(prev);
    return prev;
    
}

void main() {
     Node* head=NULL;
    while (1)
    {
        printf("Enter 1 to add to the front of the  list \n");
        printf("Enter 2 to add to the end of the list \n ");
        printf("Enter 3 to add between the list \n");
        printf("Enter 4 to display the list \n");
        printf("Enter 5 to delete the element from the front \n ");
        printf("Enter 6 to delete the element from the end \n ");
        printf("Enter 7 to delete the element from a certain postion \n");
        printf("enter 8 to reverse the linkedlist \n ");
        int ch;
        scanf_s("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("Enter a number to add to the front of the list \n");
            char input[100];
            scanf_s("%s",&input);

            if (input == "quit") {
                break;
            }
            else{
                int y = atoi(input);
                head = addtofront(head,(y));
            }
                
        }
        break;
        case 2: {
            char input[100];
            while (1) {
                printf("Now enter the number which will be pushed the end of the list \n");
                scanf_s("%s",&input);
                if (strcmp(input , "quit") == 0) {
                    break;
                }
                else
                {
                    int y = atoi(input);
                    head = addtoend(head,(y));
                    }

            }
        }
              break;

        case 3:{
            int data,position;
            printf("enter the value to inserted");
            scanf("%d",&data);
            printf("enter the position where the value needs to be inserted");
            scanf("%d",&position);
           head =  addbetweenf(head ,data, position);
        } 
            break;
        case 4: display(head);

        break;

        case 5 : head = deletefromfront(head);

        break;
        case 6 : head = deletefromend(head);
        break;

        case 7 :{
            int  position;
            printf("Enter the position where you want to delete the element");
            scanf("%d",&position);
            head = deleteBetween(head,position);
    
        }
        break;
        case 8 : head = reverse(head);
        break;
        default:
        break;
        }
    }
}