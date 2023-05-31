#include<stdio.h>
#include<conio.h>

void main()
{
    int row,col,a[30][30];
    printf("Enter row and column of matrix:");
    scanf("%d %d",&row,&col);
    read(a,row,col);
    display(a,row,col);
    symmetric(a,row,col);
}
FILE *fp;
void read(int a[30][30],int row,int col)
{

   fp=fopen("read&update matrix.txt","w");
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            scanf("%d",&a[i][j]);
            fprintf(fp,"%d\t",a[i][j]);
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
}
void display(int a[30][30],int row,int col)
{
     FILE *fp;
       fp=fopen("read&update matrix.txt","r");

    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d\t",a[i][j]);
            fscanf(fp,"%d",&a[i][j]);
        }
        printf("\n");

    }
}
void symmetric(int a[30][30],int row,int col)
{
    int temp[30][30],count=0;
    for(int i=0; i<row; i++)
    {

        for(int j=0; j<col; j++)
        {
            temp[j][i]=a[i][j];
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(temp[i][j]!=a[i][j])
            {
                count++;
                break;
            }

        }
    }
    if(count==0)
        {printf("The given matrix is symmetric.\n");
        //
        fp=fopen("read&update matrix.txt","w");
        fprintf(fp,"Symmetric matrix\n");
        fclose(fp);
        return;

        }
    else
      {
        printf("The given matrix is not symmetric.\n");}
        fp=fopen("read&update matrix.txt","w");
        fprintf(fp,"The given matrix is not symmetric\n");
        fclose(fp);
        return;
}
