#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int head, n;
int st[N];
vector <int> unre, re;
struct node {
    int pre, value, next;
} nodes[N];

int main () {
    cin >> head >> n;
    for (int i = 0; i < n; i ++ ) {
        int tnode, tvalue, tnext;
        cin >> tnode >> tvalue >> tnext;
        nodes[tnode].value = tvalue;
        nodes[tnode].next = tnext;
        if (tnext != -1) nodes[tnext].pre = tnode;
    }
    int first = head;
    while (first != -1) {
        if (st[abs(nodes[first].value)] != 1) {
            st[abs(nodes[first].value)] = 1;
            unre.push_back(first);
        } else re.push_back(first);
        first = nodes[first].next;
    }
    for (int i = 0; i < int(unre.size()); i ++ ) 
        if (i != int(unre.size()) - 1) printf("%05d %d %05d\n", unre[i], nodes[unre[i]].value, unre[i + 1]);
        else printf("%05d %d -1\n", unre[i], nodes[unre[i]].value);
    for (int i = 0; i < int(re.size()); i ++ ) 
        if (i != int(re.size()) - 1) printf("%05d %d %05d\n", re[i], nodes[re[i]].value, re[i + 1]);
        else printf("%05d %d -1\n", re[i], nodes[re[i]].value);
}