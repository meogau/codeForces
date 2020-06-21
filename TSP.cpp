 #include<iostream>
using namespace std;
#include<algorithm>
#include <string.h>
#define pi pair<int,int>
#define INF 99999999999
int c[20][20];

int save[(1<<20)][20];
int n;

int tryT(int x, int p){
	if ( __builtin_popcount ( x ) == n ) return c [p][0];
	if(save[x][p]!= -1) return save[x][p];
    int ans = INF ;
    for ( int s = 0; s < n ; ++ s )
    if (( x >> s & 1) == 0){
    ans = min ( ans , c [p][s] + tryT (1 << s | x , s ));
    }
    save [x][p] = ans ;
    return ans ;
    }

int main(){
	int m,x,y,v;
	cin>>n>>m;
	memset(c,10,sizeof(c));
	memset(save,-1,sizeof(save));
	while(m-- >0){
		cin>>x>>y>>v;
		c[x-1][y-1]=v;
	}
	cout<<tryT(1,0);
}

