#include <bits/stdc++.h>
using namespace std;
int n;
int a[100] = {0};
bool b[100] = {0};
void print() {
    for (int i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
}
void dfs(int x) {
    if (x == n) {
        print();
    } else {
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                b[i] = true, a[x] = i;
                dfs(x + 1);
                b[i] = false;
            }
        }
    }
}
int main() {
    cin >> n;
    dfs(0);
    return 0;
}