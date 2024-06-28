#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X) {
    int l = 1, r = L->Last;
    while (l <= r) {
        int mid = l + r >> 1; // >> 1 这种写法可以保证在l r取负数的时候仍满足像0取整,保证代码的稳定性
        if (L->Data[mid] > X) r = mid - 1;
        else l = mid + 1;
    }
    // 查找结束后，检查最终位置的元素是否等于目标元素
    if (L->Data[r] == X) return r; // 关于此处为何取r，画一下图就ok，如果题目问的是最后一个满足条件的数字，代码需要改变
    return NotFound;
}

/*
另外两种模板
bool check(int x) {} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
*/