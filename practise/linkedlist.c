#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;  

void insertatbegining(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    printf("Your data inserted at starting succesfully in LinkedList!! ");
}
void insertatending(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    newnode->data=data;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    printf("Your data inserted at ending succesfully in LinkedList!! ");

}

void display(){
        struct node *temp;
        temp=head;
        printf("LinkedList datas :\n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
}

void sizeofLList(){
    struct node *temp;
    temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    printf("Count of the Linked List :%d",count);
}

int main(){
    
    int choice=0;
    int data;
    while(choice!=5){
        printf("\nEnter Your Choice");
        printf("\nEnter 1 to insert data at starting");
        printf("\nEnter 2 to display LinkedList");
        printf("\nEnter 3 to insert data at ending");
        printf("\nEnter 4 to count the LinkedList\n");
        scanf("%d",&choice);
        
        
        
        switch(choice){
            case 1:
                printf("Enter your data insert at starting : ");
                scanf("%d",&data);
                insertatbegining(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("\nEnter your data insert at ending : ");
                scanf("%d",&data);
                if(head==NULL){
                    insertatbegining(data);
                }else{
                    insertatending(data);   
                }
                break;
            case 4:
                sizeofLList();
            case 5:
                exit(0);
        }
    }
    
    
    return 0;
}