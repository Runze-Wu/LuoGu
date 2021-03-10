#include <bits/stdc++.h>
using namespace std;
#define MAXPRINT 3
int n;
int row[15] = {0}, col[15] = {0}, up[30] = {0}, low[30] = {0};
void read() { cin >> n; }
inline bool check(int i, int j) { return col[j] || up[i - j + n] || low[i + j]; }
void printRes() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", row[i]);
    }
    printf("\n");
}
int dfs(int num) {
    static int printNum = 0;
    if (num == n + 1 && printNum < 3) {
        printRes();
        printNum++;
        return 1;
    }
    if (num == n + 1) return 1;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        if (!check(num, j)) {
            row[num] = j;
            col[j] = up[num - j + n] = low[num + j] = 1;
            ans += dfs(num + 1);
            col[j] = up[num - j + n] = low[num + j] = 0;
        }
    }
    return ans;
}
void work() { printf("%d", dfs(1)); }
int main() {
    read();
    work();
    return 0;
}