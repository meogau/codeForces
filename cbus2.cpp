#include<bits/stdc++.h>
using namespace std;
int visited[23], c[23][23];
int n,l,k,now=0;
int res =9999999999;
int isSolution(){
	for(int i =1;i<2*n+1;i++){
	
		if(visited[i]==0) return 0;
	}
	return 1;
}
int canVisit(int p){
	if(p<=n){
		if(l<k && visited[p]==0) return 1;
		else return 0;
	}
	else{
		 if(visited[p-n] && visited[p]==0) return 1;
		 else return 0;
	}
}
tryy(int p){
	if(isSolution()) res = min(res,now+c[p][0]);
	for(int i=1;i<2*n+1;i++){
		if(canVisit(i)) {
			if(i<=n) l++;
			else l--;
			visited[i]=1;
			now+= c[p][i];
			if(now<res)tryy(i);
			if(i<=n) l--;
			else l++;
			visited[i]=0;
			now-= c[p][i];
		
		}
	}
}
int main(){
	memset(visited,0,sizeof(visited));
	cin>>n>>k;
	for(int i=0;i<=2*n;i++){
			for(int j=0;j<=2*n;j++) scanf("%d",&c[i][j]);
	}
	tryy(0);
	cout<<res;
}
