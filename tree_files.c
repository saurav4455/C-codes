#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
}*node;

node create(int num);
void insert(node,node );
void preorder(node );
void postorder(node );
void inorder(node );


int main()
{
    int num;
    char ch;
    int item,f=0;
    node root=NULL,temp;
    int n,p,q,temp;
    printf("Enter size,lower limit,upperlimit ");
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
    for(int i=0; i<n ; i++)
    {
        temp=(rand()%q);
        temp=temp+p;
        printf("%d\n",temp);

        a[n]=temp;
        //  printf("a:%d\n",a[n]);
        fscanf(fptr,"%d",&a[n]);
        fprintf(fptr,"%d ",a[n]);
        create(a[n]);
    }
    fclose(fptr);
    return 0;
}


node create(int num)
{
    node temp;
    printf("nEnter data:");
    temp=(node)malloc(sizeof( struct BST));
    temp->data=num;
    temp->left=temp->right=NULL;
    return temp;
}

void insert(node root,node temp)
{
    if(temp->data<root->data)
    {
        if(root->left!=NULL)
            insert(root->left,temp);
        else
            root->left=temp;
    }

    if(temp->data>root->data)
    {
        if(root->right!=NULL)
            insert(root->right,temp);
        else
            root->right=temp;
    }
}

void preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(node root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);

    }
}
