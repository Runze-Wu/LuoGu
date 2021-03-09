#include <bits/stdc++.h>
using namespace std;
int n, m;
int nums[100010];
void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
}
void init() { read(); }
int partionNum(int gap) {
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > gap) return m + 1;
        while (i < n && nums[i] + sum <= gap) {
            sum += nums[i++];
        }
        ans++;
        i--;
        sum = 0;
    }
    return ans;
}
void work() {
    int ans = INT32_MAX;
    int left = 0, right = 1e9;
    while (left <= right) {
        int mid = (left + right) / 2;
        int part = partionNum(mid);
        // printf("mid %d part %d\n", mid, part);
        if (part <= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("%d", ans);
}
int main() {
    init();
    work();
    return 0;
}