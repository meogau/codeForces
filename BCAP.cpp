#include<bits/stdc++.h>
using namespace std;
#define INF 9999999999999
int n,m ,c[17],p[17][17],load[6],cou[17],res = INF;//load[i]: so tin chi hoc trong khoa i
									  // course[i]: mon i duoc xep vao khoa hoc nao
int canLoad(int course,int periods){
	for(int i =1;i<=n;i++){
		if(p[course][i]==1 && cou[i]<=periods) return 0; 
	}
	return 1;
}
int getAns(){
 return * max_element ( load + 1, load + n + 1);
}
void tryy(int i){
	if(i>n) {
	res = min(	res,getAns());
	return;
		
	}
	for(int j=1;j<=m;j++){
		if(canLoad(i,j)){
			load[j]+=c[i];
			cou[i]=j;
			tryy(i+1);
			load[j]-=c[i];
			cou[i]=INF;
		}
	}
}
int main(){
	memset(load,0,sizeof(load));
	memset(p,0,sizeof(p));
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>> c[i];
		cou[i]=INF;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) cin>>p[i][j];
	tryy(1);
	cout<<res;
	
}
