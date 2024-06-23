#include<iostream>
using namespace std;
#define I long
I n,_[25],b[25],t[25][25];
void B(I N,I M,I L,I R,I d){if(N>M)return;I r=b[R],m=N;
while(r!=_[m])m++;t[d][++t[d][0]]=r;
B(N,m-1,L,L+m-N-1,d+1);B(m+1,M,L+m-N,R-1,d+1);}
int main(){cin>>n;for(I i=1;i<=n;i++)cin>>_[i];
for(I i=1;i<=n;i++)cin>>b[i];B(1,n,1,n,1);
cout<<"R:";for(I i=1;t[i][0]!=0;i++)cout<<" "<<t[i][t[i][0]];
cout<<"\nL:";for(I i=1;t[i][0]!=0;i++)cout<<" "<<t[i][1];}