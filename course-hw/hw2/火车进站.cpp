#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

struct mystack {
    char a[N];
    int t = 0;
    void push(char x) { a[++t] = x; }
    char top() { return a[t]; }
    void pop() { t--; }
    int empty() { return t == 0 ? 1 : 0; }
    void clear() { t = 0; }
} st;

int main() {
    string input;
    getline(cin, input);
    string output;
    int len = input.length();

    while (getline(cin, output)) {
        if (output.empty()) break; // 结束输入判断

        st.clear(); // 清空栈
        int count = 0;
        int j = 0;

        for (int i = 0; i < len; i++) {
            st.push(input[i]);
            while (!st.empty() && st.top() == output[j]) {
                j++;
                st.pop();
                count++;
            }
        }

        if (count == len)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
