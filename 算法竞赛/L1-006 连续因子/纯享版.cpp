#include <iostream>
using namespace std;
int n, start, len, n1, max_len, j, cnt = 1;
int main() {
    cin >> n;
    for (int i = 2; i < n / i; i ++ ) {
        len = 0, j = i, n1 = n;
        while (n1 % j == 0) len ++, n1 /= j, j++;
        if (len > max_len) max_len = len, start = i;
    }
    if (!start) start = n, max_len = 1;
    cout << max_len << endl << start;
    for(int i = start + 1; cnt < max_len; i++, cnt++) cout << "*" << i;
}