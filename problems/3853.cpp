#include <bits/stdc++.h>
using namespace std;
int l, n, k;
int dis[100010];
void read() {
    scanf("%d%d%d", &l, &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &dis[i]);
}
void init() { read(); }
int numNeed(int d) {
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int gap = dis[i] - dis[i - 1];
        if (gap <= d) continue;
        ans += gap / d;
        if (gap % d == 0) ans--;
    }
    return ans;
}
void work() {
    int ans = 0;
    int left = 1, right = l;
    while (left <= right) {
        int mid = (left + right) / 2;
        int need = numNeed(mid);
        if (need <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", ans);
}
int main() {
    init();
    work();
    return 0;
}