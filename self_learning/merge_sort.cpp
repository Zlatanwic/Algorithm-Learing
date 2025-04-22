#include <iostream>
#include <vector>
using namespace std;

vector<int> merge_array(vector<int> a,vector<int> b) {
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
    ans.insert(ans.end(), i, a.end());
    ans.insert(ans.end(), j, b.end());
    return ans;
}

vector<int> merge_sort(const vector<int>& a,int left,int right) {
    if(left<right) {
        int mid=(left+right)/2;
        vector<int> left_array=merge_sort(a,left,mid);
        vector<int> right_array=merge_sort(a,mid+1,right);
        return merge_array(left_array,right_array);
    }
    else {
        return {a[left]}; 
    }
}


int main() {
    vector<int> a={45,20,3,7,4,29,45,61,3,16};
    
    vector<int> ans=merge_sort(a,0,a.size()-1);
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";  
    }
    return 0;
}
