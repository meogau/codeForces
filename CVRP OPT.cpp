#include<bits/stdc++.h>
using namespace std;
#define INF 99999999999
const int N = 13;
 int n , k , q , d[ N];
 int f [1 << N ], s [5] , res = 0 ;

 void opt ( int u) {
if (u == n) {
 res++;
 } else {
 for (int i = 0; i < k; ++ i )
 s[i ] ^= 1 << u , opt (u + 1) , s[i] ^= 1 << u ;
 }
 }

 int main () {
 scanf ("%d %d %d", &n , &k , & q );
 for (int i = 1; i <= n ; ++ i) scanf ("%d", d + i );
//for (int i = 0; i <= n ; ++ i)
//for (int j = 0; j <= n ; ++ j) scanf ("%d", &c[i ][ j ]);
 memset (f , 0x3F , sizeof f );

 opt (0);
 printf ("%d", res/k );
 }
