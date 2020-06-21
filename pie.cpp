#include<iostream>
#include <math.h>
using namespace std;

const double pi = acos(-1);
 int main(){
 	int numoftest,n,f,maxf;
 	double min,max,mid;
 	double r[10001];
 	cin>>numoftest;
 	while(numoftest -->0){
 		cin>>n>>f;
 		for(int i=0;i<n;i++){
 			scanf("%lf",&r[i]);
			r[i] *= r[i];
		 }
		 min =0.0;
		 max =100000000.0;
 		while(min+ 1e-7 <max){
 			mid =(min+max)/2;
 			maxf =0;
 			for(int i=0;i<n;i++){
 				maxf += (int)floor(r[i]/mid);
			 }
			 if(maxf<=f) max =mid;
			 else min =mid;
		 }
		min = min *pi;
	 printf("%.6lf\n",min);
	 }
	 
 	return 0;
 }
