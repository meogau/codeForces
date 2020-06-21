#include <iostream> 
using namespace std;


char a[]={'(',')'};
int count;int n;
int check;
void Ghinhan(){
	if(check==0) count ++;
}
void Try(int k,string b){
	
if(b[k]=='(') {
	check++;
	if (k == n) Ghinhan();
	else Try(k+1,b);
}
if(b[k]==')') {
	check++;
	if (k == n) Ghinhan();
	else Try(k+1,b);
}
for (int j = 0; j<=1; j++) {
b[k] = a[j];
if(b[k]=='(') check++;
if(b[k]==')') check--;
if (k == n) Ghinhan();
else Try(k+1,b);
if(b[k]=='(') check++;
if(b[k]==')') check--;
}
}
int main(){
	string s;
	cin>>s;
	n=s.length()-1;
	Try(0,s);
	cout<<count;
}
