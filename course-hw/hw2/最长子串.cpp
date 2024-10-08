#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

struct mystack {
    int a[N];
    int t = 0;
    void push(int x) { a[++t] = x; }
    int top() { return a[t]; }
    void pop() { t--; }
    int empty() { return t == 0 ? 1 : 0; }
    void clear() { t = 0; }
} st;

int main() {
    string str;
    getline(cin, str);
    int len = str.length();
    int max_length = 0;
    int start_index = 0;
    st.clear(); // 清空栈

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty() && str[st.top()] == '(') {
                st.pop();
                int current_length = 0;
                if (st.empty()) {
                    current_length = i + 1;
                } else {
                    current_length = i - st.top();
                }
                if (current_length > max_length) {
                    max_length = current_length;
                    start_index = st.empty() ? 0 : st.top() + 1;
                }
            } else {
                st.push(i);
            }
        }
    }

    cout << max_length << ' ' << start_index << endl;
    return 0;
}
