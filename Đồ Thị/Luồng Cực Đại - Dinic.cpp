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
 
const int maxn = 1e3 + 10;
vector<int> adj[maxn];// Đồ Thị

//https://cses.fi/problemset/task/1694
//Max Flow - Dinic code
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
 
void add_edge(int u,int v,int w) // O( 1 )
{
  adj[u].pb(edges.size());
  adj[v].pb(edges.size());
  edges.pb({u,v,{mk(0,w),mk(0,0)}});
}

int depth[maxn],ptr[maxn];

bool reset(int s,int e,int n) // O( n + m )
{
  for(int i = 1;i<=n;i++)depth[i] = -1,ptr[i] = 0;
  depth[s] = 0;
  deque<int> q;
  q.pb(s);
  while(q.size())
  {
    int i = q.front();
    q.pop_front();
    for(int id : adj[i])
    {
      bool c = edges[id].find_edge(i);
      if(edges[id].edge[c].se - edges[id].edge[c].fi == 0)continue;
      int k = edges[id].find_node(i);
      if(depth[k] != -1)continue;
      depth[k] = depth[i] + 1;
      if(k == e)break;
      q.pb(k);
    }
  }
  
  return depth[e] != -1;
}

int dfs(int i,int e,int mn) // O( m )
{
  if(i == e)return mn;
  for(int & l = ptr[i];l < adj[i].size();l++)
  {
    int id = adj[i][l];
    int k = edges[id].find_node(i);
    if(depth[k] != depth[i] + 1)continue;
    bool c = edges[id].find_edge(i);
    if(edges[id].edge[c].se - edges[id].edge[c].fi)
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

ll max_flow(int s,int e,int n) // O( m * n ^ 2 ) overall
{
  ll ans = 0;
  int tmp;
  
  while(reset(s,e,n))
  {
    int tmp;
    while(tmp = dfs(s,e,INT_MAX))ans+=tmp;
  }
  
  return ans;
}
//End Max Flow - Dinic code
 
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
    
    cout<<max_flow(1,n,n);
    
    return 0;
}
