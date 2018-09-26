#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100

struct NV{
	int 	MNV;
	char 	TNV[30];
	float 	Luong;
};
void nhapN(int &n){
	do
	{
		printf("Nhap so nhan vien: \n");
		scanf("%d", &n);
		
		if(n<0 || n>100){
			printf("Nhap sai. Nhap lai\n");
		}
	}while(n<0 || n>100);
}

void nhap1NV(NV &h){
	printf("Nhap MNV: \n");
	scanf("%d",&h.MNV);
	printf("Nhap Ho va Ten:\n");
	gets(h.TNV);
	gets(h.TNV);
	printf("Nhap luong: \n");
	scanf("%f",&h.Luong);
}

void xuat1NV(NV h){
	printf("Ma NV: %d \n",h.MNV);
	printf("Ho va Ten: %s \n,",h.TNV);
	printf("Luong: %f \n",h.Luong);
}

void nhapMang(NV a[],int n){
	for(int i=0;i<n;i++){
		printf("\n<<Nhap thong tin NV thu %d:>>\n",i+1);
		nhap1NV(a[i]);
	}
}

void xuatMang(NV a[],int n){
	for(int i=0;i<n;i++){
		printf("\n<<Thong tin NV thu %d:>>\n",i+1);
		xuat1NV(a[i]);
	}
}
void Swap(NV &a,NV &b){
	NV t=a;a=b;b=t;
	
}
void selectionSort(NV a[],int n){
	NV min;
	for(int i=0 ;i<n-1;i++){
		min.Luong = a[i].Luong;
		for(int j=i+1;j<n;j++){
			if(a[j].Luong < min.Luong){
				Swap(a[j],min);
			}
		}
		Swap(a[i],min);
	}
}

void insertionSort(NV a[],int n){
	int pos;
	NV x;
	for(int i=0;i<n;i++){
		x.Luong = a[i].Luong; pos = i-1;
		while(pos >= 0 && a[pos].Luong > x.Luong){
			Swap(a[pos+1],a[pos]);
			pos--;
		}
		Swap(a[pos+1],x);
	}
}
int main(){
	int n;
	nhapN(n);
	
	NV a[MAX];
	nhapMang(a,n);
	xuatMang(a,n);
	
	/*printf("{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{Selection Sort}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}\n");
	selectionSort(a,n);*/
	
	printf("\n\n\nInsertion Sort \n");
	//insertionSort(a,n);
	selectionSort(a,n);
	xuatMang(a,n);
	return 0;
}
