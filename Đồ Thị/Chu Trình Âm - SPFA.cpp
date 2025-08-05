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

//https://cses.fi/problemset/task/1197
// Cycle SPFA code
int cnt[maxn],p[maxn];
ll dis[maxn];
bool in_queue[maxn];
deque<int> q;

int spfa(int s,int n) // O( n * m ) worst case
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
        p[k.fi] = i;
        if(!in_queue[k.fi])
        {
          q.pb(k.fi);
          in_queue[k.fi] = 1;
          cnt[k.fi]++;
          if(cnt[k.fi] > n)
          {
            return k.fi; // Negative Cycle
          }
        }
      }
    }
  }
  return 0;
}
//End Cycle SPFA code

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
      adj[u].pb(mk(v,w));
    }
    for(int i = 1;i<=n;i++)dis[i] = LLONG_MAX;
    for(int i = 1;i<=n;i++)
    {
      if(dis[i] == LLONG_MAX)
      {
        int k = spfa(i,n);
        if(k)
        {
          stack <int> st;
          map<int,bool> mp;
          
          while(!mp[k])
          {
            mp[k] = 1;
            st.push(k);
            k = p[k];
          }
          st.push(k);
          cout<<"YES\n";
          while(st.size())
          {
            cout<<st.top()<<' ';
            st.pop();
            if(st.top() == k)
            {
              cout<<k;
              break;
            }
          }
          return 0;
        }
      }
    }
    cout<<"NO";
    
    return 0;
}