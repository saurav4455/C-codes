#include<stdio.h>
#include<stdlib.h>
struct sort
{
     int num;
     struct sort *next;
};
typedef struct sort *node;

node read_array();
node getnode();
node read_last(node head,int data);
void sort(node head);

int main()
{
  node head=NULL;

     int n,p,q,temp;
     printf("Enter size,ul and ll");
     scanf("%d %d %d",&n,&p,&q);
     q=q-p;



    FILE *fptr;
    fptr = fopen("file_random.txt","w");
    if(fptr == NULL)
   {
      printf("File Not created!");
      exit(1);
   }

     for(int i=0; i<n ;i++)
    {

        temp=(rand()%q);
        temp=temp+p;
        printf("%d\n",temp);
        fprintf(fptr,"%d ",temp);
    }
    fclose(fptr);
int data;

         fptr = fopen("file_random.txt","r");

         for(int i=0;i<n;i++)
         {
             fscanf(fptr,"%d",&data);
             head=read_last(head,data);
         }
         fclose(fptr);

         sort(head);

         FILE *fptrsort;

         fptrsort=fopen("filesort.txt","w");
         node cur;
        cur=head;
        printf("SORTED OUTPUT:\n");
    while(cur!=NULL)
    {
                 printf("%d\n",cur->num);

        fprintf(fptrsort,"%d\n",cur->num);
      //  printf("%d\n",ptr->age);
        cur=cur->next;
    }

    fclose(fptrsort);

}
node getnode()
{
	node temp;
	temp=(node)malloc(sizeof(struct sort));
	if(temp==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
temp->next = NULL;
	return temp;
}

node read_array(int data)
{
    node temp;
    temp=getnode();
        temp->num=data;
    return temp;

}
node read_last(node head,int data)
{

    node cur,temp;
    temp=read_array(data);
    temp->next=NULL;

    if(head==NULL)
    {
       return temp;
    }

    cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=temp;

    return head;
}
void sort(node head)
{
    node temp;
    node cur;
    cur =head;
    int t;

    while(cur!=NULL)
    {
        temp=cur->next;
        while(temp!=NULL)
        {
            if(cur->num>temp->num)
            {
                t=cur->num;
                cur->num=temp->num;
                temp->num=t;
            }
            temp=temp->next;
        }
        cur=cur->next;
    }
}

