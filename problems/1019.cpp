#include <bits/stdc++.h>
using namespace std;
int n;
int finalans = 0;
string key[30];
int used[30] = {0};
void read() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> key[i];
    cin >> key[n];
}
int contain(string &a, string &b) {
    int i = a.length() - 1;
    for (; i >= 0; i--) {
        if (a[i] == b[0]) break;
    }
    if (i < 0 || a.length() - i > b.length()) return -1;
    int j = 0;
    for (; j < b.length() && i + j < a.length(); j++) {
        if (a[i + j] != b[j]) return -1;
    }
    return i;
}
void dfs(int choose, int ans) {
    finalans = max(ans, finalans);
    for (int i = 0; i < n; i++) {
        if (used[i] >= 2) continue;
        int index = contain(key[choose], key[i]);

        if (index == -1 || (index == 0 && choose != n)) continue;
        if (choose != n && contain(key[i], key[choose]) == 0) continue;
        // printf("ans %d contain %s %s = %d\n", finalans, key[choose].c_str(), key[i].c_str(), index);
        used[i]++;
        dfs(i, ans + key[i].length() + index - key[choose].length());
        used[i]--;
    }
}
int main() {
    read();
    dfs(n, key[n].length());
    printf("%d\n", finalans);
}