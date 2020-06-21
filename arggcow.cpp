#include <bits/stdc++.h>
using namespace std;
int n,c;
long long pos[100000];
int check(long long dis){
	int i=0,num =1;
	for(int j=0;j<n;j++){
		if(pos[j]-pos[i]>=dis) {
			i=j;
			num++;
		}
	}
	if(num<c) return 0;
	return 1;
}
int main(){
	int numoftest;
	scanf("%d",&numoftest);
	while(numoftest-->0){
		cin>>n;
		cin>>c;
		for(int i=0;i<n;i++) scanf("%lli",&pos[i]);
		sort(pos,pos+n);
		long long  left, mid,right;
		left = 0;
		right = 5e9;
		while(left+1<right){
			mid=(left+right)/2;
			if(check(mid)) left = mid;
			else right = mid;
		}
	cout<<left<<endl;
	}
}
