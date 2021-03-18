#include <bits/stdc++.h>
using namespace std;
int n, k;
struct ele {
    int data, index;
};

int main() {
    scanf("%d%d", &n, &k);
    vector<int> res1, res2;
    deque<ele> myqueue, myqueue2;
    int data;
    for (int i = 0; i < n; i++) {
        while (!myqueue.empty() && myqueue.front().index <= i - k) {
            // printf("pop %d\n", myqueue.front().data);
            myqueue.pop_front();
        }
        while (!myqueue2.empty() && myqueue2.front().index <= i - k) {
            // printf("pop %d\n", myqueue2.front().data);
            myqueue2.pop_front();
        }
        scanf("%d", &data);

        while (!myqueue.empty() && myqueue.back().data <= data) {
            // printf("pop %d\n", myqueue.back().data);
            myqueue.pop_back();
        }
        myqueue.push_back({data, i});
        while (!myqueue2.empty() && myqueue2.back().data >= data) {
            // printf("pop %d\n", myqueue2.back().data);
            myqueue2.pop_back();
        }
        myqueue.push_back({data, i});
        myqueue2.push_back({data, i});

        if (i >= k - 1) {
            res1.push_back(myqueue.front().data);
            res2.push_back(myqueue2.front().data);
        }
    }
    for (auto num : res2) {
        printf("%d ", num);
    }
    printf("\n");
    for (auto num : res1) {
        printf("%d ", num);
    }
    return 0;
}