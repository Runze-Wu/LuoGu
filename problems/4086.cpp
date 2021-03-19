#include <bits/stdc++.h>
using namespace std;
int n;
int data[100010];
int sum;
int min_pos[100010];
void read() {
    sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
        sum += data[i];
    }
}
void init() {
    read();
    min_pos[n] = n;
    for (int i = n - 1; i >= 1; i--) {
        min_pos[i] = data[i] < data[min_pos[i + 1]] ? i : min_pos[i + 1];
    }
}
void work() {
    sum -= data[1];
    long long point = (long long)(sum - data[min_pos[2]]);
    int term = n - 2;
    vector<int> res(1, 1);
    for (int k = 2; k <= n - 2; k++) {
        sum -= data[k];
        long long cur_point = (long long)(sum - data[min_pos[k + 1]]);
        // printf("point %lld k %d\n", cur_point, k);
        if (cur_point * term > point * (n - k - 1)) {
            point = cur_point;
            term = n - k - 1;
            res.clear();
            res.push_back(k);
        } else if (cur_point * term == point * (n - k - 1)) {
            res.push_back(k);
        }
    }
    for (auto num : res) {
        printf("%d\n", num);
    }
}
int main() {
    init();
    work();
    return 0;
}