#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int solve(){
    int n, temp;
    cin>>n;
    multiset<int> s;
    int num=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        auto it = s.upper_bound(temp);
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert(temp);
    }
    return s.size();
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}
/*
5
3 8 2 1 5
*/