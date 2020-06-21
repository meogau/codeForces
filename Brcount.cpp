#include <iostream> 
using namespace std;
int count;
int res,n;
char arr[]={'(',')'};

void Try(int k,string s){
int j;
if(s[k]=='(') {
	res++;Try(k+1,s);return;
}
if(s[k]==')') {
	res--; Try(k+1,s);return;
}
for (j = 0; j<=1; j++) {
s[k] = arr[j];
if(s[k]=='(') res++;
if(s[k]==')') res--;
if (k == n && res==0)count++;
else Try(k+1,s);
}
}
int main(){
	string s="()()()!@#";
	n=s.length()-1;
	Try(0,s)
	cout<<count;
}
