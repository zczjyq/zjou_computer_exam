#include<iostream>
#define R return
#define F for(int i=0;i<n;i++)
int m,n,k;bool C(){int h=-1,c=1,s[1010],v[1010],x;F std::cin>>v[i];F{x=v[i];
if(!h||x>=c){while(x>=c)s[++h]=c++;if(h+1>m)R 0;}else if(s[h]!=x)R 0;h --;}R 1;}
int main(){std::cin>>m>>n>>k;while(k--)puts(C()?"YES":"NO");}