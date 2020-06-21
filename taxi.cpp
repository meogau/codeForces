#include<bits/stdc++.h>
using namespace std;
#define INF 99999999999
int n,c[23][23],visited[23],load=0,v=0,res=INF,now =0;
int canVisit(int i){
	if(visited[i]==1) return 0;
	if(i<=n && load ==1) return 0;
	if(i>n){
		if(visited[i-n]==0) return 0;
	}
	return 1;
}
void tryy(int i){
	if(v>=2*n){
		res = min(res,now+c[i][0]);
		return;
	}
	for(int j = 1;j<=2*n;j++){
		if(canVisit(j)){
			if(j<=n) load ++;
			else load --;
			visited[j]=1;
			now+= c[i][j];
			v++;
			if(now<res)tryy(j);
			// tra de quy
			if(j<=n) load --;
			else load ++;
			visited[j]=0;
			now-= c[i][j];
			v--;
		}
	}
}
int main(){
	cin>>n;
//	memset(visited,0,sizeof(visited));
	for(int i=0;i<=2*n;i++)
	for(int j=0;j<=2*n;j++) scanf("%d",&c[i][j]);
	tryy(0);
	cout<<res;
}
