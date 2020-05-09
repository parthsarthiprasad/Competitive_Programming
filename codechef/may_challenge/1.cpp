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
        int mincount=n;
        int maxcount=0;
        int temp;
        cin>>temp;
        int count = 1;
        for(int i=1;i<n;i++){
            int val;
            cin>>val;
            if(val - temp <3){
                count++;
            }else{
                if(count<mincount)
                    mincount=count;
                if(count>maxcount)
                    maxcount=count;
                
                count=1;
            }
            temp=val;
        }
        if(count<mincount)
            mincount=count;
        if(count>maxcount)
            maxcount=count;
        cout<<mincount<<" "<<maxcount<<endl;

    }
    return 0;
}