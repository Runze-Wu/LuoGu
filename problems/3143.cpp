#include <bits/stdc++.h>
using namespace std;
int n, k;
int data[50010];
void read() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &data[i]);
}
void init() {
    read();
    sort(data + 1, data + n + 1);
}
int l[50010], r[50010];
int findFirstSmall(int x) {
    int left = 1, right = n;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] < x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int findFistLarge(int x) {
    int left = 1, right = n;
    int ans = n + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] > x) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

void work() {
    for (int i = 1; i <= n; i++) {
        l[i] = (i - findFirstSmall(data[i] - k));
        r[i] = (findFistLarge(data[i] + k) - i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, l[i - 1] + r[i]);
        l[i] = max(l[i - 1], l[i]);
    }
    printf("%d", ans);
}
int main() {
    init();
    work();
    return 0;
}