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
        if(n==1){
            cout<<9<<endl;
            continue;
        }
        vector<int> vec(n,-1);
        int start = 1;
        vec[start] = 8;
        int i = (start-1+n)%n;
        int j = (start+1)%n;
        int count = 0;
        while(true){
            
            int val1 =  (10+ vec[(i+1)%n]+1+10)%10;
            int val2 = (10 + vec[(j-1+n)%n]+1+10)%10;
            // cout<<i<<" "<<j<<" "<<val1<<" "<<val2<<endl;
            if(vec[i]!=-1 && vec[j]!=-1) break;
            if(i==j && vec[i]==-1){
                vec[i] = max(val1, val2);
                
            }else{
                vec[i] = val1;
                vec[j] = val2;
                // if(vec[i]!=-1) {
                //     if(vec[j]!=-1){ break;}
                //     else{
                //         vec[j] = val2;
    
                //     }
                // }else if(vec[j]!=-1){
                //     if(vec[i]!=-1){break;}
                //     else{
                //         vec[i] = val1;
                       
                //     }
                // }

                
            }
            i--;
            j++;
            i=(i+n)%n;
            j=(j+n)%n;
            
        }
        
        for(int i=0;i<n;i++){
            cout<<vec[i];
        }
        cout<<endl;
    }
    return 0;
}

// vec[0] = 9;
        // for(int i=1;i<=n/2;i++){
        //     vec[i] = abs((10+ vec[i-1]-1)%10);
        // }
        // // for(auto a:vec){
        // //     cout<<a;
        // // }
        // // cout<<endl;
        // vec[n-1] = 8;
        // for(int i=n-2;i>n/2;i--){
        //     vec[i] =max(vec[i], abs((10 + vec[i+1]-1)%10));
        // }