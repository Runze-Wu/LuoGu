#include <bits/stdc++.h>
using namespace std;
string N;
int k;
bool deleteFlag[260] = {0};
void print() {
    int i = 0;
    for (; i < N.length(); i++) {
        if (!deleteFlag[i] && N[i] != '0') break;
    }
    if (i == N.length()) printf("0");
    for (; i < N.length(); i++) {
        if (!deleteFlag[i]) printf("%c", N[i]);
    }
}
void work() {
    int count = 0, index = 0;
    if (k >= N.length()) N = "";
    int len = N.length();
    for (; count < k && index < len;) {
        while (index < len && deleteFlag[index]) index++;
        int curMax = index;
        int j = index + 1;
        for (; j < len; j++) {
            if (deleteFlag[j]) continue;
            if (N[j] < N[curMax]) break;
            curMax = j;
        }
        deleteFlag[curMax] = 1;
        // cout << "delete " << curMax << " " << N[curMax] << endl;
        // if (count == 1) break;
        index = 0;
        count++;
    }
    print();
}

int main() {
    cin >> N >> k;
    // cout << N << k << endl;
    work();
    return 0;
}