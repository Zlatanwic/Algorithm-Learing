#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int partition(vector<int>&a,int p, int r)
{
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quick_sort(vector<int>&a,int p,int r)
{
    if(p<r){
        int q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}


int main()
{
    vector<int>a={3,1,60,14,2,34,20,54,6};
    quick_sort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";  
    }
    return 0;
}