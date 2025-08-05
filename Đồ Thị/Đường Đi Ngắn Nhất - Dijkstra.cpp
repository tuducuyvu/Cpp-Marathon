#include <bits/stdc++.h>

using namespace std;
#define all(v) v.begin(),v.end()
#define pb push_back
#define ll long long
#define ld long double
#define fi first
#define se second
#define mk make_pair
typedef pair<ll,int> pii;

const int maxn = 2e5 + 10;
vector<pii> adj[maxn]; // Đồ Thị

//Dijkstra code
priority_queue<pii,vector<pii>,greater<pii>>q;
ll dis[maxn];

void Dijkstra(int s) // O( (n + m) * log(n) )
{
  for(int i = 1;i<maxn;i++)dis[i] = LLONG_MAX;
  dis[s] = 0;
  q.push(mk(0,s));
  while(q.size())
  {
    ll w = q.top().fi;
    int i = q.top().se;
    q.pop();
    if(w != dis[i])continue;
    
    for(pii k : adj[i])
    {
      if(dis[k.fi] > w + k.se)
      {
        dis[k.fi] = w + k.se;
        q.push(mk(dis[k.fi],k.fi));
      }
    }
  }
}
//End Dijkstra code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}