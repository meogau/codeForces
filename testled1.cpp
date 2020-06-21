#include<bits/stdc++.h>
using namespace std;
#define START 10
void printB(int n){
	if(n==1) {
		printf("1");return;
	}
	printB(n/2);
	printf("%d",n%2);return;
}
int main(){
int x=4,y=3;
double a,b;
a=(double) (x/y);
b=(int) (x/y*x);
printf("%2f     %2f",a,b);
}
