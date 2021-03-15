#include <bits/stdc++.h>
using namespace std;
int n, m;
int colors[100010];
int numbers[100010];
int groups[100010][2];
int sum[100010][2];
void read() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &numbers[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &colors[i]);
}
void init() {
    read();
    for (int i = 1; i <= n; i++) {
        groups[colors[i]][i % 2]++;
        sum[colors[i]][i % 2] = (sum[colors[i]][i % 2] + numbers[i]) % 10007;
    }
}
void work() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + i * ((numbers[i] * (groups[colors[i]][i % 2] - 2)) % 10007 + sum[colors[i]][i % 2])) % 10007;
    }
    printf("%d", ans);
}
int main() {
    init();
    work();
    return 0;
}