#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
struct node *tail  = NULL;

void insertatbegining(int val){
    struct node *newnode =  (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next=head;
    if(head == NULL){
        tail = newnode;
    }
    else{
        head->prev=newnode;
    }
    head = newnode;
    newnode->prev=NULL;
    printf("%d Element was inserted in Double Linked List ", val);
}
void display(){
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        
    }
    free(temp);
}
void displayrev(){
    struct node *temp=tail;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->prev;
        
    }
    free(temp);
}
void insertatpos(int val, int pos) {
    if (pos == 0) {
        insertatbegining(val);
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    struct node *temp = head;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode); // Free allocated memory before returning
        return;
    }
    newnode->data = val;
    newnode->next = temp->next;
    if (temp->next == NULL) {
        tail = newnode;
    } else {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
    printf("%d Element is inserted at position %d\n", val, pos);
}
void deleteatpos(int pos){
    if(pos == 0){
        head=head->next;
        head->prev= NULL;
    }
    struct node *temp=head;
    struct node *prev = NULL;
    for(int i=0;i<pos;i++){
        prev = temp;
        temp=temp->next;
    }
    prev->next = temp->next;
    if(temp->next==NULL){
        tail=prev;
    }else{
        temp->next->prev = prev;
    }

    printf("\nDouble LinkedList Element Deleted !!");
}

int main(){
   int choice=0,pos;
    int val;
    while(choice!=6){
        printf("\n-----------------Double Linked List Menu----------------");
        printf("\nEnter Your Choice");
        printf("\nEnter 1 to insert data at starting");
        printf("\nEnter 2 to Display Double LinkedList");
        printf("\nEnter 3 to Display reverse Double LinkedList");
        printf("\nEnter 4 to insert data at position");
        printf("\nEnter 5 to delete Double LinkedList Element at any position");
        // printf("\nEnter 4 to count the LinkedList");
        // printf("\nEnter 5 to insert data at any position");
        // printf("\nEnetr 7 to delete LinkedList Element at end position\n");
        printf("\n---------------------------------------------------------\n");
        scanf("%d",&choice);        
        switch(choice){
            case 1:
                printf("Enter your data to  insert at starting : ");
                scanf("%d",&val);
                insertatbegining(val);
                break;
            case 2:
                display();
                break;
            case 3:
                displayrev();
                break;
            case 4:
                printf("Enter your data to  insert at position : ");
                scanf("%d",&val);
                printf("\nEnter position :");
                scanf("%d",&pos);
                insertatpos(val,pos);
                break;
            case 5:
                printf("\nEnter position to Delete Element from Double LinkedList ");
                scanf("%d",&pos);
                deleteatpos(pos);
                break;
            case 6:
                exit(0);
            default:
            printf("InValid Choice !!. Please Enter valid Choice ");
        }
    }
    
    
    return 0;
}