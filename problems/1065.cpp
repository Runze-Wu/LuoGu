#include <bits/stdc++.h>
using namespace std;
int m, n;
// 工件安排顺序
int order[400];
// 每个工件安排到的工序数
int step[20] = {0};
// 每个工件每个工序的机器号
int machine[20][20];
// 每个工件每个工序的时间
int cost[20][20];
// 每个工件上次加工完成的时间
int finished[20] = {0};
// 每个机器在该时间是否空闲
int idle[20][100001] = {0};
void read() {
    cin >> m >> n;
    for (int i = 0; i < n * m; i++) cin >> order[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> machine[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> cost[i][j];
}
void init() {
    read();
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        int cur_staff = order[i] - 1;
        int cur_machine = machine[cur_staff][step[cur_staff]];
        int cur_cost = cost[cur_staff][step[cur_staff]];
        // printf("now:%d step:%d cost:%d machine:%d\n", cur_staff, step[cur_staff], cur_cost, cur_machine);
        int free_time = 0;
        for (int j = finished[cur_staff] + 1;; j++) {
            if (idle[cur_machine][j] == 0)
                free_time++;
            else
                free_time = 0;
            if (free_time == cur_cost) {
                // printf("j: %d\n", j);
                for (int z = j - cur_cost + 1; z <= j; z++) idle[cur_machine][z] = 1;
                finished[cur_staff] = j;
                step[cur_staff]++;
                ans = max(j, ans);
                break;
            }
        }
    }
    printf("%d\n", ans);
}
void work() {}
int main() {
    init();
    work();
    return 0;
}