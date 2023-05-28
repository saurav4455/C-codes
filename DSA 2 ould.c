#include<stdio.h>
#include<string.h>

void input(char str[5][200]);
void display(char str[5][200]);
int length(char str1[100]);
void main()
{
   char str[5][200];
   int i;
   printf("Input:\n") ;
   input(str);
   printf("display:\n");
   display(str);

}
int length(char str1[100])
{
    int i,count=0;
    for(i=0;str1[i]!='\0';i++)
        count++;
    return count;
}
void input(char str[10][200])
{
    int i;
    for(i=0;i<4;i++)
    {
       //fgets(str[i], 200, stdin);
       gets(str[i]);
    }
}
void display(char str[10][200])

{

    int i,j,c=0,m;
    char *ptr[110];
    for(i=0;i<4;i++)
        printf("%s\n", str[i]);
    char str2[10]="ould";
    for(int j=0;j<4;j++)
    {

      ptr[j]=strstr(str[j],str2);
      if(ptr[j])
      {
      printf("%s",str[j]);
    }

}}

/*Ah dear could you and i with fate conspure
to grasp this orry scheme of things entire
would not we shatter it to bits --and then
re mould it nearer to the hearts desire*/
