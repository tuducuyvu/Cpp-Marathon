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
vector<pii> adj[maxn]; // Đồ Thị

// MST Prim code
bool c[maxn];
priority_queue<pii,vector<pii>,greater<pii>>q;
ll prim() // O( (n + m) * log(n) )
{
  ll ans = 0;
  q.push(mk(0,1));
  while(q.size())
  {
    int w = q.top().fi;
    int i = q.top().se;
    q.pop();
    if(c[i])continue;
    c[i] = 1;
    ans += w;
    for(pii k : adj[i])
    {
      if(!c[k.fi])q.push(mk(k.se,k.fi));
    }
  }
  return ans;
}
//End MST Prim code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}