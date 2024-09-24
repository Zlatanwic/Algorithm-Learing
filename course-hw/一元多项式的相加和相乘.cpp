#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
 
using namespace std;
 
// 定义项结构体
struct Term {
    int coefficient;
    int exponent;
};
 
// 加法函数
vector<Term> addPolynomials(const vector<Term>& poly1, const vector<Term>& poly2) {
    vector<Term> result;
    size_t i = 0, j = 0;
    while (i < poly1.size() && j < poly2.size()) {
        if (poly1[i].exponent == poly2[j].exponent) {
            int sumCoeff = poly1[i].coefficient + poly2[j].coefficient;
            if (sumCoeff != 0) {
                result.push_back({sumCoeff, poly1[i].exponent});
            }
            ++i;
            ++j;
        } else if (poly1[i].exponent < poly2[j].exponent) {
            result.push_back(poly1[i]);
            ++i;
        } else {
            result.push_back(poly2[j]);
            ++j;
        }
    }
    while (i < poly1.size()) {
        result.push_back(poly1[i]);
        ++i;
    }
    while (j < poly2.size()) {
        result.push_back(poly2[j]);
        ++j;
    }
    return result;
}
 
// 乘法函数
vector<Term> multiplyPolynomials(const vector<Term>& poly1, const vector<Term>& poly2) {
    map<int, int> resultMap;
    for (const auto& term1 : poly1) {
        for (const auto& term2 : poly2) {
            int newCoeff = term1.coefficient * term2.coefficient;
            int newExp = term1.exponent + term2.exponent;
            resultMap[newExp] += newCoeff;
        }
    }
    vector<Term> result;
    for (const auto& entry : resultMap) {
        if (entry.second != 0) {
            result.push_back({entry.second, entry.first});
        }
    }
    sort(result.begin(), result.end(), [](const Term& a, const Term& b) {
        return a.exponent < b.exponent;
    });
    return result;
}
 
// 格式化输出
void printPolynomial(const vector<Term>& poly) {
    if (poly.empty()) {
        return;
    }
    for (const auto& term : poly) {
        cout << term.coefficient << " " << term.exponent << " ";
    }
    cout << endl;
}
 
int main() {
    int m, n, operation;
    cin >> m;
    vector<Term> poly1(m);
    for (int i = 0; i < m; ++i) {
        cin >> poly1[i].coefficient >> poly1[i].exponent;
    }
    cin >> n;
    vector<Term> poly2(n);
    for (int i = 0; i < n; ++i) {
        cin >> poly2[i].coefficient >> poly2[i].exponent;
    }
    cin >> operation;
 
    if (operation == 0) {
        auto resultAdd = addPolynomials(poly1, poly2);
        printPolynomial(resultAdd);
    } else if (operation == 1) {
        auto resultMul = multiplyPolynomials(poly1, poly2);
        printPolynomial(resultMul);
    } else if (operation == 2) {
        auto resultAdd = addPolynomials(poly1, poly2);
        auto resultMul = multiplyPolynomials(poly1, poly2);
        printPolynomial(resultAdd);
        printPolynomial(resultMul);
    }
 
    return 0;
}
