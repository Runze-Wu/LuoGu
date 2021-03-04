#include <bits/stdc++.h>
using namespace std;
int n;
int need[10] = {0};
int maxNeed[2000] = {0};
void read() { cin >> n; }

void init() {
    read();
    need[0] = 6, need[1] = 2, need[2] = 5, need[3] = 5, need[4] = 4;
    need[5] = 5, need[6] = 6, need[7] = 3, need[8] = 7, need[9] = 6;
}
int num_need(int num) {
    int sum = 0;
    if (num == 0) return need[num];
    while (num) {
        sum += need[num % 10];
        num /= 10;
    }
    return sum;
}
void work() {
    int res = 0;
    for (int i = 0; i < 2000; i++) {
        maxNeed[i] = num_need(i);
    }
    for (int i = 0; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            if (maxNeed[i] + maxNeed[j] + maxNeed[i + j] == n - 4) {
                if (i != j) res++;
                res++;
            }
        }
    }
    printf("%d\n", res);
}

int main() {
    init();
    work();
}