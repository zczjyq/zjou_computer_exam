#include<iostream>
#define I int
#define f for(I i=1;i<=n;i++)
I n,m[100010],d[100010],_=1,g;
I D(I u){if(d[u])return d[u];d[u]=D(m[u])+1;_=std::max(_,d[u]);return d[u];}
I main(){std::cin>>n;f{std::cin>>m[i];if(m[i]==-1)d[i]=1;}
f if(!d[i])D(i);std::cout<<_<<'\n';f if(_==d[i])std::cout<<(g?" ":"")<<i,g = 1;}