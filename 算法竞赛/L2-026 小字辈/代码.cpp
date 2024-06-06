#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, nums[N], deep[N], max_deep = 1;

int dfs(int u) {
    if (deep[u]) return deep[u];
    deep[u] = dfs(nums[u]) + 1;
    max_deep = max(max_deep, deep[u]);
    return deep[u];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        cin >> nums[i];
        if (nums[i] == -1) deep[i] = 1;
    }

    for (int i = 1; i <= n; i ++ )
        if (!deep[i])
            dfs(i);

    cout << max_deep << endl;
    bool flag = true;
    for (int i = 1; i <= n; i ++ ) {
        if (max_deep == deep[i]){
            if (flag) cout << i;
            else cout << ' ' << i;
            flag = false;
        }
    }
}