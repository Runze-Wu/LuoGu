#include <bits/stdc++.h>
using namespace std;
int n, k;
int data[5000000];
void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &data[i]);
}
void my_swap(int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}
int find_k_pos(int l, int r, int k) {
    // printf("l %d r %d\n", l, r);
    if (l > r) return -1;
    int split = l, key = data[l];
    for (int i = l + 1; i <= r; i++) {
        if (key > data[i]) my_swap(++split, i);
    }
    if (split != l) my_swap(split, l);
    if (split == k)
        return split;
    else if (split < k) {
        return find_k_pos(split + 1, r, k);
    } else {
        return find_k_pos(l, split - 1, k);
    }
}

void work() { printf("%d\n", data[find_k_pos(0, n - 1, k)]); }
int main() {
    read();
    work();
    return 0;
}