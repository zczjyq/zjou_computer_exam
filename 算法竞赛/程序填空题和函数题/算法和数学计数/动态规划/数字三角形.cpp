// 题目链接https://www.acwing.com/problem/content/description/900/

#include <iostream>

using namespace std;

int n;
int nums[510][510], dp[510][510];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= i; j ++ ) 
            cin >> nums[i][j];

    for (int i = n; i >= 1; i -- ) 
        for (int j = 1; j <= i; j ++ ) 
            // 动态转移方程
            dp[i][j] = nums[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
    cout << dp[1][1];
}