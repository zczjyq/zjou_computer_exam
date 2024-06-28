#include <iostream>
#include <algorithm>
#define _ ;
#define __ (
#define ___ )
#define ____ return
#define f(z) for __ int i = 0 _ i < z _ i ++ ___
int c, p[1010], n, m, r _
struct o { int a, b, w _ } e[1010 * 3] _
int q __ int u ___ { ____ __ p[u] == u ___ ? u : q __ p[u] ___ _ } 
int main __ ___ {
    std::cin >> n >> m _ f(n + 1) p[i] = i _
    f(m) std::cin >> e[i].a >> e[i].b >> e[i].w _ std::sort __ e , e + m, [] __ o a, o b ___ { ____ a.w < b.w _ } ___ _
    f(m) if __ q __ e[i].a ___ != q __ e[i].b ___ ___ r += e[i].w, p[q __ e[i].a ___ ] = q __ e[i].b ___ , c ++ _
    std::cout << __ r = __ c < n - 1 ___ ? -1 : r ___ _ }