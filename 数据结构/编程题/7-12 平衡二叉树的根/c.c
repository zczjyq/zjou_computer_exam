#include <stdio.h>
#include <stdlib.h>

// 定义AVL树节点结构
typedef struct node* AVLTree;
typedef struct node {
    int Data;      // 节点存储的数据
    AVLTree Left;  // 左子树
    AVLTree Right; // 右子树
} Node;

// 计算树的高度
int High(AVLTree T) {
    if (!T) return 0;
    int left = High(T->Left) + 1;  // 左子树高度
    int right = High(T->Right) + 1; // 右子树高度
    return (left > right) ? left : right;  // 返回较大的高度
}

// 左旋转(LL旋转)
AVLTree LL(AVLTree T) {
    AVLTree T1 = T->Right;   // T的右子树
    T->Right = T1->Left;     // 将T的右子树指向T1的左子树
    T1->Left = T;            // 将T1的左子树指向T
    return T1;               // 返回旋转后的根节点
}

// 右旋转(RR旋转)
AVLTree RR(AVLTree T) {
    AVLTree T1 = T->Left;    // T的左子树
    T->Left = T1->Right;     // 将T的左子树指向T1的右子树
    T1->Right = T;           // 将T1的右子树指向T
    return T1;               // 返回旋转后的根节点
}

// 左右旋转(LR旋转)
AVLTree LR(AVLTree T) {
    AVLTree T1 = T->Left, T2 = T->Left->Right; // T1为T的左子树，T2为T1的右子树
    T1->Right = T2->Left;    // 将T1的右子树指向T2的左子树
    T->Left = T2->Right;     // 将T的左子树指向T2的右子树
    T2->Right = T;           // 将T2的右子树指向T
    T2->Left = T1;           // 将T2的左子树指向T1
    return T2;               // 返回旋转后的根节点
}

// 右左旋转(RL旋转)
AVLTree RL(AVLTree T) {
    AVLTree T1 = T->Right, T2 = T->Right->Left; // T1为T的右子树，T2为T1的左子树
    T1->Left = T2->Right;    // 将T1的左子树指向T2的右子树
    T->Right = T2->Left;     // 将T的右子树指向T2的左子树
    T2->Left = T;            // 将T2的左子树指向T
    T2->Right = T1;          // 将T2的右子树指向T1
    return T2;               // 返回旋转后的根节点
}

// 插入节点并保持AVL平衡
AVLTree Insert(AVLTree T, int x) {
    if (!T) {
        // 创建新节点
        AVLTree T = (AVLTree)malloc(sizeof(Node));
        T->Data = x;
        T->Left = T->Right = NULL;
        return T;
    } else if (x > T->Data) {
        // 插入到右子树
        T->Right = Insert(T->Right, x);
        if ((High(T->Right) - High(T->Left)) >= 2) {
            // 右子树高度大于左子树，需要旋转
            if (x > T->Right->Data)
                T = LL(T);
            else
                T = RL(T);
        }
    } else if (x < T->Data) {
        // 插入到左子树
        T->Left = Insert(T->Left, x);
        if ((High(T->Left) - High(T->Right)) == 2) {
            // 左子树高度大于右子树，需要旋转
            if (x < T->Left->Data) T = RR(T);
            else T = LR(T);
        }
    }
    return T;
}

int main() {
    int n, x;
    AVLTree T = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        T = Insert(T, x);
    }
    printf("%d", T->Data);  // 输出根节点的数据
    return 0;
}
