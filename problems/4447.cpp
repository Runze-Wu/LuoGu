#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> mymap;
// bool used[100010] = {0};
void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        mymap[data]++;
    }
}
void init() { read(); }

void work() {
    int ans = INT32_MAX;
    while (!mymap.empty()) {
        auto i = mymap.begin(), j = mymap.begin();
        (*i).second--;
        int t = 1;
        for (j++; j != mymap.end() && (*i).first + 1 == (*j).first && (*j).second > (*i).second; i++, j++) {
            t++;
            (*j).second--;
        }
        i = mymap.begin();
        while (i != mymap.end() && (*i).second == 0) {
            mymap.erase((*i++).first);
        }
        ans = min(ans, t);
    }
    printf("%d", ans);
}
int main() {
    init();
    work();
    return 0;
}