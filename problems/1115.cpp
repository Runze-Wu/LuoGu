#include <bits/stdc++.h>
using namespace std;
int n;
int data[200010];
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
}
int dp[200010];
void init() {
    read();
    dp[0] = data[0];
}
void work() {
    int res = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(data[i], data[i] + dp[i - 1]);
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
}
int main() {
    init();
    work();
    return 0;
}