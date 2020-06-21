#include<bits/stdc++.h>
using namespace std;
#define INF 999999
int m,n,ans;
int load[11];
int teach [11][31];
int cant_assign [11][31];
int conflict [31][31 ] ;

int get_ans () { return * max_element ( load + 1, load + n + 1); }
   
void arrange ( int i) {

 	for (int j = 1; j <= m ; j ++) {
 		if ( teach [j ][ i] == 1 && cant_assign [j ][ i] == 0){
 				if(load[j]+1>=ans) continue;
 				load[j]++;
 		for(int k=1;k<=n;k++)if(conflict [ k ][ i ] == 1) cant_assign [j ][k] = 1;
 		if(i==n)ans = min ( ans , get_ans ());
 		else arrange (i + 1);
 //tra de quy 
 		for(int k=1;k<=n;k++)if(conflict [ k ][ i ] == 1) cant_assign [j ][k] = 0;
 		load[j]--;
		 }
 }

 }
int main () {
	memset(load,0,sizeof(load));
	memset(teach,0,sizeof(teach));
	memset(conflict,0,sizeof(conflict));
	memset(cant_assign,0,sizeof(cant_assign));
	cin >> m >> n;
	//scanf khoa hoc gv co the day
 	for (int j = 1; j <= m ; j ++) {
 	int k;
	cin >> k ;
 	while (k --) {
 	int p;
	cin >> p ;
 	teach [j ][ p] = 1;
 		}
 }
 //scanf khoa hoc ko the day boi 1 gv
 	int q;
 	cin >> q ;
 	while (q --) {
 	int p1 , p2 ;
 	cin >> p1 >> p2 ;
 	conflict [ p1 ][ p2 ] = 1;
 	conflict [ p2 ][ p1 ] = 1;
 		}
 	ans = 99 ;
 	arrange (1);
 	 cout << (ans > n ? -1 : ans);
 }

