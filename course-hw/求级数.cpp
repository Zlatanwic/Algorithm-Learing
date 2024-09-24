#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
string add(const string& a, const string& b) {
    string result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
 
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
 
    reverse(result.begin(), result.end());
    return result;
}
 
 
string multiply(const string& a, const string& b) {
    vector<int> result(a.size() + b.size(), 0);
 
    for (int i = a.size() - 1; i >= 0; --i) {
        for (int j = b.size() - 1; j >= 0; --j) {
            result[i + j + 1] += (a[i] - '0') * (b[j] - '0');
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
 
    string res;
    for (int num : result) {
        if (!(res.empty() && num == 0)) {
            res.push_back(num + '0');
        }
    }
 
    return res.empty() ? "0" : res;
}
 
 
string calculate_series(int N, int A) {
    string result = "0";
    string current_power = "1";
 
    for (int i = 1; i <= N; ++i) {
        current_power = multiply(current_power, to_string(A));
        string term = multiply(current_power, to_string(i));
        result = add(result, term);
    }
 
    return result;
}
 
int main() {
    int N, A;
    while (cin >> N >> A) {
        string result = calculate_series(N, A);
        cout << result << endl;
    }
 
    return 0;
}
