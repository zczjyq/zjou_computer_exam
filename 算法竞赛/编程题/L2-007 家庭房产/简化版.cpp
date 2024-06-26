#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int n, p[10010], st_num[10010], cnt, num, f, m, k, u;
struct node {int num_ho, num_area; } nodes[10010];
struct ans {
    int min_num = 100000, num_people, num_area, num_ho;
    double avg_ho, avg_area;
} res[10010];
set<int> s;
int find(int u) { return p[u] == u ? u : p[u] = find(p[u]);}
int main() {
    cin >> n;
    for (int i = 1; i < 10010; i ++ ) p[i] = i;
    for (int i = 0; i < n; i ++ ) {
        cin >> num >> f >> m >> k;
        s.insert(num);
        for (int j = 0; j < k; j ++ ) {
            cin >> u;
            s.insert(u);
            p[find(u)] = find(num);
        }
        if (f != -1) p[find(f)] = find(num), s.insert(f);
        if (m != -1) p[find(m)] = find(num), s.insert(m);
        cin >> nodes[num].num_ho >> nodes[num].num_area;
    }
    for (int t : s) {
        if (st_num[find(t)] == 0) st_num[find(t)] = ++ cnt;
        res[st_num[find(t)]].min_num = min(res[st_num[find(t)]].min_num, t);
        res[st_num[find(t)]].num_people ++;
        res[st_num[find(t)]].num_ho += nodes[t].num_ho;
        res[st_num[find(t)]].num_area += nodes[t].num_area;
    }
    for (int i = 1; i <= cnt; i ++ ) res[i].avg_area = (double)res[i].num_area / (double)res[i].num_people, res[i].avg_ho = (double)res[i].num_ho / (double)res[i].num_people;
    sort(res + 1, res + n + 1, [](ans a, ans b) {
        if (a.avg_area == b.avg_area) return a.min_num < b.min_num;
        return a.avg_area > b.avg_area;});
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i ++ ) printf("%04d %d %.3lf %.3lf\n", res[i].min_num, res[i].num_people, res[i].avg_ho, res[i].avg_area);
}