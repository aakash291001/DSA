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
	printf("\nEnter the size of the array\n");
	cin>>q->size;
	q->f=q->r=0;
	q->Q = (int*)malloc(q->size*sizeof(int));
};
void enqueue(struct queue *q,int x)
{
	if((q->r+1)%q->size==q->f)
	printf("\n Queue is  full");
	else
	q->r=(q->r+1)%q->size;
	q->Q[q->r]=x;
}
void dequeue(struct queue *q)
{
	if(q->r==q->f)
	{
		printf("\nqueue is Empty\n");
	}
	else
	{
		
		q->f=(q->f+1)%q->size;
	}
}
void display(struct queue q)
{
	if(q.f==q.r)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i=q.f+1;
		do
		{
			printf("%d ",q.Q[i]);
			i=(i+1)%q.size;
		}while(i!=q.r+1);
	}
}
int main()
{
	struct queue q;
	create(&q);
	enqueue(&q,1);
	enqueue(&q,2);
	enqueue(&q,3);
	enqueue(&q,4);
	enqueue(&q,5);
	enqueue(&q,6);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	enqueue(&q,1);
	display(q);
	return 0;
}