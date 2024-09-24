#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N];
deque<long long>q;

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]>a[i])
            q.pop_back();
        q.push_back(i);
        if(i>=k){
            
            while(!q.empty()&&q.front()<=i-k)
                q.pop_front();
            cout<<a[q.front()]<<' ';

        }

    }
    cout<<endl;
    while(!q.empty())
        q.pop_back();
    for(int i=1;i<=n;i++){
        while(!q.empty()&&a[q.back()]<a[i])
            q.pop_back();
        q.push_back(i);
        if(i>=k){
            
            while(!q.empty()&&q.front()<=i-k)
                q.pop_front();
            cout<<a[q.front()]<<' ';

        }
    }

    return 0;
}