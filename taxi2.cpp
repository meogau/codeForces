#include<bits/stdc++.h>
using namespace std;
#define INF 99999999999
int n,c[23][23],res=INF;
int calc(int a[]){
	int rel =0;
	int now =0;
	for(int i =0;i<n;i++){
		rel+=c[now][a[i]] + c[a[i]][a[i]+n];
		now = a[i]+n;
	}
	return (rel + c[now][0]);
}
int check(int a[]){
	for(int i=0;i<n;i++)if(a[i]!=(n-i)) return 0;
	return 1;
}
int main(){
	cin>>n;
//	memset(visited,0,sizeof(visited));
	for(int i=0;i<=2*n;i++)
	for(int j=0;j<=2*n;j++) scanf("%d",&c[i][j]);
    int a [n];
    for(int i=0;i<n;i++) a[i]=i+1;
    while(1){
    	res = min(res , calc(a));
    	if(check(a)) break;
    	 next_permutation(a,a+n);
	}
	cout<<res;
}
