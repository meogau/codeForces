#include<iostream>
using namespace std;

int fib(int n, int k)
{
	if(n<=1) return 1%k;
	return (fib(n-1,k)+fib(n-2,k))%k;
}
int main(){
	int n,k;
	cin>>n;
	cin>>k;
	int input,rel;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		rel = (rel+fib(input,k))%k;
	}
	cout<<rel;
}
