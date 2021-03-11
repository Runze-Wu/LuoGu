#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int steps[210];
int counts[210];
void read() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &steps[i]);
}
void init() {
    read();
    for (int i = 1; i <= n; i++) counts[i] = -1;
}
void work() {
    queue<int> myq, nextq;
    myq.push(a);
    counts[a] = 0;
    while (!myq.empty()) {
        int cur = myq.front();
        int count = counts[cur];
        if (cur == b) {
            break;
        }
        myq.pop();
        if (cur + steps[cur] <= n && counts[cur + steps[cur]] == -1) {
            counts[cur + steps[cur]] = count + 1;
            myq.push(cur + steps[cur]);
        }
        if (cur - steps[cur] >= 1 && counts[cur - steps[cur]] == -1) {
            counts[cur - steps[cur]] = count + 1;
            myq.push(cur - steps[cur]);
        }
    }
    printf("%d\n", counts[b]);
}
int main() {
    init();
    work();
    return 0;
}