#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x: arr) cin>>x;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr.size();
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout<<solve()<<"\n";
    return 0;
}