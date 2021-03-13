#include <bits/stdc++.h>
using namespace std;
struct cost {
    int a, b, c;
} trails[100010];
int n, m;
int travel[100010];
void read() {
    cin >> n >> m;
    int start, next;
    scanf("%d", &start);
    for (int i = 1; i < m; i++) {
        scanf("%d", &next);
        if (start < next) {
            travel[start]++;
            travel[next]--;
        } else {
            travel[next]++;
            travel[start]--;
        }
        start = next;
    }
    for (int i = 1; i <= n - 1; i++) {
        scanf("%d%d%d", &trails[i].a, &trails[i].b, &trails[i].c);
    }
}
void init() {
    read();
    for (int i = 1; i <= n - 1; i++) {
        travel[i] += travel[i - 1];
    }
}
long long judge(int index) {
    return min((long long)(travel[index]) * trails[index].b + trails[index].c,
               (long long)(trails[index].a) * travel[index]);
}
void work() {
    long long ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        ans += judge(i);
    }
    printf("%lld", ans);
}
int main() {
    init();
    work();
    return 0;
}