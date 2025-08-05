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

//DSU code
int p[maxn],s[maxn];// parent[] ,  size[]

void prepare() // O( n )
{
  for(int i = 1;i<maxn;i++)
  {
    p[i] = i;
    s[i] = 1;
  }
}

int fi(int i)// find parent
{
  while(i != p[i])i = p[i] = p[p[i]]; // Path Compression -> O( 1 ) overall
  return i;
}

bool unite(int u,int v) // O( 1 )
{
  u = fi(u),v = fi(v);
  if(u == v)return 0;
  if(s[u] < s[v])swap(u,v); // Union by size
  p[v] = u;
  s[u] += s[v];
  return 1;
}
//End DSU code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}