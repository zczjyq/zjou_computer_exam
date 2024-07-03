// https://www.acwing.com/file_system/file/content/whole/index/content/3553/

#include <iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N], dp[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) 
        cin >> v[i] >> w[i];
    for (int i = 0; i < n; i ++ ) 
        for (int j = m; j >= v[i]; j -- ) 
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    cout << dp[m];
}