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
        bool possible = true;
        for(int i=0;i<n && possible;i++){
            int element = vec[i];
            int start, end;
            start = end = i;
            start--;
            end++;
            while((start>=0 && element>vec[start]) ||
                  (end<n && element>vec[end])){
                while(start>=0 && element>vec[start]){
                    start--;
                    element++;
                }
                while(end<n && element>vec[end]){
                    end++;
                    element++;
                }
            }
            if(start==-1 && end==n){
                cout<<i+1<<endl;
                possible = false;
            }
        }

        if(possible){
            cout<<-1<<endl;
        }
        
    }
    return 0;
}