#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

// 定义操作符的优先级
int precedence(char op) {
    switch (op) {
        case '!': return 3;
        case '&': return 2;
        case '|': return 1;
        default: return 0;
    }
}

// 计算两个布尔值的结果
bool applyOp(bool a, bool b, char op) {
    switch (op) {
        case '&': return a && b;
        case '|': return a || b;
        
    }
}

// 检查括号是否匹配
bool areBracketsBalanced(const string& expr) {
    int count = 0;
    for (char c : expr) {
        if (c == '(') count++;
        if (c == ')') count--;
        if (count < 0) return false;
    }
    return count == 0;
}

// 计算布尔表达式的结果
bool evaluate(const string& expression) {
    if (!areBracketsBalanced(expression)) {
        cout<<"表达式中括号数不合法";
        return 0;
    }

    stack<char> ops;
    stack<bool> values;

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];

        if (c == ' ') continue; // 忽略空格

        if (c == '(') {
            ops.push(c);
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();

                if (op == '!') {
                    if (!values.empty()) {
                        bool val = values.top();
                        values.pop();
                        values.push(!val);
                    }
                }
                else {
                    if (values.size() < 2) {
                        break;
                    }
                    bool val2 = values.top(); values.pop();
                    bool val1 = values.top(); values.pop();
                    values.push(applyOp(val1, val2, op));
                }
            }
            if (ops.empty()) {
                cout << "括号失配";
                return 0;
                
            }
            ops.pop(); // 弹出左括号
        }
        else if (c == '!') {
            int notCount = 1;
            while (i + 1 < expression.length() && expression[i + 1] == '!') {
                notCount++;
                i++;
            }
            if (notCount % 2 == 1) {
                ops.push('!');
            }
        }
        else if (c == '&' || c == '|') {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                char op = ops.top();
                ops.pop();

                if (op == '!') {
                    if (!values.empty()) {
                        bool val = values.top();
                        values.pop();
                        values.push(!val);
                    }
                }
                else {
                    if (values.size() < 2) {
                        cout << "非法表达式";
                        return -1;
                    }
                    bool val2 = values.top(); values.pop();
                    bool val1 = values.top(); values.pop();
                    values.push(applyOp(val1, val2, op));
                }
            }
            ops.push(c);
        }
        else if (c == 'V' || c == 'F') {
            values.push(c == 'V');
        }
        
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();

        if (op == '!') {
            if (!values.empty()) {
                bool val = values.top();
                values.pop();
                values.push(!val);
            }
        }
        else {
            if (values.size() < 2) {
                cout<<"非法表达式";
                return -1;
            }
            bool val2 = values.top(); values.pop();
            bool val1 = values.top(); values.pop();
            values.push(applyOp(val1, val2, op));
        }
    }

    

    return values.top();
}

int main() {
    string line;
    int index = 1;

    while (getline(cin, line)) {
        
            bool result = evaluate(line);
            cout << "Expression " << index << ": " << (result ? "V" : "F") << endl;
        
       
        index++;
    }

    return 0;
}
