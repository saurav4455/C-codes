#include<stdio.h>
#include<stdlib.h>


void main()
{

 int n;
 FILE *fp;
 printf("Enter the size of array:\t");
 scanf("%d",&n);

 input_from_file(fp,n);
 output_file(fp,n);
sort(fp,n);
output_file(fp,n);
}

void input_from_file(FILE *fp,int n)
{
  int i,a[10];
  fp=fopen("input.txt","w");
  printf("Enter the array:");
  for(i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
      fprintf(fp,"%d",a[i]);
  }
 fclose(fp);
}

void output_file(FILE *fp,int n)
{
    int i,a[10];
    fp=fopen("output.txt","r");

        for(i=0;i<n;i++)
        {
        fscanf(fp,"%d ",&a[i]);
        printf("%d ",a[i]);
        }
    fclose(fp);
}

void sort(FILE *fp,int n)
{
    int i,a[10],j,t;
    fp=fopen("output.txt","r");

        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            }
        }


    fclose(fp);

}
