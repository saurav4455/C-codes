#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp;
    fp=fopen("C:\\dsa\\duplicate\\input.txt", "w");
    int n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    int arr[n];
    int i;
    printf("Enter elements of the array\n");
    for(i=0;i<n;i++)
    {

        scanf("%d",&arr[i]);
         fprintf(fp,"%d\n",arr[i]);
    }
fclose(fp);
    //bubble sort
    int j,temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
FILE *fp1;
 fp=fopen("C:\\dsa\\duplicate\\input.txt", "r");
 fp1=fopen("C:\\dsa\\duplicate\\output.txt", "w");
    int dupli=1,num;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1])
        {
            dupli++;
            num=arr[i];
        }
    }
    printf("Number: %d repeated %d times in the array\n",num,dupli);
    fprintf(fp1,"Number: %d repeated %d times in the array\n",num,dupli);
    fclose(fp1);
fclose(fp);
    return 0;
}
