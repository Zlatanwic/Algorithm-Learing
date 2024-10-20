#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100],d[100];
//a用来表示每行的第几列被占，b表示第几列是否被占，c表示某条主对角线是否被占，d表示某条副对角线是否被占
int total;
int n;

void print()
{
    total++;
    if(total<=3){
        for(int t=1;t<=n;t++)
            cout<<a[t]<<' ';
        cout<<endl;
    }
}

void check(int i)
{
    if(i>n){
        print();
        return ;
    }
    else{
        for(int j=1;j<=n;j++){
            if(!b[j]&&!c[i+j]&&!d[i-j+n]){
                a[i]=j;
                b[j]=1;
                c[i+j]=1;
                d[i-j+n]=1;
                check(i+1);
                b[j]=0;
                c[i+j]=0;
                d[i-j+n]=0;
            }
        }
    }
}

int main()
{
    cin>>n;
    //int m=0;
    check(1);
    cout<<total<<endl;
    return 0;

}
