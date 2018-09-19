#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100

struct Book{
	int 	bookCode;
	char	bookTitle[40];
	float	price;
};

void nhapN(int &n){
	do{
		printf("Nhap n:\n");
		scanf("%d",&n);
		
		if(n<0 || n>100)
			{
				printf("Nhap sai.Nhap lai!!!!\n");
			}
	}while(n<0 ||n>100);
}

void nhap1PT(Book &h){
	printf("Nhap Ma Sach: \n");
	scanf("%d",&h.bookCode);
	printf("Nhap Ten Sach: \n");
	gets(h.bookTitle);
	gets(h.bookTitle);
	printf("Nhap Gia: \n");
	scanf("%f",&h.price);
}

void xuat1PT(Book h){
	printf("\t\tMa Sach:%d \n\n",h.bookCode);
	printf("\t\tTen Sach:%s \n\n",h.bookTitle);
	printf("\t\tGia:%f \n\n",h.price);
}

void nhapMang(Book arr[],int n){
	for(int i=0;i<n;i++){
		printf("************Nhap Thong Tin Quyen Sach %d:************\n",i+1);
		nhap1PT(arr[i]);
	}
}

void xuatMang(Book arr[],int n){
	for(int i=0;i<n;i++){
		printf("************Thong Tin Quyen Sach %d:************\n\n",i+1);
		xuat1PT(arr[i]);
	}
}

int linenearSearchCodeX(Book arr[],Book x,int n){
	for(int i=0;i<n;i++){
		if(arr[i].bookCode == x.bookCode){
			return i;
		}
	}
	return -1;
}

Book Swap(Book &h,Book &k){
	Book t;
	t.bookCode = h.bookCode;
	strcpy(t.bookTitle,h.bookTitle);
	t.price = h.price;
	
	h.bookCode = k.bookCode;
	strcpy(h.bookTitle,k.bookTitle);
	h.price = k.price;
	
	k.bookCode = t.bookCode;
	strcpy(k.bookTitle,t.bookTitle);
	k.price = t.price;
}

void ascendingSort(Book arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i].bookCode > arr[j].bookCode){
				Swap(arr[i],arr[j]);
			}
		}
	}
}

int binarySearchCodeX(Book arr[],Book x,int n){
	ascendingSort(arr,n);
	int l = 0,r = n-1;
	int m;
	
	while(l<r){
		m =(l+r)/2;
		if(arr[m].bookCode == x.bookCode){
			return m;
		}
		if (arr[m].bookCode < x.bookCode){
			r = m-1;
		}
		if (arr[m].bookCode > x.bookCode){
			l = m+1;
		}
	}
	return -1;
}

int timTenSachY(Book arr[],Book x,int n){
	int t;
	for(int i=0;i<n;i++){
		t=strcmp(arr[i].bookTitle,x.bookTitle);
		if(t == 0){
			return i;
		}
	}
	return -1;
}

int timMax(Book arr[],int n){
	int max=arr[0].price;
	for(int i=1;i<n;i++){
		if(arr[i].price > max){
			max = arr[i].price;
		}
	}
	return max;
}

void xuatSachNhieuTienNhat(Book arr[],int n){
	Book b[n];
	int m=0;
	int max=timMax(arr,n);
	for(int i=0;i<n;i++){
		if(arr[i].price == max){
			b[m++] = arr[i];	
		}
	}
	for(int i=0;i<m;i++){
		printf("***********Nhung Sach co tien nhieu nhat***********\n");
		xuat1PT(b[i]);
	}
}
int main(){
	int n;
	nhapN(n);
	Book arr[MAX];
	nhapMang(arr,n);
	xuatMang(arr,n);
	printf("\n\n\n");
	
	
	Book x;
	printf("************Nhap Sach Co Ma X va Ten Sach Y:************\n");
	nhap1PT(x);
	
	/*int m1=linenearSearchCodeX(arr,x,n);
	if(m1<0){
		printf("\\\\\\\\\\\\Khong tim thay///////////\n");
	}
	else{
		printf("************Cuon Sach Co Ma %d: ************\n\n",x.bookCode);
		xuat1PT(arr[m1]);
	}*/
	
	
	/*printf("\n\n\n");
	int m=binarySearchCodeX(arr,x,n);
	if(m<0){
		printf("\\\\\\\\\\\\Khong tim thay///////////\n");
	}
	else{
		printf("************Cuon Sach Co Ma %d: ************\n\n",x.bookCode);
		xuat1PT(arr[m]);
	}*/
	
	/*int m2=timTenSachY(arr,x,n);
	if(m2<0){
		printf("\\\\\\\\\\\\Khong tim thay/////////// \n\n");
	}
	else
	{
		printf("************Sach co Ten la : %s************\n\n",x.bookTitle);
		xuat1PT(arr[m2]);
	}*/
	
	xuatSachNhieuTienNhat(arr,n);
	return 0;
}


















