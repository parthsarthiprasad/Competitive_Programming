#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i=j;i<k;i++)
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d,p,k;
    cin>>n>>d>>p>>k;
    /*
     n is the number of fuel stations 
     d is the total distance i have to travel linearly
     p is the petrol at Time t=0
     k is time taken to refill petrol
    */
    priority_queue<int> pq;
    vector<int> distance(n);
    vector<int> fuels(n);
    rep(i,0,n) cin>>distance[i];
    rep(i,0,n) cin>>fuels[i];
    int64_t distancetravelled = p;
    int64_t dragdistance = 0;
    int64_t numrefuels = 0;
    rep(i,0,n){
        while(!pq.empty() && distancetravelled<distance[i] && distancetravelled<d){
           distancetravelled+=pq.top();
           pq.pop();
           numrefuels++;
        }
        if(distancetravelled<distance[i] && distancetravelled<d){
           dragdistance+=distance[i] - distancetravelled;
        }
        if(distancetravelled<d) pq.push(fuels[i]);
    }
    if(distancetravelled<d) dragdistance+=(d - distancetravelled);
    int64_t timetaken = 5*dragdistance + numrefuels*k;
    cout<<timetaken<<endl;

    
    

}