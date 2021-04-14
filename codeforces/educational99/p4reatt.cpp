#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> vec(n);
        for(int i=0;i<n;i++){cin>>vec[i];}
        int finalans = INT_MAX;
        for(int i=-1;i<n;i++){
            vector<int> tempvec(n);
            int beginningcount = 0;
            int swapval = x;
            for(int j=0;j<n;j++){
                if(i==j && vec[i]>x){
                    beginningcount++;
                    tempvec[i] = x;
                    swapval = vec[i];
                }else{
                    tempvec[j] = vec[j];
                }
                
            }
            // for(auto a:tempvec)cout<<a<<" ";
            // cout<<endl;
            vector<int> sortedsequence(tempvec.begin(), tempvec.end());
            sort(sortedsequence.begin(), sortedsequence.end());
            int firstreference = INT_MAX;
            for(int i=0;i<n;i++){
                if(tempvec[i]!=sortedsequence[i]){
                    beginningcount++;
                    firstreference = min(firstreference, sortedsequence[i]);
                    if(tempvec[i]==swapval) beginningcount+=2;
                }
                
            }
            if(firstreference<=swapval){
                continue;
            }
        
            finalans = min(finalans, beginningcount);
        }
        if(finalans!=INT_MAX) cout<<finalans<<endl;
        else cout<<-1<<endl;
    }
}