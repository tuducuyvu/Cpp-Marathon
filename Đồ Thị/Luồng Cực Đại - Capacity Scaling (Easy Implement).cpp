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
// Max Flow - Capacity Scaling (easy implement) code
vector <pii> edge[maxn][maxn]; // pairs of ( used_cap , cap )
int cnt[maxn],t;
int require = INT_MAX;
int dfs(int i,int e,int mn)
{
  if(i == e)return mn;
  cnt[i] = t;
  for(int k : adj[i])
  {
    if(cnt[k] == t)continue;
    for(pii &l : edge[i][k])
    {
      if(l.se - l.fi >= require)
      {
        int tmp = dfs(k,e,min(mn,l.se-l.fi));
        if(tmp)
        {
          l.fi += tmp;
          edge[k][i].begin()->fi -= tmp;
          return tmp;
        }
        break;
      }
    }
  }
  return 0;
}
//End Max Flow - Capacity Scaling (easy implement) code

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
      adj[u].pb(v);
      adj[v].pb(u);
      edge[u][v].pb(mk(0,w));//directed
      edge[v][u].pb(mk(0,0));// mk(0,w) here if undirected
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