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
ll local_gcd(ll a,ll b,ll &x,ll &y)
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

bool diophantine(ll a,ll b,ll c, ll &x,ll &y,ll &g)
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

//Constrained Diophantine code
void shift(ll &x,ll &y,ll a,ll b,ll t)
{
  x += b * t;
  y -= a * t;
}

ll diophantine_count(ll a,ll b,ll c,ll minx,ll maxx,ll miny,ll maxy)
{
  ll x,y,g;
  if(!diophantine(a,b,c,x,y,g))return 0;
  a/=g;
  b/=g;
  int sign_a = a / abs(a); // a != 0    (!)
  int sign_b = b / abs(b); // b != 0    (!)
  
  shift(x,y,a,b,(minx - x) / b);
  if(x < minx)shift(x,y,a,b,sign_b);
  if(x > maxx)return 0;
  ll l0 = x;
  
  shift(x,y,a,b,(maxx - x)/b);
  if(x > maxx)shift(x,y,a,b,-sign_b);
  ll r0 = x;
  
  shift(x,y,a,b,-(miny - y) / a);
  if(y < miny)shift(x,y,a,b,-sign_a);
  if(y > maxy)return 0;
  ll l1 = x;
  
  shift(x,y,a,b,-(maxy - y)/a);
  if(y > maxy)shift(x,y,a,b,sign_a);
  ll r1 = x;
  
  if(l1>r1)swap(l1,r1);
  ll l = max(l0,l1);
  ll r = min(r0,r1);
  if(l > r)return 0;
  return (r - l) / abs(b) + 1;
}
//End Constrained Diophantine code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}