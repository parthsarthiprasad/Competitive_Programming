#include<bits/stdc++.h>
#define int int64_t
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        bool flat = false;
        int answer = -2;
        for(int i=0;i<k && !flat;i++){
            bool added = false;
            for(int j=0;j<n-1 && !added;j++){
                if(vec[j]<vec[j+1]){
                    vec[j]++;
                    if(i==k-1){
                        answer = j;
                    }
                    added = true;
                }

            }
            if(added==false){
                flat = true;
            }
        }
        
        cout<<answer+1<<endl;

    }
    return 0;
}