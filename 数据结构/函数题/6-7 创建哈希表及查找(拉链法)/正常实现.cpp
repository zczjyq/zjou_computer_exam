#include <iostream>
using namespace std;

#define P 13

typedef struct HashNode
{
    int key;
    struct HashNode *next;
} HashNode, *HashTable;

void CreateHash(HashTable HT[], int n);
float ASL(HashTable HT[]);

int main()
{
    int i, n;
    HashTable HT[P];
    for (i = 0; i < P; i++)
        HT[i] = NULL;
    cin >> n;
    CreateHash(HT, n);
    cout << ASL(HT);
    return 0;
}
/* 请在这里填写答案 */

void CreateHash(HashTable HT[], int n)
{
    int hash_table[P]; // 创建一个辅助数组
    int temp;          // 存放余数
    for (int i = 0; i < n; i++)
        cin >> hash_table[i];
    for (int i = 0; i < n; i++)
    {
        temp = hash_table[i] % P; // 求余数
        if (HT[temp] == NULL)
        { // 头为空插头后面
            HT[temp] = (HashTable)malloc(sizeof(HashNode));
            HashTable p = (HashTable)malloc(sizeof(HashNode));
            p->key = hash_table[i];
            HT[temp]->next = p;
            p->next = NULL;
        }
        else
        { // 头不为空找到尾，查到尾后面
            HashTable p = (HashTable)malloc(sizeof(HashNode));
            p = HT[temp];
            while (p->next != NULL)
            {
                p = p->next;
            }
            HashTable q = (HashTable)malloc(sizeof(HashNode));
            q->key = hash_table[i];
            p->next = q;
            q->next = NULL;
        }
    }
}
// 计算平均查找长度
float ASL(HashTable HT[]) {
    double sum = 0, len = 0; // sum记录总步数，len记录有几个元素
    for (int i = 0; i < P; i++) {
        if (HT[i] == NULL)
            continue;
        int cnt = 1;
        HashTable p = (HashTable)malloc(sizeof(HashNode));
        p = HT[i];
        while (p->next != NULL) {
            p = p->next;
            sum += cnt;
            cnt++;
            len++;
        }
    }
    return sum / len; // 总步数除以元素个数也就是平均查找长度
}
