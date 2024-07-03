// https://www.acwing.com/problem/content/897/

#include <iostream>

using namespace std;

int n, m, dp[1010][1010];
char A[1010], B[1010];

int main() {
    cin >> n >> m;
    scanf("%s%s", A + 1, B + 1);

    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ ) 
            if (A[i] == B[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    cout << dp[n][m];
}