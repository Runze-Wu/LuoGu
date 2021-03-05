#include <bits/stdc++.h>
using namespace std;
int n;
#define maxN 100010
string dp[5010];
string HighPreSum(string a, string b) {
    int res_a[maxN] = {0}, res_b[maxN] = {0}, res_c[maxN] = {0};
    int n = a.length(), m = b.length();
    for (int i = 0; i < n; i++) {
        res_a[i] = a[n - i - 1] - '0';
    }
    for (int i = 0; i < m; i++) {
        res_b[i] = b[m - i - 1] - '0';
    }
    for (int i = 0; i < n || i < m; i++) {
        int add = res_c[i] + res_a[i] + res_b[i];
        res_c[i] = add % 10;
        res_c[i + 1] = add / 10;
    }
    int j = max(n, m);
    for (; j > 0; j--) {
        if (res_c[j] != 0) break;
    }
    string res;
    for (; j >= 0; j--) res.push_back(res_c[j] + '0');
    return res;
}
// 4: 1 1 1 1,1 2 1,1 1 2,2 1 1,2,2
string dpSol() {
    dp[0] = "0", dp[1] = "1", dp[2] = "2";
    for (int i = 3; i <= n; i++) dp[i] = HighPreSum(dp[i - 1], dp[i - 2]);
    return dp[n];
}
int dfs(int x) {
    if (x <= 2) return x;
    return dfs(x - 1) + dfs(x - 2);
}
void work() {
    printf("%s\n", dpSol().c_str());
    // printf("%d\n", dfs(n));
}
int main() {
    cin >> n;
    work();
    return 0;
}