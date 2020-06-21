#include <bits/stdc++.h>
using namespace std;
#define maxbook 501
int n,m,book[maxbook];

int check(long long maxpage){
	int index =1;
	long long now =0;
	for(int i=n;i;i--){
		if(now + book[i]<=maxpage){
			now+= book[i];
		}
		else{
			index++;
			if(book[i]>=maxpage) return 0;
			if(index>m) return 0;
			now = book[i];
		}
	}
	return 1;
}
int main(){
	int numoftest;
	scanf("%d",&numoftest);

	while(numoftest-->0){
		long long sum=0;long long min=0;
		scanf("%d",&n);	scanf("%d",&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&book[i]);
			sum+= book[i];
		}
	long long max = sum;	long long mid;
		while(min+1<max){
			
		  mid= (min+max)/2;
		  if(check(mid)==1) max = mid;
		  else min= mid ;
		}
	if(!check (min)) min = max;
        stack<int> pos_slash;
		long long sum2 = 0;
		for (int i =  n; i > 0; --i) {
			if (sum2 + book[i] <= min) {
				sum2 += book[i];
			} else {
				sum2 = book[i];
				pos_slash.push(i);
			}
		}
		
		int deficient_slash = m - pos_slash.size() - 1;
		int i = 1;
		while (deficient_slash) {
			cout << book[i] << "  / ";
			if (pos_slash.size() && pos_slash.top() == i) pos_slash.pop();
			else --deficient_slash;
			++i;
		}
		while (i <= n) {
			cout << book[i] << " ";
			if (pos_slash.size() && pos_slash.top() == i) {
					cout << " / ";
					pos_slash.pop();
				}
			++i;
		}
		cout << "\n";

	}


	
}
