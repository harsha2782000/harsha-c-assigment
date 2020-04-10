#include<stdio.h>

char s[10];
int top=-1;
void push(char);
void pop();
void push(char x)
{
	s[++top]=x;
}
void pop()
{
	printf("%c",s[top--]);
}
void main()
{
	char string[10];
	printf("\n enter name:");
	scanf("%s",&string);	
	int i=0;
	while (string[i]!='\0')
	{
		push(string[i]);
		i++;
	}	
	printf("\n");
	while(top!=-1)
	{
		pop();
	}
}
