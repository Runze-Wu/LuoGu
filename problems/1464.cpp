#include <bits/stdc++.h>
using namespace std;
int res[21][21][21] = {0};
int dfs(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);
    if (res[a][b][c]) return res[a][b][c];
    if (a < b && b < c)
        res[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    else
        res[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    return res[a][b][c];
}
int main() {
    long long a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %d\n", a, b, c, dfs(a, b, c));
    }
}