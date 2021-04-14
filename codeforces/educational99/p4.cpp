#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> vec(n), sortvec(n);
        rep(i,0,n){
            cin>>vec[i];
        }
        int presentanswer = INT_MAX;
        int jval = x;
        for(int j=-1;j<n;j++){
            for(int i=0;i<n;i++){
                if(i==j && x<vec[i]){sortvec[i] = x; x = vec[i];}
                sortvec[i] = vec[i];
            }
            for(auto a:sortvec) cout<<a<<" ";
            cout<<endl;
            sort(sortvec.begin(), sortvec.end());

            int minval = 501;
            rep(i,0,n){
                if(sortvec[i]!=vec[i]){
                    minval = sortvec[i];
                    break;
                }
            }
            if(minval<=x){
                cout<<"HERE";
                continue;
            }
            int currcount = 0;
            if(j!=-1)currcount++;
            map<int,int> mp;
            rep(i,0,n){
                if(sortvec[i]!=vec[i]) mp[vec[i]]=i;
            }
            bool sorted = false;
            
                int firstswapval = x;
                for(auto a:mp){
                    if(sorted) break;
                    swap(vec[a.second],x);
                    x=a.first;
                    currcount++;
                
                bool pk = true;
                bool firstswapoff = false;
                rep(i,0,n){

                    if(vec[i]==firstswapval){
                        if(i>0 && vec[i]<vec[i-1]) firstswapoff = true;
                    if(i+1<n && vec[i]>vec[i+1])firstswapoff=true;
                    }
                    if(i>0 && vec[i]<vec[i-1]) pk = false;
                    if(i+1<n && vec[i]>vec[i+1])pk=false;
                    
                }
                if(pk==true){
                    sorted = true;
                    if(firstswapoff)currcount+=2;
                }
                }
            if(sorted) presentanswer = min(presentanswer, currcount);
            x = jval;
        }
        if(presentanswer==INT_MAX)cout<<-1<<endl;
        else cout<<presentanswer<<endl;


    }
    return 0;
}