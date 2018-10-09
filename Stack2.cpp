#include<stdio.h>
#include<limits.h>
struct STACKNODE{
	
	int Data;
	STACKNODE* pNext;	
};

STACKNODE* getStackNode(int item){
	
	STACKNODE* p = new STACKNODE;
	
	if(p==NULL){
		return NULL;
	}
	
	p->Data = item;
	p->pNext = NULL;
	return p;
}

int isEmpty(STACKNODE* root){
	
	return !root;
}

void push(STACKNODE** root,int item){
	
	STACKNODE* p = getStackNode(item);	
	p->pNext = *root;
	*root = p;
	printf("%d pushed into stack \n",item);
}

int pop(STACKNODE** root){
	
	if(isEmpty(*root))
		return INT_MIN;
		
	STACKNODE* temp = *root;
	*root = (*root)->pNext;
	int popped = temp->Data;
	delete temp;
	return popped;
}

int peek(STACKNODE* root){
	
	if(isEmpty(root))
		return INT_MIN;
	return ((root->pNext)->pNext)->Data;
}
int main(){
	
	STACKNODE* root = NULL;
	
	push(&root,21);
	push(&root,03);
	push(&root,1999);
	
	
	printf("Top of the stack is %d",peek(root));
	return 0;
}

