#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        rep(i,0,n)cin>>vec[i];
        int numoperations = n-1;
        for(int i=1;i<=n;i++){
            bool possible = true;
            int tempoperations = i-1;
            int64_t tempsum = 0;
            for(int j=0;j<i;j++){
                // tempoperations++;
                tempsum+=vec[j];
            }
            int j = i;
            int ksum = j!=n?vec[j]:tempsum;
            j++;

            while(j<n){
                if(ksum<tempsum){
                    ksum+=vec[j];
                    tempoperations++;
                }
                else if(ksum == tempsum){
                    ksum=vec[j];
                }else if(ksum>tempsum){
                    possible = false;
                    break;
                }
                j++;
            }
            
            if(ksum!=tempsum){possible = false;}
            // cout<<i<<ksum<<" "<<tempsum<<" "<<tempoperations<<" "<<possible<<endl;
            if(possible){
                numoperations = min(numoperations, tempoperations);
                // break;
            }
        }
        cout<<numoperations<<"\n";
    }
    return 0;
}