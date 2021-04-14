#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        map<int,int> m;
        rep(i,0,n) {
            cin>>vec[i];
            m[vec[i]]++;
        }
        int answer = -1;
        
        for(auto a:m){
            if(a.second==1){
                answer = a.first;
                break;
            }
        
        }
        if(answer==-1){
            cout<<-1<<"\n";
            continue;
        }
        rep(i,0,n){
            if(vec[i]==answer){
                answer = i+1;
                break;
            }
        }
        cout<<answer<<"\n";
        
        
        
    }
    return 0;
}