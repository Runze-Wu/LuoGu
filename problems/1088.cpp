#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ori;
void read() {
    scanf("%d%d", &n, &m);
    ori.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &ori[i]);
}
void init() { read(); }
void work() {
    if (ori.size() == 0) return;
    for (int i = 0; i < m; i++) next_permutation(ori.begin(), ori.end());
    printf("%d", ori[0]);
    for (int i = 1; i < n; i++) printf(" %d", ori[i]);
}

int main() {
    init();
    work();
    return 0;
}