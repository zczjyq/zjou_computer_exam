// 本题数据量达到10^5 所以要用nlogn时间复杂度的算法，即二分查找
#include <set>
#include <iostream>

using namespace std;

int n, m;
set<int> s;

int main() {
    cin >> n;
    while (n -- ) {
        cin >> m;
        if (s.upper_bound(m) != s.end())
            s.erase(s.upper_bound(m));
        s.insert(m);
    }
    cout << s.size();
}
