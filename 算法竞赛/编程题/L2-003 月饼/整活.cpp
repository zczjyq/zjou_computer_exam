#include <iostream>
#include <algorithm>

using namespace std;
int n;
double v, res;
int idx
struct node {
    double v, w, p;
}nodes[1010];

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i ++ ) cin >> nodes[i].v;
    for (int i = 0; i < n; i ++ ) cin >> nodes[i].w;
    for (int i = 0; i < n; i ++ ) nodes[i].p = nodes[i].w / double(nodes[i].v);
    sort(nodes, nodes + n, [](node a, node b){
        return a.p > b.p;
    });
    while (v && idx < n) {
        if (v >= nodes[idx].v) {
            v -= nodes[idx].v;
            res += nodes[idx].w;
        } else {
            res += nodes[idx].p * v;
            break;
        }
        idx ++ ;
    }
    printf("%.2lf", res);
}