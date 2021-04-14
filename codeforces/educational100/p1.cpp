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
        string r,b;
        cin>>r>>b;
        sort(r.rbegin(),r.rend());
        sort(b.rbegin(),b.rend());
        if(r==b){
            cout<<"EQUAL\n";
        }else{
            bool done = false;
            // rep(i,1,n){
            //     if(r[i-1]>=b[i] && b[i-1]>=r[i]) continue;
            //     else if(r[i-1]>=b[i]){
            //         done = true;
            //         cout<<"RED\n";
            //         break;
            //     }else{
            //         done = true;
            //         cout<<"BLUE\n";
            //         break;
            //     }
            //     if(!done){
            //         if(r[n-1]==b[n-1]){
            //             cout<<"EQUAL\n";
            //         }else if(r[n-1]>b[n-1]){
            //             cout<<"RED\n";
            //         }else{
            //             cout<<"BLUE\n";
            //         }
            //     }
            // }
            int ptr1[9] = {0};
            int ptr2[9] = {0};
            rep(i,0,n){
                ptr1[r[i]='0']++;
            }
            rep(i,0,n){
                ptr2[b[i]='0']++;
            }
            int num1 = 0, num2 = 0;
            rep(i,0,10){
                num1+= i*ptr1[i];
                num2+= i*ptr2[i];
            }
            if(num1>num2){
                cout<<"RED\n";
            }else {
                cout<<"BLUE\n";
            }
            
        }


    }
    return 0;
}