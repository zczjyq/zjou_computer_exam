#include<iostream>
#define I int
#define f(_)for(I i=1;i<=_;i++)
I n,b[35],m[35],r[35][35];
void y(I o,I _,I h,I A,I d){if(o>_)return;I p=h;r[d][++r[d][0]]=b[_];while(m[p]!=b[_])p++;
y(o,o+p-1-h,h,p-1,d+1);y(o+p-h,_-1,p+1,A,d+1);}
int main(){std::cin>>n;f(n)std::cin>>b[i];f(n)std::cin>>m[i];y(1,n,1,n,0);
for(I z=0;r[z][0];z++)f(r[z][0])std::cout<<(!z?"":" ")<<r[z][i];}