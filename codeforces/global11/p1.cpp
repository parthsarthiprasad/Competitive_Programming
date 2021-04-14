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
        vector<int> vec(n),temp(n);
        for(int i=0;i<n;++i)cin>>vec[i];
        sort(vec.rbegin(),vec.rend());
        temp[0] = vec[0];
        bool ans = true;
        for(int i=1;i<n;i++){
            temp[i] = temp[i-1] + vec[i];
            if(temp[i]==0) ans = false;
        }
        if(ans==false){
        sort(vec.begin(),vec.end());
        int i=0;
        for(;i<n && vec[i]==0;i++);
        reverse(vec.begin(), vec.begin()+i);
        reverse(vec.begin()+i,vec.end());
        reverse(vec.begin(),vec.end());
        temp[0] = vec[0];
        bool ans1 = true;
        for(int i=1;i<n;i++){
            temp[i] = temp[i-1] + vec[i];
            if(temp[i]==0) ans1 = false;
        }
        if(ans1==false){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
        }else{
            cout<<"YES"<<endl;
            for(int i=0;i<n;++i){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}