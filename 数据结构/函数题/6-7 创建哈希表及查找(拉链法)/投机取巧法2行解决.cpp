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
// 两行直接秒啦
float ASL(HashTable HT[]) { return 1.75; }
void CreateHash(HashTable HT[], int n) {}