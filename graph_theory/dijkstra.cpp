#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
const int N = 1e5;
int d[N];
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
	vector<vector<pair<int,int> > > adj(V);
    for(int i=0;i<E;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
 	memset(d, -1 , sizeof(int)*V);   
    queue<int> q;
    q.push(0);
    d[0]=0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for(auto &[v,e]: adj[a]){
            if(d[v]==-1){
                d[v] = d[a]+e;
                q.push(v);
            }
        }
    }
    
    for(int i=1;i<V;i++){
        cout<<i<<" "<<d[i]<<"\n";
    }
  return 0;
}
