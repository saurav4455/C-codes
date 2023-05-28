#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int temp;
struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue *node;
node enqueue(node head,int val);
node dequeue(node head);
int isempty(node head);
node isfull(node head);
node display(node head);

node enqueue(node head,int val)
{
    node ptr,cur=head;
   ptr=(node)malloc(sizeof(struct queue));
    ptr->data=val;
    ptr->next=NULL;
     if(head==NULL)
    {

        return ptr;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
            cur->next=ptr;

       return head;
    }
}
node dequeue(node head)
{
    node cur=head;
     if(head==NULL)
    {  printf("Queue is empty");
        return NULL;
    }
    else
    {
    head=head->next;
    printf("\nDeleted:%d",cur->data);
    temp=cur->data;
    free(cur);
    return head;
    }

}
node isfull(node head)
{
    if(head==NULL)
        return 0;
    else
        return head;
}
int isempty(node head)
{
    if(head->next==NULL)
        return 1;
    else
        return 0;
}
node display(node head)
{
    node cur=head;
if(head==NULL)
    {
    return NULL;
    }
    else
    {
          printf("\nDetails:\n");

    do
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }while(cur!=NULL);
     //printf("%d\t",cur->data);

    return head;
    }
}
void main()

{
    FILE *fp1,*fp2;
    node head=NULL;
    int i,n,num,k;
    for(;;)
    {
     printf("\nEnter choice:\n");
     scanf("%d",&n);
    switch(n)
    {
    case 1:
        scanf("%d",&num);
        head=enqueue(head,num);
        fp1=fopen("D:\\dsa_files\\queue.txt","a");
        head=display(head);
        fprintf(fp1,"%d ",num);
        fclose(fp1);
        break;

    case 2:
        head=dequeue(head);
        fp2=fopen("D:\\dsa_files\\dequeue.txt","a");
        fprintf(fp2,"%d ",temp);
        fclose(fp2);
        break;

    }
}
}
