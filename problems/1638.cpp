#include <bits/stdc++.h>
using namespace std;
int n, m;
int data[1000010];
int mycount[2010];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
    }
    int num = 0;
    int i = 1, j = 1, left = -1, right = n + 1;
    while (true) {
        while (j <= n && num < m) {
            j++;
            mycount[data[j - 1]]++;
            if (mycount[data[j - 1]] == 1) num++;
        }
        if (num < m) break;
        if (right - left > j - 1 - i) {
            right = j - 1;
            left = i;
        }
        i++;
        mycount[data[i - 1]]--;
        if (mycount[data[i - 1]] == 0) num--;
        // printf("%d %d\n", i, j);
    }
    printf("%d %d", left, right);
    return 0;
}