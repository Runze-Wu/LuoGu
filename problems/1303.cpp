#include <bits/stdc++.h>
using namespace std;
#define maxN 4001
string HighPreMultiply(string a, string b) {
    int res_a[maxN] = {0}, res_b[maxN] = {0}, res_c[maxN] = {0};
    int n = a.length(), m = b.length();
    for (int i = 0; i < n; i++) {
        res_a[i] = a[n - i - 1] - '0';
    }
    for (int i = 0; i < m; i++) {
        res_b[i] = b[m - i - 1] - '0';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mul = res_c[i + j] + (res_a[i] * res_b[j]);
            res_c[i + j] = mul % 10;
            res_c[i + j + 1] += mul / 10;
        }
    }
    int j = n + m;
    for (; j > 0; j--) {
        if (res_c[j] != 0) break;
    }
    string res;
    for (; j >= 0; j--) res.push_back(res_c[j] + '0');
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << HighPreMultiply(a, b) << endl;
    return 0;
}