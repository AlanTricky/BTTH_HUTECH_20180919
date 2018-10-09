#include<stdio.h>
#include<limits.h>
struct STACK{
	int top;
	unsigned capacity;
	int* array;
};

STACK* getStack(unsigned capacity){
	
	STACK* s = new STACK;
	s->capacity = capacity;
	s->top = -1;
	s->array = new int[capacity];
	return s;
}

void inputCapacity(int &cap){
	
	do{
		printf("Input Capacity: \n");
		scanf("%d",&cap);
		
		if(cap<0){
			printf("Input Wrong.Please check again! \n");
		}
	}while(cap<0);
}

int isEmpty(STACK* s){
	
	return (s->top == -1);
}

int isFull(STACK* s){
	
	return (s->top == s->capacity-1);
}

void push(STACK* s,int item){
	
	if(isFull(s))
		return;
	s->array[++s->top] = item;
	printf("%d pushed into stack\n",item);
}

int pop(STACK* s){
	
	if(isEmpty(s))
		return NULL;
	return s->array[s->top--];	
}

void inputStack(STACK* s,int cap){
	
	for(int i=0;i<cap;i++){
		
		int item;
		printf("Input element %d: \n",i+1);
		scanf("%d",&item);
		
		push(s,item);
	}
	printf("\n");
}

void outputStack(STACK* s,int cap){
	
	for(int i=cap-1;i>= 0;i--){
		printf("%d popped from stack \n",pop(s));
	}
	printf("\n");
}
int main(){
	int cap;
	inputCapacity(cap);
	
	STACK* s = getStack(cap);
	
	inputStack(s,cap);
	
	outputStack(s,cap);
	delete s;
	return 0;
}


