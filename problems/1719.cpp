#include <bits/stdc++.h>
using namespace std;
int n;
int val[130][130];
int sum[130][130];
int maxPos[130][130];
void read() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &val[i][j]);
        }
    }
}
void init() {
    read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + val[i][j];
        }
    }
}
void work() {
    int ans = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                for (int pos = i; pos <= n; pos++) {
                    int area = sum[pos][k] - sum[pos][j - 1] - sum[i - 1][k] + sum[i - 1][j - 1];
                    ans = max(area, ans);
                    // printf("(%d %d) (%d %d) area %d\n", i, j, pos, k, area);
                }
            }
        }
    }
    printf("%d\n", ans);
}
int main() {
    init();
    work();
    return 0;
}