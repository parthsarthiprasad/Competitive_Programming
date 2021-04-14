#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k)for(int64_t i=j;i<k;i++)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
       int64_t n;
       cin>>n;
       int facts[10] = {0};
       string temp  = to_string(n);
       for(auto a:temp){
           facts[a-'0']++;
       }
        int64_t ans = n;
        int64_t minproduct = 1;
    
    //    rep(i,1,10){
    //        if(facts[i]){
    //            ans = ((ans)/i)*i;
    //        }
    //    }
    //    if(facts[5]){
    //         ans = ((ans)/5)*5;
    //    }
    //    cout<<ans<<" ";
       int fst[10] = {0};
       if(facts[2]){
           fst[2] = 1;
       }
        if(facts[3]){
           fst[3] = 1;
       }
        if(facts[4]){
           fst[2] = 2;
       }
        if(facts[5]){
           fst[5] = 1;
       }
        if(facts[6]){
           fst[2] = 1;
           fst[3] = 1;
       }
        if(facts[7]){
           fst[7] = 1;
       }
        if(facts[8]){
           fst[2] = 3;
       }
        if(facts[9]){
           fst[3] = 2;
       }
       rep(i,0,10){
          rep(j,0,fst[i]){
              minproduct*=i;
          }
       }
       
    //    for(int i=9;i>0;i--){
    //        if(facts[i]){
    //            minproduct*=i;
    //            if(i==9){
    //                facts[3] = 0;
    //            }else if(i==6){
    //                facts[2] =0;
    //                facts[3] =0;
    //            }else if(i==4){
    //                facts[2] = 0;
    //            }else if(i==8){
    //                facts[4] = 0;
    //                facts[2] = 0;
    //            }
    //        }
    //    }
       int i = ans;
       for(;i<=ans+minproduct;i++){
           bool possible = true;
           rep(j,2,10){
               if(facts[j]){
                   if(ans%j){
                       possible = false;
                       break;
                   }
               }
           }
           if(possible && i>=n){
               break;
           }
       }
        cout<<i<<endl;
    //    while(true){
    //        if(ans+minproduct>=n){
    //            ans-=minproduct;
    //        }else{
    //            break;
    //        }
    //    }

    //    cout<<minproduct<<" "<<ans<<endl;
      
      


    }
    return 0;
}