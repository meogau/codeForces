#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
	int n;
    int k;
	int a[5000];
	
int count(){
	int l,r;
	int c=0,cl=1,cr=1,il=0,ir=0;
	for(int i=0;i<n-3;i++){
		l=i+1; r=n-1;
		while(l<r){
			if(a[i]+a[l]+a[r]==k) {
				
			 while(a[l]==a[l+1]&&l<r){
			 	l++;
			 	cl++;
			 	il=1;
			 }
			 while(a[r]==a[r-1]&&l<=r){
			 	 r--;
			     cr++;
			     ir=1;
			 }
			c= c+ cr*cl;
		//	cout<<"i  "<<i<<"C  "<<c<<"L  "<<l<<"R  "<<r<<endl;
			 l++;
			 r--;
			cl=1;cr=1;il=0;ir=0;
			}
			else if(a[i]+a[l]+a[r]>k) r--;
			else l++;
		}
	}
	return c;
}
int main(){

	scanf("%d",&n);scanf("%d",&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	cout<<count();
}
