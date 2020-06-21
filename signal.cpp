#include <bits/stdc++.h> 
using namespace std;
int max(int a,int b) {
	if(a>b) return a;
	return b;
}
int main(){
	int n,b;
	cin>>n>>b;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int maxLeft[n];maxLeft[0]=a[0];
	int maxRight[n];maxRight[n-1]=a[n-1];
	for(int i=1;i<n;i++){
		int j=n-i-1;
		maxLeft[i]=max(a[i],maxLeft[i-1]);
		maxRight[j]=max(a[j],maxRight[j+1]);
	} 
	int res=-1;
		for(int i=1;i<n;i++)
		if((maxLeft[i]-a[i])>=b &&(maxRight[i]-a[i])>=b) res = max(res,maxLeft[i]+maxRight[i]-2*a[i]);
	
	cout<<res;
}
