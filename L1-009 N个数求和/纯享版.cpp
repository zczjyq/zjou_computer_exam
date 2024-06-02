#include <iostream>
using namespace std;

int n, fz_ans = 0, fm_ans = 1, fz, fm;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &fz, &fm);
        fz_ans = fz_ans * fm + fz * fm_ans;
        fm_ans = fm_ans * fm;
        int num = gcd(fz_ans, fm_ans);
        fz_ans /= num, fm_ans /= num;
    }
    if (fm_ans == 1) printf("%d", fz_ans);
    else if (fz_ans > fm_ans) printf("%d %d/%d", fz_ans / fm_ans, fz_ans % fm_ans, fm_ans);
    else printf("%d/%d", fz_ans, fm_ans);
}
