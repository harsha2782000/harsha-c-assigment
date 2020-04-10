#include<stdio.h>
#include<stdlib.h>
typedef struct NodePtr
{
int value;
struct NodePtr *lf;
struct NodePtr *rt;

}Node;

Node* createNode(int value)
{
Node *node=(Node*)malloc(sizeof(Node));
node->value=value;
node->lf = node->rt=NULL;
return node;
}

Node* insert(Node *root,int value)
{
if(root == NULL)
{
root=createNode(value);
}
else if(value < root->value)
{
root->lf=insert(root->lf,value);
}
else if(value > root->value)
{
root->rt=insert(root->rt,value);
}
return root;

}

Node* findMinNode(Node *root)
{
if(root->lf)
{
root=findMinNode(root->lf);
}
return root;
}

Node* delete(Node* root,int value)
{
if(root)
{
if(value>root->value)
{
root->rt=delete(root->rt,value);
}
else if(value<root->value)
{
root->lf=delete(root->lf,value);
}
else if(value == root->value)
{
if(root->lf && root->rt)
{
Node *minNode= findMinNode(root->rt);
root->value=minNode->value;
root->rt=delete(root->rt, minNode->value);
}
else
{
Node *nodeToDelete=root;
if(root->lf)
{
root=root->lf;
}
else
{
root=root->rt;
}
free(nodeToDelete);
}
}
}
return root;
}


void print(Node *root)
{
if(root)
{
printf("\n %d",root->value);
print(root->lf);
print(root->rt);
}
}

int main()
{
Node *root=NULL;
root=insert(root,23);
root=insert(root,25);
root=insert(root,24);
root=insert(root,27);
root=insert(root,39);
root=insert(root,66);
root=insert(root,54);
root=insert(root,22);

print(root);
printf("\n \n \n");

delete(root,23);
print(root);
return 0;
}
