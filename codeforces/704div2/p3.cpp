#include<bits/stdc++.h>
using namespace std;
#define int int64_t
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int maxele = *max_element(vec.begin(), vec.end());
        int minele = *min_element(vec.begin(), vec.end());
        vector<int> maxtoright(n);
        vector<int> mintoleft(n);
        maxtoright[n-1] = vec[n-1];
        mintoleft[0] = vec[0];
        for(int i=n-2;i>=0;i--){
            maxtoright[i] = max(maxtoright[i+1], vec[i]);
        }
        for(int i=1;i<n;i++){
            mintoleft[i] = min(mintoleft[i-1],vec[i]);
        }
        bool poossible = false;
        for(int i=0;i<n;i++){
            if(maxtoright[i]>mintoleft[i])poossible = true;
        }

        if(poossible){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
        

    }
    return 0;
}