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

int main(){
    fio
    int t;
    cin>>t;
    while(t--){
        ll l,r,m,a,b=0,c=0;
        cin>>l>>r>>m;
        ll nmax = ((m+r)/l) -1;
        //ll nmin = ((m+l)/r) -1;
        //atleast 1 soln' should exits
        a=l;
        while(true){
             if(r*nmax-m <l-r){
                nmax++;
                continue;
            }
            if(l*nmax-m>r-l){
                nmax--;
                continue;
            }
            break;
        }
        
        while(a<=r && a*nmax -m <l-r){
            a++;
        }

        c=r;
        b=c-a*nmax+m;
        
        int temp = b-r;
        b-=max(0,temp);
        c-=max(0,temp);
        cout<<a<<" "<<b<<" "<<c<<endl;

    }
    return 0;
}
