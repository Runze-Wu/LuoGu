#include <bits/stdc++.h>
using namespace std;

int p, k, s;
string input = "0", dict[10];
int dp[210][50], sum[210][210];
void read() {
    cin >> p >> k;
    for (int i = 0; i < p; i++) {
        string temp;
        cin >> temp;
        input.append(temp);
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> dict[i];
    }
}
bool check(int l, int r) {
    string x = input.substr(l, r - l + 1);
    for (int i = 0; i < s; i++) {
        if (x.find(dict[i]) == 0) return true;
    }
    return false;
}
void init() {
    read();

    for (int i = 20 * p; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            sum[j][i] = sum[j + 1][i];
            if (check(j, i)) sum[j][i]++;
        }
    }
}
void work() {
    dp[0][0] = 0;
    int len = 20 * p;
    for (int i = 1; i <= k; i++) dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    for (int i = 1; i <= len; i++) dp[i][1] = sum[1][i];
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= k && j < i; j++) {
            for (int r = j; r < i; r++) {
                dp[i][j] = max(dp[i][j], dp[r][j - 1] + sum[r + 1][i]);
            }
        }
    }
    cout << dp[len][k] << endl;
}
int main() {
    init();
    work();

    return 0;
}