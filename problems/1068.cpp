#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> info;
void read() {
    scanf("%d%d", &n, &m);
    int id, grade;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &id, &grade);
        info.push_back({id, grade});
    }
}
void work() {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    };
    sort(info.begin(), info.end(), cmp);
    int num = int(floor(1.5 * m));

    int min_grade = info.at(num - 1).second;
    int count = 0;
    for (const auto& stu : info) {
        if (stu.second < min_grade) break;
        count++;
    }
    printf("%d %d\n", min_grade, count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", info[i].first, info[i].second);
    }
}
int main() {
    read();
    work();
    return 0;
}