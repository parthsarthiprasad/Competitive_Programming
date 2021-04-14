#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int64_t n;
       cin>>n;
    //    string temp = to_string(n);
    //    int facts[10] = {0};
    //    for(auto a:temp){
    //        facts[a-'0']++;
    //    }
    //    for(int i=1;i<10;i++){
    //        cout<<i<<" "<<facts[i]<<endl;
    //    }
       int64_t seed = n;
       while(true){
           bool possible = true;
           string temp = to_string(seed);
           for(int i=0;i<temp.size();i++){
               if((temp[i]!='0') && seed%(temp[i]-'0')){
                   seed++;
                   possible = false;
                   break;
               }
           }
           if(possible){
               cout<<seed<<"\n";
               break;
           }
        
       }
    }
    return 0;
}