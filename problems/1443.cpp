#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int steps[410][410] = {-1};
struct jump {
    int move_x, move_y;
} kinds[] = {{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};
#define pos(row, col) steps[row][col]
#define pos_legal(row, col) row <= n&& row >= 1 && col <= m&& col >= 1
#define redun_steps(row, col, step) (pos_legal(row, col)) && (steps[row][col] == -1 || steps[row][col] > step)
void read() { scanf("%d%d%d%d", &n, &m, &x, &y); }
void init() {
    read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) pos(i, j) = -1;
}
void dfs(int s_x, int s_y, int step) {
    if (step > 200) return;
    if (!redun_steps(s_x, s_y, step)) return;
    pos(s_x, s_y) = step;
    for (int i = 0; i < 8; i++) {
        int next_x = s_x + kinds[i].move_x, next_y = s_y + kinds[i].move_y;
        if (redun_steps(next_x, next_y, step + 1)) {
            dfs(next_x, next_y, step + 1);
        }
    }
}
void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%-5d", pos(i, j));
        }
        printf("\n");
    }
}
int main() {
    init();
    dfs(x, y, 0);
    print();
    return 0;
}
