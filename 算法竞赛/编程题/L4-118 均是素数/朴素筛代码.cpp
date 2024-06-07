#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 10;

int m, n;
int primes[N], cnt, res;
bool st[N];
unordered_map<int , bool> h; // 用于判断当前的数是不是质数

// 刷选指数
void get_primes(int n) {
    for (int i = 2; i <= n; i ++ ) {
        int flag = 1;
        for (int j = 0; j < cnt && primes[j] <= i / primes[j]; j ++ ) {
            if (i % primes[j] == 0) {flag = 0; break;}
        }
        if (flag) primes[cnt ++ ] = i, h[i] = true;
    }
}
// 判断当前的rqp是否满足
bool check(int a, int b, int c) {
    return h[a * b + c] && h[a + b * c] && h[a * c + b];
}

int main() {
    cin >> n >> m;
    get_primes(N - 1);
    int start = 0;
    while (primes[start] < n) start ++ ; 
    for (int i = start; primes[i] <= m; i ++ ) {
        for (int j = i + 1; primes[j] <= m; j++ ) {
            for (int k = j + 1; primes[k] <= m; k ++ ) {
                if (check(primes[i], primes[j], primes[k])) {
                    res ++ ;
                }
            }
        }
    }
    cout << res;
}