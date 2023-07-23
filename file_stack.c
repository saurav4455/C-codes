#include<stdlib.h>
#include<stdio.h>
#define size 10
void push(int data);
int pop();
int stack[size],top=-1;
int main()
{
    int n,p,q,temp,op[10];
    scanf("%d%d%d",&n,&p,&q);
    q=q-p;
    FILE *fptr,*fstack;
    fptr = fopen("D:\\dsa_files\\file_random.txt","w");
    if(fptr == NULL)
    {
        printf("File Not created!");
        exit(1);
    }
    int a[100],data;
    for(int i=0; i<n ; i++)
    {
        temp=(rand()%q);
        temp=temp+p;
        printf("%d\n",temp);
        fprintf(fptr,"%d ",temp);
        a[i]=temp;
    }
    fclose(fptr);

    fptr = fopen("D:\\dsa_files\\file_random.txt","r");
    fstack=fopen("D:\\dsa_files\\stack.txt","w");

    for(int i=0; i<n; i++)
    {
        fscanf(fptr,"%d",&a[i]);
    }
    for(int i=0; i<n; i++)
        fprintf(fstack,"%d ",a[i]);
    fclose(fstack);
    fclose(fptr);

    FILE *fpush,*fpop;
    int s;
    printf("Enter the number of data to be popped out from stack?");
    scanf("%d",&s);
    fstack=fopen("D:\\dsa_files\\stack.txt","a");
    fpop=fopen("D:\\dsa_files\\pop.txt","a");

    for(int i=0; i<s; i++)
    {
        fscanf(fstack,"%d",&a[i]);
        data=pop();
        printf("%d",data);
    }
  fclose(fpop);
  fclose(fstack);

}
void push(int value)
{
    if(top==size-1)
    {
        printf("Stack is full.");

    }

    else
    {
        top++;
        stack[top]=value;
        printf("Insertion success %d:||",value);
    }

}

int pop()
{
    if(top==-1)
    {
        return 0;
    }
    else
        return top--;

}
int peak()
{
 int value;
  if(top==-1)
  {
      return 0;
  }
  else
    value=stack[top];
  return value;

}
