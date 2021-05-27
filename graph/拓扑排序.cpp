#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> e;
vector<int> deg;
vector<int> res;
vector<int> vis;
int top;

bool dfs(int x){
    vis[x]=-1;
    for(auto&y:e[x]){
        if(vis[y]==-1)return false;
        if(!vis[y]&&!dfs(y))return false;
    }
    vis[x]=1;
    res[--top]=x;
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    top=n;
    e.resize(n+1);
    deg.resize(n+1);
    vis.resize(n+1);
    res.resize(n);
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;++i){
        cin>>edges[i].first>>edges[i].second;
        if(edges[i].first==edges[i].second){
            cout<<-1<<endl;
            return 0;
        }
    }
    edges.erase(unique(begin(edges),end(edges)),end(edges));
    for(auto&[a,b]:edges){
        e[a].push_back(b);
        ++deg[b];
    }
    for(int i=1;i<=n;++i){
        if(!deg[i]&&!vis[i]){
            if(!dfs(i)){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    if(res.size()!=n){
        cout<<-1<<endl;
        return 0;
    }
    for(auto&i:res)cout<<i<<" ";
    return 0;
}
