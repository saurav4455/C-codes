#include<stdlib.h>
#include<stdio.h>
int main()
{
    int n,p,q,temp;
    scanf("%d%d%d",&n,&p,&q);
    q=q-p;
    FILE *fptr;
    fptr = fopen("D:\\dsa_files\\file_random.txt","w");
    if(fptr == NULL)
   {
      printf("File Not created!");
      exit(1);
   }
int a[n];
     for(int i=0; i<n ;i++)
    {
        temp=(rand()%q);
        temp=temp+p;
        printf("%d\n",temp);
        a[n]=temp;
        printf("a:%d\n",a[n]);
        fscanf(fptr,"%d",&a[n]);
        fprintf(fptr,"%d ",a[n]);
    }
    fclose(fptr);



}
