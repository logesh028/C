#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insertval(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if(head==NULL){
        newNode->next=NULL;
        head = newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
void Display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void insertAtpos(int val,int pos){
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data=val;
        struct Node *temp = head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next=newNode;
        
}





int main()
{
    int choice=0,val,pos;
    while(choice!=4){
        printf("Enter your choice :");
        scanf("%d",&choice);
        printf("1.Insert at beginning\n");
        printf("2.Display Linked List\n");
        switch(choice){
            case 1:
                printf("Enter your data :");
                scanf("%d",&val);
                insertval(val);
                break;
            case 2:
                Display();
                break;
            case 3:
                printf("Enter the data And position : ");
                scanf("%d %d", &val, &pos);
                if (pos == 0) {
                    insertval(val);
                } else {
                    insertAtpos(val, pos);
                }
                break;

            case 4:
                exit(0);
            defult:
                printf("Invalid choice,please enter valid choice ");
        }

        
    }

    
}
