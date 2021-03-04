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
int mydp() {
    int dp[20][20] = {0};
    for (int j = 0; j < 20; j++) dp[0][j] = 1;
    for (int i = 1; i < 20; i++) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < 20; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
        }
    }
    return dp[n][0];
}
void work() {
    // printf("%d\n", dfs(n, 0));
    printf("%d\n", mydp());
}
int main() {
    init();
    work();
    return 0;
}