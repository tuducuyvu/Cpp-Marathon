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

const int maxn = 25e2 + 10;
vector<pii> adj[maxn]; // Đồ Thị

// SPFA code
int cnt[maxn];
ll dis[maxn];
bool in_queue[maxn];
deque<int> q;

void spfa(int s,int n) // O( n * m ) worst case
{
  dis[s] = 0;
  q.pb(s);
  in_queue[s] = 1;
  while(q.size())
  {
    int i = q.front();
    q.pop_front();
    in_queue[i] = 0;
    for(pii k : adj[i])
    {
      if(dis[k.fi] > dis[i] + k.se)
      {
        dis[k.fi] = dis[i] + k.se;
        if(!in_queue[k.fi])
        {
          q.pb(k.fi);
          in_queue[k.fi] = 1;
          cnt[k.fi]++;
          if(cnt[k.fi] > n)
          {
            return; // Negative Cycle
          }
        }
      }
    }
  }
}
//End SPFA code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}