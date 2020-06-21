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
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
      cout<<arr[i]<<" ";

}
 
 
int main()
{
    int size; cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)cin>>arr[i];
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}
