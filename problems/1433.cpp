#include <bits/stdc++.h>
using namespace std;
int n;
struct point {
    double x;
    double y;
} points[20], ori{0, 0};
bool used[20] = {0};
double dp[(1 << 15) + 15][20] = {0};
double res = 1e12;
void read() {
    scanf("%d", &n);
    double x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &x, &y);
        points[i] = {x, y};
    }
}
double distance(struct point *a, struct point *b) { return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)); }
void dfs(struct point *begin, int num, double ans, int ww) {
    if (num == n) {
        res = min(res, ans);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int xb = ww + (1 << i);
            double dis = distance(begin, &points[i]);
            if (dp[xb][i] && dp[xb][i] <= dis + ans) continue;
            used[i] = 1;
            dp[xb][i] = ans + dis;
            dfs(&points[i], num + 1, dp[xb][i], xb);
            used[i] = 0;
        }
    }
}
void work() {
    dfs(&ori, 0, 0, 0);
    printf("%.2f", res);
}
int main() {
    read();
    work();
    return 0;
}