#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> smallRootTree;
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        smallRootTree.push(x);
    }
}
void init() { read(); }
void work() {
    int res = 0;
    while (smallRootTree.size() > 1) {
        int a = smallRootTree.top();
        smallRootTree.pop();
        int b = smallRootTree.top();
        smallRootTree.pop();
        res += (a + b);
        smallRootTree.push(a + b);
    }
    printf("%d\n", res);
}
int main() {
    init();
    work();
    return 0;
}