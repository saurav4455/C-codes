#include<stdlib.h>
#include<stdio.h>
#define size 10
void push(int data);
int pop();
int stack[size],top=0;
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
        //printf("%d\n",temp);
        fprintf(fptr,"%d ",temp);
        a[i]=temp;
    }
    fclose(fptr);

    fptr = fopen("D:\\dsa_files\\file_random.txt","r");
    fstack=fopen("D:\\dsa_files\\stack.txt","w");

    int number;
    for(int i=0; i<n; i++)
    {
        fscanf(fptr,"%d",&number);
        push(number);
    }
    for(int i=0; i<n; i++)
        fprintf(fstack,"%d ",a[i]);
    fclose(fstack);
    fclose(fptr);




    FILE *fpush,*fpop;
    int choice,num;
    for(;;)
    {
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:num=pop();
               fpush=fopen("D:\\dsa_files\\push.txt","a");
               fprintf(fpush,"%d\n",num);
               printf("%d ",num);
               fclose(fpush);
               break;
            case 2:num=pop();
               fpop=fopen("D:\\dsa_files\\pop.txt","a");
               fprintf(fpop,"%d\n",num);
            printf("%d ",num);

               fclose(fpop);

               break;

       }
    }


}
void push(int value)
{
    if(top==size-1)
    {
        printf("Stack is full.");

    }

    else
    {
        stack[top]=value;
        top++;
        printf("Insertion success: %d ",value);
        printf("\n");
    }

}

int pop()
{
    if(top==0)
    {
        return 0;
    }
    else
    {
        int data;
        top--;
        data=stack[top];
        return data;
    }

}
int peak()
{
 int value;
  if(top==0)
  {
      return 0;
  }
  else
    value=stack[top];
  return value;

}
