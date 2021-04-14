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
        for(auto &a:vec){cin>>a;}
        bool same = true;
        int first, second;
        for(int i=1;i<n && same;i++){
            if(vec[i]!=vec[i-1]){
                first = i;
                second = i-1;
                same = false;
            }
        }
        if(same){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        cout<<first+1<<" "<<second+1<<endl;
        for(int i=0;i<n;i++){
            if(i==first || i==second)continue;
            if(vec[i] == vec[first]){
                cout<<i+1<<" "<<second+1<<endl;
            }else{
                cout<<i+1<<" "<<first+1<<endl;
            }
        }

    }
    return 0;
}