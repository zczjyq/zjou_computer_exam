#include<iostream>
int n,z,y=1,x,m,_;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){std::cin>>n;for(int i=0;i<n;i++)
scanf("%d/%d",&x,&m),z=z*m+x*y,y*=m,_=gcd(z,y),z/=_,y/=_;
if(y==1)std::cout<<z;else if(z>y)printf("%d %d/%d",z/y,z%y,y);
else printf("%d/%d",z,y);}
