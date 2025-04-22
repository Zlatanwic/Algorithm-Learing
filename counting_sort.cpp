#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int cal_k(vector<int>a){
    if (a.empty()) return 0;
    return *max_element(a.begin(), a.end()) + 1;
}

void counting_sort(vector<int>&a,vector<int>&b,int k)
{
    vector<int> c(k, 0);
    
    // 统计每个元素的出现次数
    for (int num : a) {
        c[num]++;
    }
    
    // 计算前缀和（表示该元素在输出数组中的最后一个位置 +1）
    for (int i = 1; i < k; i++) {
        c[i] += c[i - 1];
    }
    
    // 反向遍历原数组，保证稳定性
    for (int j = a.size() - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];  // 注意要减1
        c[a[j]]--;
    }

}

int main()
{
    vector<int>a={3,1,60,14,2,34,20,54,6};
    vector<int>b(9,0);
    counting_sort(a,b,cal_k(a));
    for(int i=0;i<a.size()-1;i++){
        cout<<b[i]<<' ';
    }
    return 0;
}