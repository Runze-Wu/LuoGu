#include <bits/stdc++.h>
using namespace std;
int n, p;
int a[100100], b[100100];
void read() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
}
void init() { read(); }
double powerNeed(double t) {
    double power = 0;
    for (int i = 0; i < n; i++) {
        if (t * a[i] < b[i]) continue;
        power += (t * a[i] - b[i]);
    }
    return power;
}
void work() {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    if (sum <= p) {
        printf("%f\n", double(-1));
        return;
    }
    // printf("%d\n", powerNeed(2.0) <= 2.0 * p);
    double ans = INT32_MIN;
    double left = 0, right = 1e10;
    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        double need = powerNeed(mid);
        // printf("need %f act %f\n", need, mid * p);
        if (need <= mid * p) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.10f", ans);
}
int main() {
    init();
    work();
    return 0;
}