#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;  // 使用long long类型以支持大整数处理

ll n, p, res;  // n表示其他国家的数量，p是本国的实力值，res用于统计有效的结盟组合数量
ll nums[200010];  // 数组存储其他国家的实力值，注意数组大小是根据问题约束设定的

int main() {
    // 输入处理
    cin >> n >> p;  // 读入国家数量和本国的实力值
    for (int i = 0; i < n; i++) cin >> nums[i];  // 读入其他国家的实力值到数组中

    // 对其他国家的实力值进行排序，以便高效地进行范围查询
    sort(nums, nums + n);

    for (int i = 0; i < n; i++) {
        // 'l' 是第一个使得nums[i]和nums[l]之和不能击败本国的索引位置
        int l = upper_bound(nums + i + 1, nums + n, p - nums[i]) - nums;

        // 'r' 是第一个使得nums[i]和nums[r]之和可以击败本国的索引位置
        int r = lower_bound(nums + i + 1, nums + n, p + nums[i]) - nums;

        res += (r - l);
    }
    // 输出最终的结果
    cout << res;
}
