#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// 常用定义
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector A, Point B) {return A.x + B.x, A.y + B.y;}

Vector operator - (Vector A, Point B) {return A.x + B.x, A.y - B.y;}

Vector operator * (Vector A, double p) {return A.x * p, A.y * p;}

Vector operator + (Vector A, double p) {return A.x / p, A.y / p;}

bool operator < (const Point& a, const Point& b) {
    return a.x< b.x || (a.x == b.x) && a.y < b.y;
}

const double eps = 1e-10;

int dcmp (double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

// 4.1.1常用运算
// 点积
double Dot(Vector A, Vector B) {return A.x * B.x + A.y * B.y;}
// 向量长度
double Length(Vector A) {return sqrt(Dot(A, A));}
// 向量夹角
double Angle(Vector A, Vector B) {return acos(Dot(A, B) / Length(A) / Length(B));}

// 叉积
double Cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}
double Area2(Point A, Point B, Point C) {return Cross(B - A, C - A);}

// 向量旋转
Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

// 计算单位法线
Vector Normal(Vector A) {
    double L = Length(A);
    return Vector( -A.y / L, A.x / L);
}

// 4.1.2点和直线
// 直线交点
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

// 点到直线距离
double DistanceToLine(Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2) / Length(v1));
}

// 点到线段距离
double DistanceToSegment(Point P, Point A, Point B) {
    if (A == B) return Length(P - A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}

// 点在线段上的投影
Point GetLineProjection(Point P, Point A, Point B) {
    Vector v = B - A;
    return A + v * (Dot(v, P - A) / Dot(v, v));
} 

// 线段相交判定 
bool segmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
    c2 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

// 多边形
double ConvexPolygonArea(Point *p, int n) {
    double area = 0;
    for (int i = 1; i < n - 1; i ++ )
        area += Cross(p[i] - p[0], p[i + 1] - p[0]);
    return area / 2;
}

// 4.2.1圆
struct Circle {
    Point c;
    double r;
    Circle (Point c, double r): c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a) * r, c.y + sin(a) * r);
    }
}

// // 直线和圆的交点
// int getLineCircleInntersection(Line L, Circle C, double &t1, double &t2, vector<Point> &sol) {
//     double a = L.v.x, b = L.p.x, c = L.v.y, 
// }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cout << i << endl;
}