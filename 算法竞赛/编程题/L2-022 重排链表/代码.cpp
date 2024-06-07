#include <iostream>

using namespace std;

struct node {
    int pre, num, next;
} nodes[100010];
int head, back, n, j;

int main() {
    cin >> head >> n;
    for (int i = 0; i < n; i ++ ) {
        int tnode, tnum, tnext;
        cin >> tnode >> tnum >> tnext;
        nodes[tnode].num = tnum;
        nodes[tnode].next = tnext;
        nodes[tnext].pre = tnode;
        if (tnext == -1) back = tnode;
    }
    int first = head;
    while (first != -1) {
        first = nodes[first].next;
        j ++ ;
    }
    n = j;
    while (n) {
        if (n - 1 == 0) {
            printf("%05d %d -1\n", back, nodes[back].num);
            break;
        }
        printf("%05d %d %05d\n", back, nodes[back].num, head);
        back = nodes[back].pre;
        if (n - 2 == 0) {
            printf("%05d %d -1\n", head, nodes[head].num);
            break;
        }
        printf("%05d %d %05d\n", head, nodes[head].num, back);
        head = nodes[head].next;
        n -= 2;
    }
}