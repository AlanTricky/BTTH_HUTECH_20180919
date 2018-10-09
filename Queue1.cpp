#include<stdio.h>
#include<limits.h>

struct QUEUE{
	
	int front,rear,size;
	unsigned capacity;
	int* array;
};

QUEUE* getQueue(unsigned cap){
	
	QUEUE* q = new QUEUE;
	q->capacity = cap;
	q->front = q->size = 0;
	q->rear = q->capacity-1;
	q->array = new int[cap];
	return q;
}

int isEmpty(QUEUE* q){
	
	return (q->size == 0);
}

int isFull(QUEUE* q){
	
	return (q->size == q->capacity);
}

void enQueue(QUEUE* q,int item){
	
	if(isFull(q))
		return;
	q->rear = (q->rear+1)%(q->capacity);
	q->array[q->rear] = item;
	q->size = q->size+1;
	printf("%d enqueue to Queue \n",item);
}

int deQueue(QUEUE* q){
	
	if(isEmpty(q))
		return INT_MIN;
		
	int item = q->array[q->front];
	q->size = q->size-1;
	q->array[q->front] = q->array[q->front+1]%(q->capacity);
	
	return item;
}

int front(QUEUE* q){
	
	if(isEmpty(q))
		return INT_MIN;
	return q->array[q->front];
}
int rear(QUEUE* q){
	if(isEmpty(q))
		return INT_MIN;
	return q->array[q->rear];
}
int main(){

		
	QUEUE* q = getQueue(100);
	enQueue(q,10);
	enQueue(q,20);
	enQueue(q,30);
	
	printf("%d dequeue from queue \n",deQueue(q));
	printf("Front item is %d \n",front(q));
	printf("Rear item is %d \n",rear(q));
	
	return 0;
}



