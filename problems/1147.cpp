#include <bits/stdc++.h>
using namespace std;
int m;
int main() {
    scanf("%d", &m);
    int sum = 3;
    for (int i = 1, j = 2; i <= m / 2;) {
        if (sum == m) {
            printf("%d %d\n", i, j);
            sum -= i;
            i++;
        } else if (sum > m) {
            sum -= i;
            i++;
        } else {
            sum += (++j);
        }
    }
    return 0;
}