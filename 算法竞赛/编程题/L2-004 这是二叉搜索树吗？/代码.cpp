#include <iostream>
#include <vector>

using namespace std;

int n;
int nums[1010];
bool flag;
vector<int>v;

void find(int l, int r) {
    if (l > r) return ;
    int ml = l + 1, mr = r;
    if (flag) {
        while (ml <= r && nums[ml] >= nums[l]) ml ++ ;
        while (mr > l && nums[mr] < nums[l]) mr -- ;
    } else {
        while (ml <= r && nums[ml] < nums[l]) ml ++ ;
        while (mr > l && nums[mr] >= nums[l]) mr -- ;
    }
    // cout << ml << ' ' << mr << endl;
    if (ml - mr != 1) return;
    find(l + 1, mr), find(ml, r);
    v.push_back(nums[l]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> nums[i];
    find(0, n - 1);
    // cout << v.size() << endl;
    if (v.size() != n) {
        flag = !flag;
        v.clear();
        find(0, n - 1);
    }
    // cout << v.size() << endl;
    if (v.size() != n) cout << "NO";
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i ++ ) {
            if (i == 0) cout << v[i];
            else cout << " " << v[i];
        }
    }
}