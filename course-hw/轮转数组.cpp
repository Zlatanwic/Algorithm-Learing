#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long>v1(n, 0);
    for (long long i = 0; i < n; i++)
        cin >> v1[i];
    vector<long long >v2(n, 0);
    for (long long  i = 0; i < n; i++) {
        v2[(i + k) % n] = v1[i];
    }
    for (long long t = 0; t < n; t++)
        cout << v2[t]<<' ';
    return 0;
}
