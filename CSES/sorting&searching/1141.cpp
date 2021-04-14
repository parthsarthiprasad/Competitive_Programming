#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//good probme
ll solve(){
    int n,j=0, ans=0;
    cin>>n;
    int ptr[n];
    for(int i=0;i<n;i++) cin>>ptr[i];
    set<int> s;
    for(int i=0;i<n;i++){
        while(s.count(ptr[i])){
            s.erase(ptr[j++]);
        }
        s.insert(ptr[i]);
        ans = max(ans,i-j+1);

    }
    return ans;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve()<<endl;
}

/*
8
1 2 1 3 2 7 4 2
*/