#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MOD 100000007
#define INF 100000009
#define ll long long 
#define all(x) x.begin(),x.end()
#define f(a,n) for(ll i=a;i<n;i++)
#define print(x) for(auto &it:x){cout<<it<<" ";}
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
void solve(){
    int n;
    cin>>n;
    string s, temp="abacaba";
    cin>>s;
    int count =0;
    int countquestion = 0;
    int startindex=-1;
    int endindex=-1;
    bool possible = false;
    for(int i=0;i<n;i++){
        int a=0;
        int tempcount =0;
        int index = i;
        while(a<7 &&( s[index]=='?' || s[index]==temp[a] )){
            a++;
            index++;
            if(s[index]=='?'){tempcount++;}
        }
        if(a==7){
            possible=true;
            startindex=i;
            endindex=index;
            if(tempcount){countquestion++;}
            count++;
        }
        else if(a>4){
            i+=3;
        }
    }

    if(count>countquestion+1){
        possible=false;
    }
    if(possible){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            if(startindex!=-1 && i==startindex){
                cout<<"abacaba";
                i=endindex;
            }
            if(s[i]=='?') cout<<'z';
            else cout<<s[i];
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return ;
}
int main(){
    fio
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
