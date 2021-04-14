//last round went bad due to sprinklr mood
//keepcalm and do well, microsoft is ahead;
#include<bits/stdc++.h>
#define ll long long 
const int mod = 1e9+1;
const int max = 2e5+5;
#define pb push_back
#define mp make_pair
using namespace std;
set<int , greater<int> > a,b,c;
int retmin(int i,int j,int k){
    if(i<=j && i<=k){
        return 0;
    }
    if(j<=i && j<=k) return 1;
    return 2;
}
void inputa(int x){
    int temp;
    for(int i=0;i<x;i++){
        cin>>temp;
        a.insert(temp);
    }
}
void inputb(int x){
    int temp;
    for(int i=0;i<x;i++){
        cin>>temp;
        b.insert(temp);
    }
}
void inputc(int x){
    int temp;
    for(int i=0;i<x;i++){
        cin>>temp;
        c.insert(temp);
    }
}
ll solve(){
    int r,g,b1;
    cin>>r>>g>>b1;
    inputa(r);
    inputb(g);
    inputc(b1);
    ll maxarr=0;
    int numl = min(r,min(g,b1));
    set<int>::iterator k = a.begin();
    set<int>::iterator l =b.begin();
    set<int>::iterator m = c.begin(); 
    //cout<<a.size()<<" "<<b.size()<<" "<<c.size()<<endl;
    while(k!=a.end() && l!=b.end() && m!=c.end()){
      
        switch(retmin(*k,*l,*m)){
            case 0 : { 
                        maxarr += (*l)*(*m);
                        l++;
                        m++;
                        break;
            }
            case 1: {
                        maxarr += (*k)*(*m);
                        k++;
                        m++;
                        break;
            }
            case 2: {
                        maxarr += (*k)*(*l);
                        k++;
                        l++;
            }
        }

    }
    if(k==a.end()){
        while(l!=b.end() && m!=c.end()){
            maxarr += (*l)*(*m);
            l++;
            m++;
        }
    }else if(l==b.end()){
        while(k!=a.end() && m!=c.end()){
            maxarr += (*k)*(*m);
            k++;
            m++;
        }
    }else if(m==c.end()){
        while(k!=a.end() && l!=b.end()){
            maxarr += (*k)*(*l);
            k++;
            l++;
        }
    }

    return maxarr;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}