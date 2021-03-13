#include <bits/stdc++.h>
using namespace std;
int n, m;
int data[1010][1010] = {0};

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x_1, y_1, x_2, y_2;
        scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
        for (int row = x_1; row <= x_2; row++) {
            data[row][y_1]++;
            data[row][y_2 + 1]--;
        }
    }
}
void work() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            data[i][j] += data[i][j - 1];
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}
int main() {
    read();
    work();
    return 0;
}