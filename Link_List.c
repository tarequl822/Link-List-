#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node * prev;

} * head =NULL ;
// create a node after memory assign
struct node *createNewNode(int x)
{
struct node* newnode = (struct node *)malloc(sizeof(struct node));
newnode -> data =x;
newnode -> next =NULL;
return newnode;
};

void insertBeginning(int key)
{
struct node* newnode = createNewNode(key); // create NULL new node then value set
newnode -> next = head;
head ->prev = NULL;
head = newnode;
}
void insertLast(int key)
{
struct node* newnode = createNewNode(key);// create new node

if(head == NULL){
    head= newnode;
}else{
    struct node * t=head;
    while(t->next != NULL){
        t=t->next;
    }
    // new t is the last node
    t-> next = newnode;
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
        int current_position=0;//  idx
        struct node *current=head; // t
        while(current  !=  NULL  &&  current_position  < pos-1)
        {
            current = current  -> next;
            current_position ++;
        }
        // t is the node at   pos -1;
        if(current!=NULL)
        {
            struct node *newnode=createNewNode(key);
            newnode->next=current->next;
            current->next=newnode;
        }
        else
        {
            printf("Position exceeds the length of the list. %d is not inserted.\n",key);
        }
    }

}
void deleteFirst()
{
   if(head == NULL){
        printf("list is null \n");
        return;
    }else{
        struct node *t = head;
        head = head-> next;
        free(t); // free memory space
    }
}

void deleteLast()
{
     if(head == NULL){
        printf("list is null \n");
        return;
    }
    else if(head -> next == NULL){
            // only one data have on list
        struct node *t = head;
        head = NULL;
        free(t);
        }else{
             struct node *t = head;
              while( t -> next ->next != NULL){
                   t = t-> next;
               }
            free(t -> next); // free memory space
            t -> next =NULL;
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
        if(current==NULL)
        {
            printf("Position exceeds the length of the list. Can't be deleted at position %d.\n",pos);
        }
        else
        {
            struct node *t=current->next;
            current->next=current->next->next;
            free(t);
        }
    }
}

int search(int x){
    int  ind =0;
    struct node *t =head;
    while(t!=NULL){
        if(t -> data == x){
            return ind;
          }else{
              ind++;
              t = t-> next;
          }

    }
    printf("!!! value is not found !!!! \n");
    return -1;
}
void printList()
{
  printf("printList:  ");
  struct node* t= head;
  while(t != NULL){
    printf("%d ", t-> data);
    t = t-> next;
  }
  printf("\n");
}

int main()
{
    int choice,key,pos;
    printf("1.insert first 2.insert last 3.insert at\n");
    printf("4.delete first 5.delete last 6.delete at 7.search 8.exit\n");
    while(1){

        printf("enter choice:");
        scanf("%d",&choice);
        if(choice==1){
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
        }else{
            break;
        }
        printList();
    }
}
