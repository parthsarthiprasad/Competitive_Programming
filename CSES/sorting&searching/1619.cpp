//this is classic maximum trains at platform type question
#include<bits/stdc++.h>
using namespace std;
bool comp(const int &a, const int &b){
    return abs(a)<abs(b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arriv, depart;
    vector<int> temp;
    for(int i=0;i<n;i++) {
       
        cin>>arriv>>depart;
        temp.push_back(arriv);
        temp.push_back(-1*depart);
    }
    sort(temp.begin(),temp.end(), comp);
    int maxnum = 0;
    int count =0;
    for(int i=0;i<temp.size(); i++){
        if(temp[i]>0) count++;
        else count--;
        maxnum = max(maxnum,count);
    }
    
    cout<<maxnum<<"\n";
    return 0;
}
//took input in wrong manner
/*
10
45 84
2 43
34 64
42 99
50 80
12 21
72 82
39 86
33 89
47 97

10
1 20
2 19
3 18
4 17
5 16
6 15
7 14
8 13
9 12
10 11
*/