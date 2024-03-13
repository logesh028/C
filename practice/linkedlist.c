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
void insertatanyposition(int pos,int data){
    struct node *newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *temp = head;
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
     newnode->next=temp->next;
     temp->next=newnode;
}
void delete(int pos){
    struct node *temp=head;
    if(pos==0){
        head=head->next;
        return;
    }
    struct node *pre ;
    for(int i=0;i<pos;i++){
        pre = temp;
        temp=temp->next;
    }
    pre->next = temp->next;
    printf("\nLinkedList Element Deleted !!");
}
void deleteatend(){
    struct node *temp = head;
    struct node *pre;
    while (temp->next!=NULL)
    {
        pre = temp;
        temp=temp->next;
    }
    if(pre == NULL){
        head = NULL;
    }else{
    pre->next = NULL;
    }
 printf("\nLinkedList Element Deleted at end!!");
    
}
int main(){
    
    int choice=0,pos;
    int data;
    while(choice!=8){
        printf("\nEnter Your Choice");
        printf("\nEnter 1 to insert data at starting");
        printf("\nEnter 2 to display LinkedList");
        printf("\nEnter 3 to insert data at ending");
        printf("\nEnter 4 to count the LinkedList");
        printf("\nEnter 5 to insert data at any position");
        printf("\nEnter 6 to delete LinkedList Element at any position");
        printf("\nEnetr 7 to delete LinkedList Element at end position\n");
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
                break;
            case 5:
                printf("\nEnter your position :");
                scanf("%d",&pos);
                printf("Enter the data: ");
                scanf("%d",&data);
                if(head==NULL){
                    insertatbegining(data);
                }
                else{
                    insertatanyposition(pos,data);
                }
                break;
            case 6:
                printf("\nEnter your position :");
                scanf("%d",&pos);
                delete(pos);
                break;
            case 7:
                deleteatend();
                break;
            case 8:
                exit(0);
            default:
            printf("InValid Choice !!. Please Enter valid Choice ");
        }
    }
    
    
    return 0;
}