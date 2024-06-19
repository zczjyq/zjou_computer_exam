#include <iostream>

using namespace std;

int n;
struct point{
    int x, y;
};
point a, b, c, d;

int cross(point O, point A, point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool check(point a, point b, point c, point d) {
    // 快速排斥实验
    if (max(a.x, b.x) < min(c.x, d.x) || 
        max(a.y, b.y) < min(c.y, d.y) || 
        max(c.x, d.x) < min(a.x, b.x) || 
        max(c.y, d.y) < min(a.y, b.y)) {
            return false;
        }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        check(a, b, c, d);
    }
}