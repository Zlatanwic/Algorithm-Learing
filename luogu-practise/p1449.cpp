#include <bits/stdc++.h>
#include <string>
using namespace std;

stack<int> num;

int apply(char op, int x, int y) {
    int ans = 0;
    switch (op) {
        case '+':
            ans = x + y;
            break;
        case '-':
            ans = x - y;
            break;
        case '*':
            ans = x * y;
            break;
        case '/':
            if (y != 0) {
                ans = x / y;
            }
            break;
    }
    return ans;
}

int main() {
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            // 读取完整的数字
            int number = 0;
            while (i < str.length() && isdigit(str[i])) {
                number = number * 10 + (str[i] - '0');
                i++;
            }
            i--; // 因为for循环会自动i++，所以这里要减1
            num.push(number);
        } else if (str[i] == '@' || str[i] == '.') {
            continue;
        } else {
            // 遇到运算符，弹出两个数字进行计算
            int y = num.top(); num.pop();
            int x = num.top(); num.pop();
            num.push(apply(str[i], x, y));
        }
    }
    cout << num.top() << endl;
    return 0;
}
