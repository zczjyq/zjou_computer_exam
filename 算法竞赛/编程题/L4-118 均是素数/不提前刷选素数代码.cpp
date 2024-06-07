#include <iostream>
#include <cmath>

using namespace std;

int n, m, a[10000], flag1 = 0, k = 0, count = 0;

int sushu(int i) {
    int flag1=0;
    if(i >= 2) {
        for(int j = 2;j <= sqrt(i); j ++) {
            if(i % j == 0) {
                flag1 = 1;
                break;
            }
        }
    }
    else return 1;
    return flag1;
}

int main() {  
    cin >> n >> m;
    for(int i = n; i <= m; i ++ ) {
        flag1 = sushu(i);
        if(flag1 == 0) {
            a[k] = i;
            k ++;
        }
    }	
    for(int i = 0; i <= k; i ++) 
        for(int j = i; j <= k; j ++) 
            for(int t = j ;t <= k;  t++) 
                if((sushu(a[i]*a[j]+a[t])==0)&&(sushu(a[j]*a[t]+a[i])==0)&&(sushu(a[t]*a[i]+a[j])==0))
                count++;
    cout << count;
}
