#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 100


void nhapN(int &n){
	do
	{
		printf("Nhap so phan tu cua mang: \n");
		scanf("%d", &n);
		
		if(n<0 || n>100){
			printf("Nhap sai. Nhap lai\n");
		}
	}while(n<0 || n>100);
}

void nhapMang(int a[],int n){
	for(int i=0;i<n;i++){
		a[i] = rand()%100;
	}
}

void xuatMang(int a[],int n){
	for(int i=0;i<n;i++){
		printf("a[%d] = %d \n",i+1,a[i]);
	}
}

void Swap(int &a,int &b){
	int t=a;a=b;b=t;	
}

void bubbleSort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>0;j--){
			if(a[j-1] > a[j])
				Swap(a[j-1],a[j]);
		}
	}
	xuatMang(a,n);
}

void interchangeSort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]){
				Swap(a[i],a[j]);
			}
		}
	}
	xuatMang(a,n);
}

void selectionSort(int a[],int n){
	int m;
	for(int i=0;i<n;i++){
		m = a[i];
		for(int j=i+1;j<n;j++){
			if(a[j] < m){
				Swap(a[j],m);
			}
		}
	a[i] =m;
	}
	xuatMang(a,n);
}

void insertionSort(int a[],int n){
	
	int pos,x;
	for(int i=0;i<n;i++){
		x = a[i]; pos = i-1;
		while(pos >=0 && a[pos] > x){
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
	xuatMang(a,n);
}

int partition(int a[],int l,int r){
	int pivot = a[r];
	int i = l - 1;
	
	for(int j=l;j<r-1;j++){
		if(a[j] <= pivot){
			i++;
			Swap(a[i],a[j]);
		}
	}
	Swap(a[i+1],a[r]);
	return i+1;
}

void quickSort(int a[],int l,int r){
	
	if(l < r){
		int pi = partition(a,l,r);
		
		quickSort(a,l,pi-1);
		quickSort(a,pi+1,r);
	}
}

void menu(int a[],int n){
	int chon;
	
		printf("-----Nhap 1. Bubble Sort \n");
		printf("-----Nhap 2. Interchange Sort \n");
		printf("-----Nhap 3. Insertion Sort \n");
		printf("-----Nhap 4. Selection Sort \n");
		printf("-----Nhap 5. Quick Sort \n");
		printf("///////Nhap 0. Stop \\\\\\\ \n");
		
		do
		{
			printf("=============>Xin moi nhap phim:<=============== \n");
			scanf("%d",&chon);
			
			if(chon <0 || chon >5)
				printf("Nhap sai. Nhap lai.!!!! \n");
			
			
			
			switch(chon){
			case 1:
				printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Bubble Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
				bubbleSort(a,n);
				break;
			case 2:
				printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Interchange Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
				interchangeSort(a,n);
				break;
			case 3:
				printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Insertion Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
				insertionSort(a,n);
				break;
			case 4:
				printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Selection Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
				selectionSort(a,n);
				break;
			case 5:
				printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Quick Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}");
				quickSort(a,0,n-1);
				xuatMang(a,n);
				break;
		}
		}while(chon <0);
		
		
		
}
int main(){
	int n;
	nhapN(n);
	
	int a[MAX];
	nhapMang(a,n);
	printf("***********************<<<Xuat mang vua nhap>>>****************************** \n");
	xuatMang(a,n);
	
	menu(a,n);
	return 0;
}
