#include <iostream>
#include <algorithm>

using namespace std;

long long n, p, res, nums[200010];

int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums + n);
    for (int i = 0; i < n; i++) 
        res += lower_bound(nums + i + 1, nums + n, p + nums[i]) - upper_bound(nums + i + 1, nums + n, p - nums[i]);
    cout << res;
}
