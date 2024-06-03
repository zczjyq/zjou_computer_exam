#include<iostream>
int n,s,l,_,m,j;
int main(){std::cin>>n;for(int i=2;i<n/i;i++)
{l=0,j=i,_=n;while(_%j==0)l++,_/=j++;if(l>m)m=l,s=i;}
if(!s)s=n,m=1;_=1;std::cout<<m<<'\n'<<s;
for(int i=s+1;_<m;i++,_++)std::cout<<"*"<<i;}