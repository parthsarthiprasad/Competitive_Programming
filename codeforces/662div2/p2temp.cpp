#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5+1;
const int mod = 1e9+7;
#define ll long long 
#define pb push_back
#define mp make_pair
void solve(){
    int n,temp;
    cin>>n;
    int ptr[n];
    map<int,int> m;
    map<int,int> twosum;
    map<int,int> foursum;
    map<int,int> onesum;
    for(int i=0;i<n;i++){
        cin>>temp;
        m[temp]++;
    }
    int fourval = 0;
    int twoval = 0;
    int oneval = 0;
    int count4 = 0;
    map<int,int>::iterator it = m.begin();
    for(it = m.begin(); it!=m.end(); ++it){
        if(it->second>3) fourval++;
        else if(it->second>1) twoval++;
        else oneval++;
    }

    int q;
    cin>>q;
    char a; int b;
    while(q--){
        cin>>a;
        cin>>b;
        if(a=='-'){
            if(m[b]>4){
                count4--;
            }
            else if(m[b]==4){
                fourval--;
                twoval++;
                count4--;
            }else if(m[b]>2){
               
            }
            else if(m[b]==2){
                twoval--;
            }
            else{
               oneval--;
            }
            m[b]--;
        }else{
            if(m[b]>3){
                count4++;
            }
            if(m[b]==3){
                fourval++;
                twoval--;
                count4++;
            }
            else if(m[b]==2){
               
            }
            else if(m[b]==1){
               twoval++;
            }else{
                oneval++;
            }
            m[b]++;
        }

        if(fourval>1 || ( fourval==1 && count4 >=8)){
            cout<<"YES"<<endl; continue;
        }else if(fourval==1 && twoval>1){
            cout<<"YES"<<endl; 
        }else{
            cout<<"NO"<<endl;
        }

        // int sum = 8;
        // bool square=false;
        // for(auto &[v, j]: m){
        //     if(sum<=0 && square){
        //         break;
        //     }
        //     if(j/4 > 1){ sum-=8; square=true; break;}
        //     if(j>=6){ sum-=6; square = true; continue;}
        //     if(j/4>0){ sum-=4; square= true; continue; }
        //     if(j>1){sum-=2;}
        // }
        // if(sum<=0 && square) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    solve();
}