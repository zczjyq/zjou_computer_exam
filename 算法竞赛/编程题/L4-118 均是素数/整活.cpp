#include<iostream>
#define f(_,n)for(int _=n;p[_]<=m;_++)
const int N = 1e6 + 10;
int m,n,p[N],c,r,t[N],f,s;
int main(){std::cin>>n>>m;for(int i=2;i<N;i++){f=1;
for(int j=0;j<c&&p[j]<=i/p[j];j++)if(i%p[j]==0){f=0;break;}
if(f)p[c++]=i,t[i]=true;}while(p[s]<n)s++; 
f(i,s)f(j,i+1)f(k,j+1)if(t[p[i]*p[j]+p[k]]&&t[p[i]+p[j]*p[k]]&&t[p[i]*p[k]+p[j]])r++;
std::cout<<r;}