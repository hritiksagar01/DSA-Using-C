#include<stdio.h>

struct Node {
     struct Node* next;
      int data;
};
 struct Node* addtofront(struct Node* head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if( head == NULL){
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;  
    } 
    return head;
}

struct Node* addtoend(struct Node* head , int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if( head == NULL){
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void display(struct Node* head){
     struct Node* temp = head;
      while (temp != NULL)
      {
        printf(temp->data,"\t");
        temp = temp->next;
      }
      
}
void main(){

    struct Node* head;

    while (1)
    {
    printf("Enter 1 to add to the front of the  list \n" );
    printf("Enter 2 to add to the end of the list \n ");
    printf("Enter 3 to add between the list \n");
    printf("Enter 4 to display the list \n");
    int ch;
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
    {
        printf("Enter a number to add to the front of the list");
        int input;
         scanf("%d", input);

    if (input  == 100) {
      break;
    }
    else
       head = addtofront(head ,(input));
    } 
        break;
    case 2: {
        int input;
        while(1){
                printf("Now enter the number which will be pushed the end of the list");
                scanf("%d", input);
                if (strcmp(input, "quit") == 0) {
                    break;
                    }
                    else
                     head = addtoend(head ,(input));
                      } 
                      }
                       break;

                       case 3: 
                       
              break;

                case 4: display(head);
                     default:
        break;
    }
 } 
}