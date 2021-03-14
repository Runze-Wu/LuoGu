#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int val[1010][1010];
int sum[1010][1010];
int dp[1010][1010];
void read() {
    scanf("%d%d%d", &n, &m, &c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &val[i][j]);
        }
    }
}
void init() {
    read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
        }
    }
}
void work() {
    int ans = INT32_MIN, x, y;
    for (int i = 1; i <= n - c + 1; i++) {
        for (int j = 1; j <= m - c + 1; j++) {
            int area = sum[i + c - 1][j + c - 1] - sum[i + c - 1][j - 1] - sum[i - 1][j + c - 1] + sum[i - 1][j - 1];
            // printf("x %d y %d  area %d\n", i, j, area);
            if (area > ans) {
                ans = area;
                x = i, y = j;
            }
        }
    }
    printf("%d %d", x, y);
}
int main() {
    init();
    work();
    return 0;
}