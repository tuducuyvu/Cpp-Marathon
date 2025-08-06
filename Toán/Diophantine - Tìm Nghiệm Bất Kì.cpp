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

//Diophantine code
ll local_gcd(ll a,ll b,ll &x,ll &y) // O( log(min(a,b)) )
{
  if(b==0)
  {
    x = 1;
    y = 0;
    return a;
  }
  ll x1,y1;
  ll ans = local_gcd(b,a%b,x1,y1);
  x = y1;
  y = x1 - y1 * (a/b);
  return ans;
}

bool diophantine(ll a,ll b,ll c, ll &x,ll &y,ll &g) // O( log(min(a,b)) )
{
  g = local_gcd(abs(a),abs(b),x,y);
  if(c % g)return 0;
  x *= c / g;
  y *= c / g;
  if(a<0)x = -x;
  if(b<0)y = -y;
  return 1;
}
//End Diophantine code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}