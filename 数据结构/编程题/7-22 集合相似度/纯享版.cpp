#include <iostream>
#include <set>
using namespace std;
int k, n, t, l, r, ans;
set<int> s[51];
int main() {
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> t;
            s[i].insert(t);
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        ans = 0;
        cin >> l >> r;
        for (int element : s[l]) ans += s[r].count(element);
        printf("%.2f%%\n", ans * 100.0 / (s[r].size() + s[l].size() - ans));
    }
}
