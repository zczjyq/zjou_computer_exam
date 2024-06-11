#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;
struct node{
    int num_house, area;
} nodes[20010];

struct ans{
    int num = 100000, all_people, all_ho, all_area;
    double num_h, area;
}res[10010];
int n, cnt, p[10010], st_a[10010], st_num[10010];
int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

int main() {
    cin >> n;
    for (int i = 0; i < 10010; i ++ ) p[i] = i;
    for (int i = 0; i < n; i ++ ) {
        int num, f, m, k;
        cin >> num >> f >> m >> k;
        s.insert(num);
        int a = find(num);
        for (int j = 0; j < k; j ++ ) {
            int c;
            cin >> c;
            if (c >= 0){
                p[find(c)] = a;
                s.insert(c);
            }
        }
        if (f >= 0) p[find(f)] = a, s.insert(f);
        if (m >= 0) p[find(m)] = a, s.insert(m);
        cin >> nodes[num].num_house >> nodes[num].area;
    }
    for (auto t : s) {
        int a = find(t);
        if (!st_a[a]) {
            st_a[a] = 1;
            st_num[a] = cnt++;
        }
        res[st_num[a]].num = min(res[st_num[a]].num, t);
        res[st_num[a]].all_area += nodes[t].area;
        res[st_num[a]].all_people += 1;
        res[st_num[a]].all_ho += nodes[t].num_house;
    }
    for (int i = 0; i < cnt; i ++ ) {
        res[i].num_h = (double)res[i].all_ho / (double)res[i].all_people;
        res[i].area = (double)res[i].all_area / (double)res[i].all_people;
    }
    sort(res, res + cnt, [](ans a, ans b) {
        if (a.area == b.area) return a.num < b.num;
        return a.area > b.area;
    });
    
    cout << cnt << endl;
    for (int i = 0; i < cnt; i ++ ) printf("%04d %d %.3lf %.3lf\n", res[i].num, res[i].all_people, res[i].num_h, res[i].area);
}