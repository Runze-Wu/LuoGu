#include <bits/stdc++.h>
using namespace std;
long long l;
int n, m;
long long stones[50010];
void read() {
    scanf("%lld%d%d", &l, &n, &m);
    for (int i = 0; i < n; i++) scanf("%lld", &stones[i]);
    stones[n] = l;
}
void init() { read(); }
int needStone(long long step) {
    long long pre = 0;
    int count = 0;
    for (int i = 0; i <= n; i++) {
        while (i <= n && stones[i] - pre < step) {
            count++;
            i++;
        }
        pre = stones[i];
    }
    return count;
}
void work() {
    long long left = 0, right = l;
    long long ans = l;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int need = needStone(mid);
        // printf("mid %lld need %d\n", mid, need);
        if (need <= m) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    init();
    work();
    return 0;
}