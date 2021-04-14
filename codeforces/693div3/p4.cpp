#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        vector<int> evenvals;
        vector<int> oddvals;
        for(auto &a:vec){
            cin>>a;
            if(a&1){
                oddvals.push_back(a);
            }else{
                evenvals.push_back(a);
            }
        }
        
        sort(oddvals.rbegin(),oddvals.rend());
        sort(evenvals.rbegin(),evenvals.rend());
        int64_t  oscore = 0;
        int64_t escore = 0;
        int i = 0, j = 0;
        bool turn = true;
        while(i<oddvals.size() && j<evenvals.size()){
            if(turn){
                if(evenvals[j]>oddvals[i]){
                    escore+=evenvals[j++];
                }else{
                    i++;
                }
            }else{
                if(oddvals[i]>evenvals[j]){
                    oscore+=oddvals[i++];
                }else{
                    j++;
                }
            }
            turn=!turn;   
        }
        while(i<oddvals.size()){
            if(turn){
                i++;
                turn = !turn;
            }
            else {
                oscore+=oddvals[i++];
                turn = !turn;
            }
            // i+=2;
        }
        while(j<evenvals.size()){
            if(turn){
            escore+= evenvals[j];
            j++;
            turn = !turn;
            }else{
                j++;
                turn = !turn;
            }
        }
        // cout<<oscore<<" "<<escore<<endl;
        if(oscore == escore){
            cout<<"Tie\n";
        }else{
            if(oscore>escore){
                cout<<"Bob\n";
            }else{
                cout<<"Alice\n";
            }
        }


    }
    return 0;
}