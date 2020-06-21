#include <bits/stdc++.h> 
#include <stack>
using namespace std;
#include <bits/stdc++.h> 
using namespace std;
void swap(int &a, int &b)
{
	
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
      
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 


int dot(int *a,int*b,int n){
	int res =0;
  for(int i=0;i<n;i++) res = res+a[i]*b[n-i-1];
  return res;
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
      cout<<arr[i]<<" ";

}
int main(){
int numOfTest;
cin>>numOfTest;
int count = 1;
int n;
while(numOfTest-->0){
	cin>>n;
	int a [n];int b[n];
	  for(int i=0;i<n;i++) cin>>a[i];
	  for(int i=0;i<n;i++) cin>>b[i];
	  int size = sizeof(a)/sizeof(a[0]);
	  quickSort(a, 0, size-1);
	  quickSort(b, 0, size -1);
	cout<<"Case #"<<count<<": "<<dot(a,b,n)<<endl;
	count ++;
}
}
