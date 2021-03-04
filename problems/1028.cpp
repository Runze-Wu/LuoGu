#include <bits/stdc++.h>
using namespace std;
int n;
int res[1010] = {0};
void read() { cin >> n; }
void init() { read(); }

int dfs(int x) {
    if (res[x]) return res[x];
    res[x] = 1;
    for (int i = 1; i <= x / 2; i++) res[x] += dfs(i);
    return res[x];
}
void work() { printf("%d\n", dfs(n)); }
int main() {
    init();
    work();
    return 0;
}