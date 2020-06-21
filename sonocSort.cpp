#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
       
   }
}

int main(){
	int count, n;
	cin>>n;
	int* a;
	a= new int [n];
	fflush(stdin);

	for( int i=0;i<n;i++){
		cin>>a[i]; 
		if((a[i]%2)==0) count++;
	}
	
	if(count!=0){
		int * arrN = new int [count];
		int arrNCount=0;
		for(int j=0;j<n;j++){
			if((a[j]%2)==0)
			{arrN[arrNCount]=a[j];
				arrNCount++;
			 } 
			
		}
		insertionSort(arrN,arrNCount);
		// sao chep sang mang goc
		
		int NCount=0;
		for(int j=0;j<n;j++){
			if(a[j]%2==0){
				a[j]=arrN[NCount];
				NCount++;
			}
			
			 } 
			
	}
	for(int i=0;i<n;i++){
	 printf("%d ",a[i]);
	}
}
	

