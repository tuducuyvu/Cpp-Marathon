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
const int maxn = 1e6 + 10;
vector<int> adj[maxn];// Đồ Thị

//https://cses.fi/problemset/task/1679
// topo code
int c[maxn];
stack<int> st;
bool topo(int i) // O( n )
{
  c[i] = 1;
  for(int k : adj[i])
  {
    if(c[k] == 1)return 1; // true -> cycle (invalid)
    if(c[k] == 2)continue;
    if(topo(k))return 1;
  }
  c[i] = 2;
  st.push(i);
  return 0;
}
//End topo code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    while(m--)
    {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
    }
    
    for(int i = 1;i<=n;i++)
    {
      if(c[i] == 0 && topo(i))
      {
        cout<<"IMPOSSIBLE";
        return 0;
      }
    }
    
    for(;st.size();st.pop())cout<<st.top()<<' ';
    
    return 0;
}