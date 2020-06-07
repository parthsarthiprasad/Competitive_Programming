#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       bool flag = true;
       vector<int> vec;
       for(int i=0; i<n; i++){
         int temp;
         cin>>temp;
         temp-=5;
         vec.push_back(temp);
       }
        int count5 = 0;
        int count10 = 0;
        int count15 = 0;
        for(int i=0;i<n;i++){
            if(vec[i]==0) count5++;
            if(vec[i]==5){ 
                if (count5>0){
                     count5--;
                     count10++;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if(vec[i]==10){
                count15++;
                if ( i <2){
                    flag = false;
                    break;
                }
                else if ( count10 <1 ){
                    if (count5 <2){
                        flag = false;
                        break;
                    }
                    else{
                        count5-=2;
                    }
                }else{
                    count10--;
                }
            }
        }

       flag? cout<<"YES": cout<<"NO";
       cout<<endl;

    }
    return 0;
}