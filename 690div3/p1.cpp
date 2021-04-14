#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n),b(n);
        rep(i,0,n)cin>>vec[i];
        int i = 0;
        int j = n-1;
        while(i<j){
            cout<<vec[i++]<<" ";
            cout<<vec[j--]<<" ";
        }
        if(i==j){
            cout<<vec[i]<<endl;
        }else{
            cout<<endl;
        }
        
    }
    return 0;
}