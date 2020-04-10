#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int ele;
    struct stack *next;
};


struct stack *createstack () 
{
    return NULL;
}

int emptystack(struct stack *top) 
{
    return (top == NULL);
}

void Push(struct stack **top, int ele) 
{
    struct stack *newnode = (struct stack*) malloc(sizeof(struct stack));
    if(!newnode)
        return;
    newnode->ele = ele;
    newnode->next = *top;
    *top = newnode;
}

int Pop(struct stack **top) 
{
    struct stack *temp;
    int ele;

    if(emptystack(*top)) 
	{
        printf("Empty Stack\n");
        return INT_MIN;
    }

    temp = *top;
    ele = (*top)->ele;
    *top = (*top)->next;
    free(temp);
    return ele;
}

struct queue 
{
    struct stack *stack1;
    struct stack *stack2;
};

struct queue *createqueue() 
{
    struct  queue  *newnode = (struct queue *) malloc(sizeof(struct  queue ));
    return newnode;
}

void insertqueue(struct queue *q, int ele)
{
    Push(&q->stack1, ele);
}

int releasequeue(struct queue *q) 
{
    if(!emptystack(q->stack2)) 
	{
        return Pop(&q->stack2);
    }
    else 
	{
        while(!emptystack(q->stack1)) 
		{
            Push(&q->stack2, Pop(&q->stack1));
        }
        return Pop(&q->stack2);
    }
}

int main() 
{
    struct queue *q = createqueue();
    q->stack1 = q->stack2 = NULL;
    insertqueue(q, 7);
    insertqueue(q, 18);
    insertqueue(q, 45);
   
    printf("%d ", releasequeue(q));
    printf("%d ", releasequeue(q));
    printf("%d ", releasequeue(q));

    return 0;
}
