#include<stdio.h>
#define SIZE 50

char stack[SIZE];
int top=-1;

void push(char ele)
{
	if(top>=SIZE-1)
	printf("\n stack oerflow,push not possible \n");
	else
	{
		top++;
		stack[top]=ele;
	}
}
char pop()
{
	char ele;
	ele=stack[top];
	top--;
	return(ele);
}
int is_operator(char sym)
{
	if(sym=='^'||sym=='*'||sym=='/'||sym=='+'||sym=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int precedence(char sym)
{
	if(sym=='^')
	{
		return 3;
	}
	else if(sym=='*'|| sym=='/')
	{
		return 2;
	}
	else if(sym=='+'||sym=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	
}
int main()
{
	char infix[SIZE],postfix[SIZE],ele,temp;
	int i=0,j=0;
	printf("\n enter the arthimatic form in infix notation:");
	gets(infix);
	while(infix[i]!='\0')
	{
		ele=infix[i];
		if(ele=='(')
		{
			push(ele);
		}
		else if(ele>='A' && ele<='Z' || ele>='a' && ele<='z')
		{
			postfix[j]=ele;
			j++;
		}
		else if(is_operator(ele)==1)
		{
			temp=pop();
			while(is_operator(temp)==1 && precedence(temp)>=precedence(ele))
			{
				postfix[j]=temp;
				j++;
				temp=pop();
				
			}
			push(temp);
			push(ele);
		}
		else if(ele==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j]=temp;
				j++;
				temp=pop();
				
			}
		}
		else
		{
			printf("\n invalid arthimatic expression\n");
			getch();
		    exit(0);		
		}
		i++;
	}
	while(top>-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
	puts(postfix);
	
	getch();
	return 0;
}
