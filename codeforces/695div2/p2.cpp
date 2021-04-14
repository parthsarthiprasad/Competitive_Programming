#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int count = 0;
        vector<int> hill;
        for(int i=1;i<n-1;i++){
            if(vec[i]>vec[i-1] && vec[i]>vec[i+1]){
                count++;
                hill.push_back(i);
            }else if(vec[i]< vec[i-1] && vec[i]<vec[i+1]){
                count++;
                hill.push_back(i);
            }
        }
       
        
           int count3 = 0, count2 = 0;
        if(hill.size()==0){
            cout<<0<<endl;
            continue;
        }
        sort(hill.begin(),hill.end());
        for(int i=1;i<hill.size()-1;i++){
            if(hill[i-1]+1 == hill[i] && hill[i]+1==hill[i+1]){
                count3++;
                count2++;
                break;
            }
        }
        for(int i=1;i<hill.size();i++){
            if(hill[i]==hill[i-1]+1) count2++;
        }
        // cout<<count<<" ";
        if(count3) count-=3;
        else if(count2)count-=2;
        else count--;
        cout<<max(0,count)<<endl;
        
    }
    return 0;
}