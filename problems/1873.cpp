#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<int> heights;
void read() {
    scanf("%d%lld", &n, &m);
    heights.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
}
void init() { read(); }

long long getRes(int height) {
    long long res = 0;
    for (auto x : heights) {
        if (x > height) res += x - height;
    }
    return res;
}
void work() {
    int left = 0, right = *max_element(heights.begin(), heights.end()), ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long res = getRes(mid);
        // printf("res %lld  mid %d pos %d\n", res, mid, pos);
        if (res >= m) {
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