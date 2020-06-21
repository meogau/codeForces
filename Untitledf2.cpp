
// C++ program to find product 
// of all subarray of an array 
  
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find product of all subarrays 
void product_subarrays(int arr[], int n) 
{ 
    // Variable to store the product 
    int product = 1; 
  
    // Compute the product while 
    // traversing for subarrays 
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            product *= arr[j]; 
        } 
    } 
    // Printing product of all subarray 
    cout << product << "\n"; 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 10, 3, 7 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    product_subarrays(arr, n); 
  
    return 0; 
} 
