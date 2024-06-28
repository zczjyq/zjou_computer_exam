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
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    // 创建结果链表的头节点
    List res = (List)malloc(sizeof(struct Node));
    List a = res; // a 用于指向结果链表的尾部

    // 获取两个链表的首节点
    List p1 = L1->Next, p2 = L2->Next;

    // 遍历两个链表，比较节点的值，将较小的节点加入结果链表
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->Data < p2->Data)
        {
            0 a->Next = p1; // 将 p1 加入结果链表
            p1 = p1->Next;  // 移动 p1 指针
        }
        else
        {
            a->Next = p2;  // 将 p2 加入结果链表
            p2 = p2->Next; // 移动 p2 指针
        }
        a = a->Next; // 移动 a 指针，指向结果链表的尾部
    }

    // 处理剩余的节点，将剩余的链表直接加入结果链表的尾部
    a->Next = (p1 != NULL) ? p1 : p2;
    L1->Next = L2->Next = NULL;
    return res; // 返回结果链表的头节点
}