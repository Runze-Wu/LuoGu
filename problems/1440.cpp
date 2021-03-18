#include <bits/stdc++.h>
using namespace std;
int n, k;
struct ele {
    int data, index;
};

int main() {
    scanf("%d%d", &n, &k);
    deque<ele> myqueue;
    int data;
    for (int i = 0; i < n; i++) {
        while (!myqueue.empty() && myqueue.front().index < i - k) {
            // printf("pop %d\n", myqueue.front().data);
            myqueue.pop_front();
        }
        if (i == 0)
            printf("%d\n", 0);
        else
            printf("%d\n", myqueue.front().data);
        scanf("%d", &data);

        while (!myqueue.empty() && myqueue.back().data >= data) {
            // printf("pop %d\n", myqueue.back().data);
            myqueue.pop_back();
        }
        myqueue.push_back({data, i});
    }
    return 0;
}