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
        if(n>45) {
            cout<<-1<<endl;
            continue;
        }
        string s;
        int i = 9;
        while(n>0){
            s.push_back(('0' + min(n, i)));
            n-=min(n,i);
            i--;
        }
        sort(s.begin(), s.end());

        cout<<s<<endl;
        
    }
    return 0;
}