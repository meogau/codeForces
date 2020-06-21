
#include<iostream> 
#include<stack>
using namespace std; 
  

int getMaxArea(int arr[], int n) 
{ 
 
    stack<int> s; 
  
    int max_area = 0;
    int tp; 
    int area_with_top;
  
    int i = 0; 
    while (i < n) 
    { 
 
        if (s.empty() || arr[s.top()] <= arr[i]) 
            s.push(i++); 
  
 
        else
        { 
            tp = s.top();  
            s.pop();  

            area_with_top = arr[tp] * (s.empty() ? i :  
                                   i - s.top() - 1); 

            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 

    while (s.empty() == false) 
    { 
        tp = s.top(); 
        s.pop(); 
        area_with_top = arr[tp] * (s.empty() ? i :  
                                i - s.top() - 1); 
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
} 
  
int main() 
{   int n; 
    cin>>n;
    while(n!=0){
    	int hist[n];
    	for(int i=0;i<n;i++) cin>> hist[i];
    	cout<<getMaxArea(hist, n)<<endl; 
    	cin>>n;
	}
   
    return 0; 
} 
