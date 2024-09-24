#include <bits/stdc++.h>
using namespace std;
int Hash[1010]={0};
queue<int>trans;
int main()
{
    int m,n;
    cin>>m>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(Hash[a]==0){
            ans++;
            trans.push(a);
            Hash[a]=1;
            if(int(trans.size())>int(m)){
                Hash[trans.front()]=0;
                trans.pop();
            }
        }


    }
    cout<<ans<<endl;
    return 0;

}