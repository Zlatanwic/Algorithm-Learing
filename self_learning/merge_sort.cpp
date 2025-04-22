#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_sort(vector<int> a,vector<int> b) {
    vector<int>::iterator i=a.begin();
    vector<int>::iterator j=b.begin();
    vector<int> ans;
    while(i!=a.end() && j!=b.end()) {
        if(*i<=*j) {
            ans.push_back(*i);
            i++;
        }
        else {
            ans.push_back(*j);
            j++;
        }
    }
    if(i!=a.end()) {
        while(i!=a.end()) {
            ans.push_back(*i);
            i++;
        }
    }
    if(j!=b.end()) {
        while(j!=b.end()) {
            ans.push_back(*j);
            j++;
        }
    }   
    return ans;
}


int main() {
    vector<int> a={1,5,6,10,20};
    vector<int> b={1,3,13,14,30};
    vector<int> ans=merge_sort(a,b);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";  
    }
    return 0;
}
