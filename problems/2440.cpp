#include <bits/stdc++.h>
using namespace std;
int n, k;
int heights[100010];
void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &heights[i]);
}
int getMax(int *data, int len) {
    int myMax = INT32_MIN;
    for (int i = 0; i < len; i++) myMax = max(myMax, data[i]);
    return myMax;
}
void init() { read(); }
int numGet(int h) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += heights[i] / h;
    }
    return ans;
}
void work() {
    int ans = 0;
    int left = 1, right = getMax(heights, n);
    while (left <= right) {
        int mid = (left + right) / 2;
        int num = numGet(mid);
        if (num >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
}
int main() {
    init();
    work();
    return 0;
}