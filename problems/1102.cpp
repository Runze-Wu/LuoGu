#include <bits/stdc++.h>
using namespace std;
int n, c;
int data[200010];
unordered_map<int, int> mycount;
void read() {
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        mycount[data[i]]++;
    }
}
void init() {
    read();
    sort(data, data + n);
}
void work() {
    int left = 0;
    long long ans = 0;
    while (left < n) {
        if (mycount[data[left] + c]) {
            ans += ((long long)mycount[data[left]] * mycount[data[left] + c]);
        }
        left++;
        while (left < n && data[left] == data[left - 1]) {
            left++;
        }
    }
    printf("%lld", ans);
}
int main() {
    init();
    work();
    return 0;
}