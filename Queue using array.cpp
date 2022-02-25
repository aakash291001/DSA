#include<iostream>
using namespace std;
struct queue
{
	int size;
	int f;
	int r;
	int *Q;
};
void create(struct queue *q)
{
	printf("Enter the size\n");
	scanf("%d",&q->size);
	q->f=q->r=-1;
	q->Q=(int *)malloc(q->size*sizeof(int));
}
void enqueue(struct queue *q,int x)
{
	if(q->r==q->size-1)
	{
		printf("Queue is Full\n");
	}
	else
	{
		q->r++;
		q->Q[q->r]=x;
	}
}
int dequeue(struct queue *q)
{
	int x=-1;
	if(q->f==q->r)
	{
		printf("Queue is empty\n");
	}
	else
	{
		q->f++;
		x=q->Q[q->f];
	}
	return x;
}
void display(struct queue q)
{
	if(q.f==q.r)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		for(i=q.f+1;i<=q.r;i++)
		{
			printf("%d ",q.Q[i]);
		}
	}
}
int main()
{
	struct queue q;
	create(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
//	dequeue(&q);
	display(q);
	return 0;
}