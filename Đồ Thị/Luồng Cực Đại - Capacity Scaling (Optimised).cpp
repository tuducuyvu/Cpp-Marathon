#include <bits/stdc++.h>
 
using namespace std;
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
typedef pair<int,int> pii;
 
const int maxn = 2e5 + 10;
vector<int> adj[maxn];// Đồ Thị

//https://cses.fi/problemset/task/1694
//Max Flow - Capacity Scaling (optimised) code
struct Edge
{
  int u,v;
  pii edge[2];
  bool find_edge(int i)const 
  {
    return i == v;
  }
  int find_node(int i)const
  {
    if(i == u)return v;
    return u;
  }
};
vector<Edge> edges;
 
void add_edge(int u,int v,int w)
{
  adj[u].pb(edges.size());
  adj[v].pb(edges.size());
  edges.pb({u,v,{mk(0,w),mk(0,0)}});
}
 
int cnt[maxn],t;
int require = INT_MAX;
int dfs(int i,int e,int mn)
{
  if(i == e)return mn;
  cnt[i] = t;
  for(int id : adj[i])
  {
    int k = edges[id].find_node(i);
    if(cnt[k] == t)continue;
    bool c = edges[id].find_edge(i);
    if(edges[id].edge[c].se - edges[id].edge[c].fi >= require)
    {
      int tmp = dfs(k,e,min(mn,edges[id].edge[c].se - edges[id].edge[c].fi));
      if(tmp)
      {
        edges[id].edge[c].fi += tmp;
        edges[id].edge[!c].fi -= tmp;
        return tmp;
      }
    }
  }
  return 0;
}
//End Max Flow - Capacity Scaling (optimised) code
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    while(m--)
    {
      int u,v,w;
      cin>>u>>v>>w;
      add_edge(u,v,w);
    }
    
    ll ans = 0;
    int tmp;
    for(;require;require>>=1)
    {
      while(++t,tmp = dfs(1,n,INT_MAX))ans+=tmp;
    }
    cout<<ans;
    
    return 0;
}
