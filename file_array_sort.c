#include<stdio.h>
struct sort
{
    int num;
    struct sort *next;

};
typedef struct sort *node;
node read_last(node head);
void  display(node head);
node sort_array(node head);
node read_array();
node getnode();

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

node read_array()
{
    node temp;
    temp=getnode();
        scanf("%d",&temp->num);
    return temp;

}
void display(node head)
{
    node cur;
        if(head==NULL)
        {

            printf("List is empty");
            return;
        }
        cur=head;

        while(cur!=NULL)
        {

            printf("%d ",cur->num);
            cur=cur->next;
        }
printf("\n");
}

node read_last(node head)
{

    node cur,temp;
    temp=read_array();
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

int main()
{
    node head=NULL;
    int i,n;
     for(;;)
     {
         printf("\n1.Read data\n2.display list\n3.Sort list:\n");
           scanf("%d",&n);
     switch(n)
        {
      case 1: printf("Enter the data:\n");
              head=read_last(head);
              break;
     case 2: printf("Display:\n");
             display(head);
             break;
    case 3: printf("Sorted array:\n");
             sort(head);
             display(head);
             break;

        default:
        exit(0);
      }

   }
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
