#include<conio.h>
#include<iostream>
using namespace std;
typedef struct
{
    int n;
    long *a;
}Dathuc;
void Nhap(Dathuc &A)
{
     cin>>A.n;
    A.a=new long [A.n+1];
    for(int i=0;i<=A.n;i++)
    {
        cin>>A.a[i];
    }
}

void Tich(Dathuc P,Dathuc Q,Dathuc &R)
{
    R.n=P.n+Q.n;
    R.a=new long [R.n+1];
    for(int i=0;i<=R.n;i++)
    {
        R.a[i]=0;
        for(int j=0;j<=P.n;j++)
        if(i>=j && i-j<=Q.n) R.a[i]+=P.a[j]*Q.a[i-j];
    }
}
int main(){
   Dathuc dathuc1,dathuc2,dathucKQ ;
   Nhap(dathuc1);
   Nhap(dathuc2);
   Tich(dathuc1,dathuc2,dathucKQ);
   long kq=0;
   for(int i=0;i<=dathucKQ.n;i++) kq = kq^dathucKQ.a[i];
   cout<<kq;
   
}

