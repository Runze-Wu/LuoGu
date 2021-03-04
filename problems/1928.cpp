#include <bits/stdc++.h>
using namespace std;
enum State {
    Intial,
    Letter,
    Int,
};
// Letter '[' -> Int
// Int 'A-Z' -> Letter
bool IsLetter(char c) { return c >= 'A' && c <= 'Z'; }
bool IsInt(char c) { return c >= '0' && c <= '9'; }
bool IsLeftBlock(char c) { return c == '['; }
bool IsRightBlock(char c) { return c == ']'; }
int GetNum(string s) { return atoi(s.c_str()); }
string input;
int point = 0;
string dfs() {
    string res;
    int len = input.size();
    while (point < len) {
        char c = input[point];
        if (IsLetter(c)) {
            int start = point;
            while (point < len && IsLetter(input[point])) {
                res.push_back(input[point]);
                point++;
            }
        } else if (IsLeftBlock(c)) {
            int inner_repeat = 0;
            int start = ++point;
            while (point < len && IsInt(input[point])) {
                inner_repeat = inner_repeat * 10 + input[point] - '0';
                point++;
            }
            string sub = dfs();
            // cout << "get sub " << sub << endl;
            for (int i = 0; i < inner_repeat; i++) res += sub;
        } else if (IsRightBlock(c)) {
            point++;
            return res;
        }
    }
    return res;
}
void work() { cout << dfs() << endl; }
// void work() {
//     string res, curStr, curNum;
//     int point = 0, len = res.length();
//     int deep = 1;
//     State state = Intial;
//     vector<int> repeat;
//     while (point < len) {
//         switch (state) {
//             char c = input[point];
//             case Intial:
//                 if (IsLetter(c)) {
//                     state = Letter;
//                 } else if (IsInt(c)) {
//                     state = Int;
//                 } else if (IsLeftBlock(c)) {
//                     deep++;
//                 }
//                 break;
//             case Letter:
//                 int start = point;
//                 while (point < len && IsLetter(input[point])) {
//                     point++;
//                 }
//                 curStr = res.substr(start, point - start);
//                 point--;
//                 break;
//             case Int:
//                 int start = point;
//                 while (point < len && IsLetter(input[point])) {
//                     point++;
//                 }
//                 repeat.push_back(GetNum(input.substr(start, point - start)));
//                 point--;
//                 break;
//         }
//     }
//     printf("%s\n", res);
// }
int main() {
    cin >> input;
    work();
    return 0;
}