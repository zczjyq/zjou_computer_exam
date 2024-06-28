#include <iostream>

using namespace std;

const int N = 110;
int n, m, f[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> f[i];
    for (int i = 0; i < n; i++)
        if (i == 0) cout << f[(i + m) % n];
        else cout << ' ' << f[(i + m) % n];
}