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
vector<pii> adj[maxn];// Đồ Thị

//https://cses.fi/problemset/task/1693
//Eulerian cycle code
int deg[maxn];
bool used[maxn];
stack<int> st;
void dfs(int i) // O( m )
{
  while(adj[i].size())
  {
    if(used[adj[i].back().se])
    {
      adj[i].pop_back();
      continue;
    }
    used[adj[i].back().se] = 1;
    dfs(adj[i].back().fi);
  }
  st.push(i);
}
//End Eulerian cycle code


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].pb(mk(v,i));
      deg[u]++;
      deg[v]--;
    }
    if(deg[1] != 1 && deg[n] != -1)
    {
      cout<<"IMPOSSIBLE\n";
      return 0;
    }
    for(int i = 2;i<n;i++)
    {
      if(deg[i])
      {
        cout<<"IMPOSSIBLE\n";
        return 0;
      }
    }
    
    dfs(1);
    if(st.size() != m+1)
    {
      cout<<"IMPOSSIBLE\n";
      return 0;
    }
    
    for(;st.size();st.pop())cout<<st.top()<<' ';
    
    return 0;
}