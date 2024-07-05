#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL;

struct node *createNewNode(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
};

void insertBeginning(int x)
{
 struct node *newnode=createNewNode(x);
 if(head==NULL){
        head=newnode;
    }else{
         newnode->next=head;
    head->prev =newnode;
    head=newnode;
    }

}
void insertLast(int x)
{
 struct node *newnode=createNewNode(x);
    //if the list is empty
    if(head==NULL){
        head=newnode;
    }else{
        struct node *t=head;
        while(t->next!=NULL){
            t=t->next;
        }
        //now t is the last node
        t->next=newnode;
        newnode->prev = t;
    }
}

void insertAt(int key,int pos)
{
    if(pos<0)
    {
        printf("invalid position\n");
        return;
    }
    else if(pos==0)
    {
        insertBeginning(key);
        return;
    }
    else
    {
        int idx=0;
        struct node *t=head;
        while(t!=NULL && idx< pos-1)
        {
            idx++;
            t=t->next;
        }
        // t is the node at pos-1
        if(t!=NULL)
        {
            struct node *newnode=createNewNode(key);
            newnode->next=t->next;
            t->next->prev=newnode;
            t->next=newnode;
            newnode->prev=t;
           // printf("newNode prev data:- %d\n ",newnode->prev->data);
        }
        else
        {
            printf("Position exceeds the length of the list. %d is not inserted.\n",key);
        }
    }

}
void deleteFirst()
{
    //check if list is empty
    if(head==NULL){
        printf("List is empty. Nothing to delete\n");
        return;
    }
    else if(head->next == NULL){
        head = NULL;
        return;
    }
    struct node *t=head;
    head=head->next;
    head->prev =NULL;
    //printf("head next = %d\n", head->next->data);
    //printf("head prev = %d\n", head->prev);
    free(t);
}

void deleteLast()
{
    //case -1: list is empty
    if(head==NULL){
        printf("List is empty\n");
    }else if(head->next==NULL){//case-2: only 1 node in the list
        struct node *t=head;
        head=NULL;
        free(t);
    }else{
        struct node *t=head;
        //find the 2nd last node
        while(t->next->next!=NULL){
            t=t->next;
        }
        //t is the 2nd last node. last node is t->next
        free(t->next);//delete last node
        t->next=NULL;//set the next of 2nd last node as NULL
        //printf("current value = %d\n", t->data);
        //printf("current-> next value = %d\n", t->next);
        //printf("current-> next->prev value = %d\n", t->prev);
    }
}
void deleteAt(int pos)
{
    if(pos<0)
    {
        printf("Invalid position.\n");
    }
    else if(pos==0)
    {
        deleteFirst();
    }
    else
    {
        int current_position=0;
        struct node *current=head;
        while(current!=NULL && current_position<pos-1)
        {
            current=current->next;
            current_position++;
        }
        //current is the node at pos-1
        if(current==NULL)
        {
            printf("Position exceeds the length of the list. Can't be deleted at position %d.\n",pos);

        }
        else
        {
            struct node *t=current->next;
            current->next=t->next;
            t->next ->prev = current;
           // printf("current value = %d\n", current->data);
           //printf("current-> next value = %d\n", current->next->data);
            //printf("current-> next->prev value = %d\n", current->next->prev->data);
            free(t);
        }
    }
}

int search(int element){
 //returns the first occurrence of element
    //if not present in the list, return -1
    int idx=0;
    struct node *t=head;
    while(t!=NULL){
        if(t->data == element){
            return idx;
        }else{
            idx++;
            t=t->next;
        }
    }
    return -1;
}

int findMax(){
  if(head == NULL) {
        return -1;
    }

    struct node *t = head;
    int max = t->data;

    while(t != NULL){
        if(t->data > max) {
            max = t->data;

        }
        t = t->next;
    }
    return max;
}

int findMin(){
    if(head == NULL) {
        return -1;
    }

    struct node *t = head;
    int min = t->data;

    while(t != NULL){
        if(t->data < min) {
            min =t->data;

        }
        t = t->next;
    }

    return min;
}
void displayList()
{
 printf("linked list:");
    struct node *t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main()
{
    int choice,key,pos;
    printf("1.insert first 2.insert last 3.insert at\n");
    printf("4.delete first 5.delete last 6.delete at "
           "7.search 8.find max 9.find min 10.exit\n");
    while(1){

        printf("enter choice:");
        scanf("%d",&choice);
        if(choice==1){
            //complete the code
            printf("enter element:");
            scanf("%d",&key);
            insertBeginning(key);
        }else if(choice==2){
            printf("enter element:");
            scanf("%d",&key);
            insertLast(key);

        }else if(choice==3){
            printf("enter position:");
            scanf("%d",&pos);
            printf("enter element:");
            scanf("%d",&key);
            insertAt(key,pos);

        }else if(choice==4){
             deleteFirst();

        }else if(choice==5){
            deleteLast();

        }else if(choice==6){
            printf("enter position:");
            scanf("%d",&pos);
            deleteAt(pos);
        }else if(choice==7){
             printf("enter element:");
            scanf("%d",&key);
            int idx=search(key);
            if(idx==-1){
                printf("%d is not in the list.\n",key);
            }else{
                printf("The key is found at:%d\n",idx);
            }

        }else if(choice==8){
           int max = findMax();

            if(max == -1) {
                printf("List is empty.\n");
            }
            else {
                printf("Max element: %d\n", max);
            }
        }else if(choice==9){
            int min = findMin();

            if(min == -1) {
                printf("List is empty.\n");
            }
            else {
                printf("Min element: %d\n", min);
            }
        }
        else if(choice==10){
            break;
        }else {
            break;
        }
        displayList();
    }
}



