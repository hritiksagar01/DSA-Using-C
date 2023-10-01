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
        int ch;
        scanf_s("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            printf("Enter a number to add to the front of the list \n");
            int input;
            scanf_s("%d",&input);

            if (input == 100) {
                break;
            }
            else
                head = addtofront(head, (input));
        }
        break;
        case 2: {
            int input;
            while (1) {
                printf("Now enter the number which will be pushed the end of the list \n");
                scanf_s("%d",&input);
                if (input ==100) {
                    break;
                }
                else
                    head = addtoend(head, (input));
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
        default:
        break;
        }
    }
}