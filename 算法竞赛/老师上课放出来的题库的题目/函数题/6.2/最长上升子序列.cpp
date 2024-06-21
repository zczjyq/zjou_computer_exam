// https://www.acwing.com/file_system/file/content/whole/index/content/4422/
#include <iostream>

using namespace std;

int n, res;
int nums[1010], dp[1010];

int main () {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> nums[i];
    
    for (int i = 1; i <= n; i ++ ) {
        dp[i] = 1;
        for (int j = 1; j <= i; j ++ ) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    for (int i = 1; i <= n; i ++ ) res = max(res, dp[i]);
    cout << res;
}