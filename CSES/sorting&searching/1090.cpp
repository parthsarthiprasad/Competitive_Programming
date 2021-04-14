#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int solve(){
    int n,x;
    cin>>n>>x;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    sort(ptr, ptr+n);
    int num = 0;
    int totsum =0;
    int i=0, j=n-1;
    while(i<j){
        if(ptr[j]+ptr[i]>x){
            j--;
        }else{
            j--;
            i++;
        }
        num++;
    }
    if(i==j) num++;
    return num;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}

/*
4 10
7 2 3 9

https://cses.fi/problemset/task/1090
*/