#include <iostream>
#include <vector>

using namespace std;

int n, flag;
int nums[1010];
vector <int> v;

void find(int l, int r) {
    if (l > r) return ;
    int tr = r, tl = l + 1;
    if (!flag) {
        while (tl <= r && nums[tl] < nums[l]) tl ++ ;
        while (tr > l && nums[tr] >= nums[l]) tr -- ;
    } else {
        while (tl <= r && nums[tl] >= nums[l]) tl ++ ;
        while (tr > l && nums[tr] < nums[l]) tr -- ;
    }
    if (tl - tr != 1) return;
    find(l + 1, tr); find(tl, r);
    v.push_back(nums[l]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    find(0, n - 1);
    if (v.size() != n) {
        flag = 1;
        v.clear();
        find(0, n - 1);
    }
    if (v.size() != n) cout << "NO";
    else {
        cout << "YES\n" << v.front();
        for (int i = 1; i < v.size(); i ++ ) cout << " " << v[i];
    }
}