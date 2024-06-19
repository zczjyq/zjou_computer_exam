// https://www.acwing.com/file_system/file/content/whole/index/content/3553/

#include<iostream>

using namespace std;

const int N = 1010;
int n, m;
int v[N], w[N];
int f[N][N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++ ){ 
            if (j < v[i]) f[i][j] = f[i - 1][j];
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }
    cout << f[n][m] << endl;
}
