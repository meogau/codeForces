#include<bits/stdc++.h>
using namespace std;
int binary(int n){
	if(n==1) {
		printf("1");
		return 0;
	}
	binary(n/2);
	printf("%d",n%2);
	return 0;
}
int main(){int x=0;
 int n;
 cin>>n;
 binary(n);
}
