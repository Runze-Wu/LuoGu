#include <bits/stdc++.h>
using namespace std;
int n;
struct mypos {
    int left, right;
} pos[20010];
void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pos[i].left, &pos[i].right);
    }
}
void init() {
    read();
    auto cmp = [](const mypos &a, const mypos &b) {
        if (a.left != b.left) return a.left < b.left;
        return a.right < b.right;
    };
    sort(pos, pos + n, cmp);
}

void work() {
    auto contain = [](const mypos &a, const mypos &b) { return b.left <= a.right; };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        mypos curpos{pos[i].left, pos[i].right};
        int j = i + 1;
        while (j < n && contain(curpos, pos[j])) {
            curpos.right = max(pos[j].right, curpos.right);
            j++;
        }
        i = j - 1;
        ans += (curpos.right - curpos.left);
    }
    printf("%d", ans);
}
int main() {
    init();
    work();
    return 0;
}