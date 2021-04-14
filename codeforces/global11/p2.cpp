#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k==0){
            long sum = 0;
            for(int i=0;i<s.size();i++){
                if(s[i]=='W'){
                    if((i==0)||s[i-1]=='L'){
                        sum+=1;
                    }else{
                        sum+=2;
                    }
                }
            }
            cout<<sum<<endl;
            continue;
        }
        int totw = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='W') totw++;
        }
        vector<pair<int,int>> segments;
      
        for(int i=0;i<(int)s.size();i++){
            int j=i;
            while(j<(int)s.size() && s[j]=='L'){
                j++;
            }
            if(j-i>0){
                segments.push_back({j-i,i});
            }
            i=j;
        }
        sort(segments.begin(), segments.end());
        cout<<endl<<endl;
        for(int i=0;i<segments.size();++i){
            cout<<segments[i].first<<" "<<segments[i].second<<endl;
        }
        cout<<endl<<endl;
        int value = 2*min(n, totw+k);
        long temp = k;
        int i=0;
        bool fval = false;
        for(;i<n ;i++){
            temp-=segments[i].first;
            if(temp>0 && segments[i].first + segments[i].second !=n){
                if(segments[i].second==0){
                    fval=true;
                    }
            }else{
                value--;
            }
            
        }

        if(!fval && s[0]=='W')value--;
        cout<<value<<endl;

        
    }
    return 0;
}