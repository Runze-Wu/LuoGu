#include <bits/stdc++.h>
using namespace std;
int n;
int f[20][20] = {0};
void read() { cin >> n; }
void init() { read(); }
// i 表示操作序列剩余个数，j 表示栈中个数
int dfs(int i, int j) {
    if (f[i][j]) return f[i][j];
    if (i == 0) return 1;
    if (j > 0) f[i][j] += dfs(i, j - 1);
    f[i][j] += dfs(i - 1, j + 1);
    return f[i][j];
}
void work() { printf("%d\n", dfs(n, 0)); }
int main() {
    init();
    work();
    return 0;
}