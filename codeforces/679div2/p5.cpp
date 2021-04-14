#include<bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)
#define ll long long int 
const int nax = 2e5+5;
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> operations(2*n);
    vector<int> answer(n);
    getline(cin,operations[0]);
    forn(i,2*n){
        getline(cin,operations[i]);
    }
    reverse(operations.begin(),operations.end());
    set<int> var;
    forn(i,n){
        var.insert(i+1);
    }
    vector<int> ordernums;
    forn(i,2*n){
        if(operations[i][0]=='-'){
            ordernums.push_back(operations[i][2] - '0');
        }
    }
    // reverse(ordernums.begin() ,ordernums.end());
    int count = 0;
    bool possible = true;
    priority_queue<int, vector<int>,greater<int>>pq;
    forn(i,2*n){
        if(operations[i][0]=='+'){
            count--;
        }else{
            count++;
        }
        if(count>0){
            possible=false;
            break;
        }
    }
    if(!possible){
        cout<<"NO"<<endl;
        return 0;
    }else{
         forn(i,2*n){
        if(operations[i][0]=='+'){
            if(pq.empty()){
                possible=false;
                break;
            }else{
                answer.push_back(pq.top());
                pq.pop();
            }
        }else{
            pq.push(operations[i][2] - '0');
        }
        
    }
    if(!possible){
        cout<<"NO"<<endl;
        return 0;
    }else{
        reverse(answer.begin(), answer.end());
        forn(i,n){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
    }
    }
    return 0;
}