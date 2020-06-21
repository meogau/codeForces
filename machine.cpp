#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,N=1,res=0;;
		cin>>n;
	int t[n+1],s[n+1];

	for(int i =1;i<=n;i++){
		scanf("%d %d",&s[i],&t[i]);
		N= max(N,t[i]);
	}
	int maxs[N+1];
		memset(maxs,0,sizeof(maxs));
	for(int i =1;i<=n;i++){
		maxs[t[i]] = t[i]-s[i];
	
	}
	for(int i =1;i<=N;i++){
		maxs[i] = max(maxs[i-1],maxs[i]);
		//cout<<i<<" :"<<maxs[i]<<endl;
	}
    for(int i =2;i<=n;i++){
    	if(maxs[s[i]-1]>0)res = max(res,maxs[s[i]-1]+t[i]-s[i]);
    	
	}
	if(res>0)	cout<<res;
    else cout<<"-1";
}
