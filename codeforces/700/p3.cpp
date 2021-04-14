#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        int start = 1;
        int end = n;
     
        while(start+1<end){
            int greatindex ;
            cout<<"? "<<start<<" "<<end<<endl;
            cin>>greatindex;
            int mid1, mid2;
            cout<<"? "<<start<<" "<<greatindex<<endl;
            cin>>mid1;
            cout<<"? "<<greatindex<<" "<<end<<endl;
            cin>>mid2;
            if(mid1==greatindex){
                end = greatindex;
            }else if(mid2 == greatindex) {
                start = greatindex;
            }
        }
        cout<<start<<" "<<end<<endl;
        
    }
    


}