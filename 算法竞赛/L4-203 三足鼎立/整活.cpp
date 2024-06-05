#include<iostream>
#include<algorithm>
#define f for(int i=0;i<n;i++)
using namespace std;
long long n,p,r,s[200010];
int main(){cin>>n>>p;
f cin>>s[i];sort(s,s+n);f r+=(lower_bound(s+i+1,s+n,p+s[i])-upper_bound(s+i+1,s+n,p-s[i]));cout<<r;}