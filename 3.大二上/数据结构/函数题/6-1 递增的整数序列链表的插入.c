#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Insert(List L, ElementType X) {
    // 保存头节点
    List res = L;
    // 下一个节点不空并且小于X
    while (L->Next != NULL && L->Next->Data < X)
        L = L->Next;
    // 申请内存
    List node = (List)malloc(sizeof(List));
    node->Data = X;
    node->Next = L->Next;
    L->Next = node;
    return res;
}