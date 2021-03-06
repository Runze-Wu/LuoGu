#include <bits/stdc++.h>
using namespace std;
vector<pair<int, double>> CV_list;
int n, t;
void read() {
    scanf("%d%d", &n, &t);
    int c, v;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &c, &v);
        CV_list.push_back({c, double(v) / double(c)});
    }
}
void work() {
    auto cmp = [](const pair<int, double> &a, const pair<int, double> &b) { return a.second > b.second; };
    sort(CV_list.begin(), CV_list.end(), cmp);
    double res = 0;
    for (auto cv : CV_list) {
        if (cv.first >= t) {
            res += t * cv.second;
            break;
        } else {
            res += cv.first * cv.second;
            t -= cv.first;
        }
    }
    printf("%.2f\n", res);
}
int main() {
    read();
    work();
    return 0;
}