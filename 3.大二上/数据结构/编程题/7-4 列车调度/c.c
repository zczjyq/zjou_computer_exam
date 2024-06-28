#include <stdio.h>

#define N 100010

int rail[N];
int top = 0;

void put(int num) {
    int low, high, mid;
    if (!top || rail[top - 1] < num) 
        // 当top=0或输入的列车序号比每个轨道最后一趟列车序号还大时，开辟新轨道
        rail[top ++ ] = num;
    else {
        low = 0;
        high = top - 1;

        while (low <= high) {
            // 二分查找
            mid = (low + high) / 2;
            if (rail[mid] < num) low = mid + 1;
            else high = mid - 1;
        }

        rail[low] = num;  // 将序号为num的列车放入相应轨道
    }
}

int main() {
    int i, n, num;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        put(num);
    }

    printf("%d\n", top);
    return 0;
}
