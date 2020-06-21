#include <bits/stdc++.h> 
using namespace std;

int countReRoad(int * arr,int n){
	int rel = arr[0];
	int count =1;
	for(int i=1;i<n;i++)
	 if(rel!=arr[i]){
		rel =arr[i];
		count++;
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int numOfTest;
	cin>>numOfTest;
	int index,value;
	while(numOfTest-- > 0){
		cin>> index;cin>>value;
		arr[index-1]=value;
		cout<<countReRoad(arr,n)<<endl;
	}
	
	
	
	return 0;
}
