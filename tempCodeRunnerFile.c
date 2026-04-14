#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
     struct node *prev;
    struct node *next;
 }*first=NULL,*last=NULL,*temp=NULL;

  void create(){
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
  }


  void insert_beg(){
    if(first==NULL){
        create();
        first=last=temp;
    }
    else{
         create();
         first->prev=temp;
         temp->next=first;
         first=temp;
    }
  }


  void insert_end(){
     if(first==NULL){
        create();
        first=last=temp;
    }
    else{
      create();
         last->next=temp;
         temp->prev=last;
         last=temp;
    }
  }


 int delete_beg(){
    struct node *temp;
    temp=first;
    if(temp==NULL){
        printf("Empty\n");
        return 0 ;
    }
    if(temp->next==NULL){
        printf("The deleted item is:%d\n",temp->data);
        free(temp);
        first=last=NULL;
    }
    else{
        first=temp->next;
        printf("The deleted item is:%d\n",temp->data);
        free(temp);
        first->prev=NULL;
    }
 }


 int delete_end()
 {
    struct node *temp;
    temp=first;
    if(temp==NULL){
        printf("Empty\n");
        return 0 ;
    }
    if(temp->next==NULL){
        printf("The deleted item is:%d\n",temp->data);
        free(temp);
        first=last=NULL;
    }
    else{
         printf("Deleted element is :%d\n",last->data);
        temp=last;
        last=temp->prev;
        last->next=NULL;
        
        free(temp);
    }
 }


  int display(){
    struct node *temp;
    temp=first;
    if(temp==NULL){
        printf("Empty");
        return 0 ;
    }
    if(temp->next==NULL){
        printf("The elements item is:%d\n",temp->data);
    
    }
    else{
        printf("The element are: ");
        while((temp->next)!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",last->data);
       
    }
 }

void main(){
    int ch;
    while(1){

    printf("1.insert_beg()\n2.insert_end()\n3.delete_beg()\n4.delete_end()\n5.display()\n6.exit()\n");
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    switch(ch){
        case 1: insert_beg();
                break;
        case 2: insert_end();
                break;
        case 3: delete_beg();
                break;
        case 4: delete_end();
                break;
        case 5:display();
               break;
        case 6:exit(0);
        default:printf("invalid\n");
            break;
        
    }
    }
 }