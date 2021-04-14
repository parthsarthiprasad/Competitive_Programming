//water droplet problem
#include<bits/stdc++.h>
using namespace std;
struct water{
    int pos;
    int vel;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int numdrops ;
    cin>>numdrops;
    water drops[numdrops];
    for(int i=0;i<numdrops;++i){
        cin>>drops[i].pos;
    }
    for(int i=0;i<numdrops;++i){
        cin>>drops[i].vel;
        if((n-drops[i].pos) %drops[i].vel){
            drops[i].vel = 1 + (n - drops[i].pos)/drops[i].vel; 
        } 
        else{
            drops[i].vel = (n-drops[i].pos)/drops[i].vel;
        }
    }
    sort(drops, drops+n, [](const water &a, const water &b){
        if(a.pos==b.pos){
            return a.vel >b.vel;
        }
        return a.pos<b.pos;
    });

    stack<int> s;
    for(int i=numdrops-1;i>0;i--){
        while(!s.empty() && s.top()>drops[i].vel){
            s.pop();
        }
        s.push(drops[i].vel);
    }
    cout<<s.size()<<endl;

}