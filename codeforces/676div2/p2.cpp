#include<bits/stdc++.h>
using namespace std;
bool valid(int x,int y,int n){
    if(x<0 || y<0 || x>n || y>n) return false;
    return true;
}
vector<pair<int,int>> findmininversion(vector<string> &mat, char ch){
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(mat.size(),vector<bool>(mat.size(),false));
    int n = mat.size()-1;
    if(mat[1][0]==ch)q.push({1,0});
    if(mat[0][1]==ch)q.push({0,1});
    vector<pair<int,int>> ans;
    bool haspath = true;
    int count = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            pair<int,int> p = q.front();
            q.pop();
            int newx = p.first+1;
            int newy = p.second;
            if(valid(newx,newy,n) && mat[newx][newy]==ch && visited[newx][newy]==false){
                q.push({newx,newy});
                visited[newx][newy] = true;
            }
            newx = p.first-1;
            newy = p.second;
            if(valid(newx,newy,n) && mat[newx][newy]==ch && visited[newx][newy]==false){
                q.push({newx,newy});
                visited[newx][newy] = true;

            }
            newx = p.first;
            newy = p.second-1;
            if(valid(newx,newy,n) && mat[newx][newy]==ch && visited[newx][newy]==false){
                q.push({newx,newy});
                visited[newx][newy] = true;

            }
            newx = p.first;
            newy = p.second+1;
            if(valid(newx,newy,n) && mat[newx][newy]==ch && visited[newx][newy]==false){
                q.push({newx,newy});
                visited[newx][newy] = true;
                }
            
        }
        if(q.size()<3){
            while(!q.empty()){
                ans.push_back(q.front());
                q.pop();
            }
            haspath = false;
            break;
        }
    }
    if(haspath ==false)return ans;
    if(visited[n-1][n]==false && visited[n][n-1]==false) return ans;
    else return {{0,0},{0,0},{0,0},{0,0}};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> mat(n);
        for(int i=0;i<n;i++)cin>>mat[i];
        vector<pair<int,int>> ans1 = findmininversion(mat,'0');
        vector<pair<int,int>> ans2 = findmininversion(mat,'1');
        vector<pair<int,int>> finans = ans1.size()>ans2.size()?ans1:ans2;
        cout<<finans.size()<<endl;
        for(int i=0;i<finans.size();i++){
            cout<<finans[i].first+1<<" "<<finans[i].second+1<<endl;
        }
    }
    return 0;
}