// 完全背包问题
// leetcode 的题目 https://leetcode.cn/problems/coin-change/
// acwing 的题目  https://www.acwing.com/file_system/file/content/whole/index/content/3554/

// leetcode 的代码
#include <cstring>
#include <vector>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[100010];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i ++ ) 
            for (int j = coins[i]; j <= amount; j ++ ) 
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        return dp[amount] == 0x3f3f3f3f ? -1 : dp[amount];
    }
};

// acwing 的代码
#include <iostream>

using namespace std;

int n, m;
int w, v, f[1000];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) {
        cin >> w >> v;
        for (int j = w; j <= m; j ++ )
            f[j] = max(f[j], f[j - w] + v);
    }
    cout << f[m];
}