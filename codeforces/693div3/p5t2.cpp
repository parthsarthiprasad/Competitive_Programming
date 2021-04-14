#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5;

struct rect{
    int x;
    int y;
};
struct ltreedim{
    int index;
    int y;
};
struct btreedim{
    int index;
    int x;
};
vector<ltreedim> lquery(nax);
vector<btreedim> bquery(nax);
vector<int> ltree(2*nax);
vector<int> btree(2*nax);
ltreedim tempa;
btreedim tempb;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<rect> vec(n);
        int index = 0;
        int lqueryindex = 0;
        int bqueryindex = 0;

        for(auto &a:vec){
            int x, y;
            cin>>x>>y;
            if(x<y) swap(x,y);
            a.x = x;
            a.y = y; 
            tempa.index = index; 
            tempa.y = y;
            tempb.index = index;
            tempb.x = x;
            lquery[lqueryindex++] = tempa;
            bquery[bqueryindex++] = tempb;
            index++;
        }
        sort(lquery.begin(), lquery.end(), [&](const ltreedim &a, const ltreedim&b){
            return a.y > b.y;
        });
        sort(bquery.begin(),bquery.end(), [&](const btreedim &a, const btreedim &b){
            return a.x > b.x;
        });

        for(int i=0;i<lqueryindex;i++){
            cout<<vec[lquery[i].index].x<<" "<<vec[lquery[i].index].y<<"\n";
        }
        for(int i=0;i<bqueryindex;i++){
            cout<<vec[bquery[i].index].x<<" "<<vec[bquery[i].index].y<<"\n";
        }

    }
    return 0;
}