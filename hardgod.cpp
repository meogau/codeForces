#include<bits/stdc++.h>
#define pi pair<int ,int>
using namespace std;



int main(){
	int n,l1,l2;
	long long int top,rel=0;
	cin>>n>>l1>>l2;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	priority_queue <pi> q;
	long long int  save[n];save[0] =a[0];
	for(int i=1;i<n;i++){
		save[i]=a[i];
		if(i-l1<0)continue;
		 q.push({save[i-l1],i-l1});
		top=q.top().first;
		while(i-q.top().second>l2){
			q.pop();
			top=q.top().first;
		}
		save[i]=a[i]+q.top().first;
		
	}
	for(int i=1;i<n;i++) rel = max(rel,save[i]);
	cout<<rel<<endl;
}
