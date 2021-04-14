#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> vec(n);
       for(int i=0;i<n;i++)cin>>vec[i];
       int odd  = 0;
       for(int i=0;i<n;i++){
           if(vec[i]&1) odd++;
       }
       cout<<min(n-odd,odd)<<endl;

    }
    return 0;
}