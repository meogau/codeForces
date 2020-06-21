#include<iostream>
#include<math.h>

using namespace std;

long long cut(long long h,long long arr[],int n){
	long long rel =0 ;
	for(int i=0;i<n;i++){
		if(arr[i]>h) rel += arr[i]-h; 
	}
	return rel;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); 
	long long min=0;long long  max =0;
	int n;
	long long m,mcut,mid;
	cin>>n>>m;
	long long arr [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>max) max =arr[i];
	}
	while(min+1<max){
		mid = (min+max)/2;
		mcut = cut(mid,arr,n);
		if(mcut<m) max =mid;
		else min = mid;
	}
	cout<<min;
	return 0;
}
