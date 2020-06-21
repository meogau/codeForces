#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[100000];
int f[100000];
int main(){
	int n,l1,l2;
	cin>>n>>l1>>l2;
	for ( int i = 1; i <= n ; i ++) {
cin >> a [ i ];
 }
 int res = 0;
 for ( int i = 1; i <= n ; i ++) {
f[ i ] = a[ i ];
for ( int j = max (1 , i - l2 ); j <= i - l1 ; j ++) {
f[ i ] = max ( f [ i ] , f [ j ] + a [ i ]);
 }
 res = max ( res , f [ i ]);
 }
 cout << res << endl ;
 return 0;

}
