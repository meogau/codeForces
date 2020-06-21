#include<bits/stdc++.h> 
using namespace std; 
  
// comp function to perform sorting 
bool comp(const string &left, const string &right) 
{ 
    // if length of both string are equals then sort 
    // them in lexicographically order 
    if (left.size() == right.size()) 
        return left < right; 
  
    // Otherwise sort them according to the length 
    // of string in ascending order 
    else
        return left.size() < right.size(); 
} 
  
// Function to sort arr[] elements according 
// to integer value 
void SortingBigIntegers(string arr[], int n) 
{ 
    // Copy the arr[] elements to sortArr[] 
    vector<string> sortArr(arr, arr + n); 
  
    // Inbuilt sort function using function as comp 
    sort(sortArr.begin(), sortArr.end(), comp); 
  
    // Print the final sorted array 
  vector<string>::iterator iter_name; // Khai báo con tr? d? duy?t
for (iter_name = sortArr.begin(); iter_name != sortArr.end(); iter_name++) {
cout << *iter_name << " ";
} 
} 
  
// Driver code of above implementation 
int main() 
{ int n;
//cin>>n;
    string  arr[]={"2222","3333","1"};
    cout<<"aaaaaaaa"<<endl;
 //   for(int i =0;i<n;i++) cin>>arr[i];
    int t = sizeof(arr) / sizeof(arr[0]); 
  cout<<endl<<t;
    SortingBigIntegers(arr, t); 
  cout<<"hhhhh";
    return 0; 
}

