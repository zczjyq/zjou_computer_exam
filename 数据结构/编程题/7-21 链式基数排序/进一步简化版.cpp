#include <iostream>
#include <algorithm>
using namespace std;
int n, f[1010];
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> f[i];
    int m = *max_element(f, f + n);
    for (int w = 1 ; m / w > 0; w *= 10 ) {
        stable_sort(f, f + n, [w](int a, int b){return a / w % 10 < b / w % 10;});
        for (int j = 0; j < n; j ++ ) cout << f[j] << ' ';
        cout << endl;
    }
}