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

ll bin_mul(ll a,ll b,const ll &mod) // O( log(b) )
{
  a %= mod;
  ll ans = 0;
  for(;b;b>>=1)
  {
    if(b&1)ans = (ans + a) % mod;
    a = (a + a) % mod;
  }
  return ans;
}

ll bin_pow(ll a,ll b,const int &mod) // O( log(b) )
{
  a %= mod;
  ll ans = 1;
  for(;b;b>>=1)
  {
    if(b&1)ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}

ll bin_pow_large_mod(ll a,ll b,const ll &mod) // O( log(b) * log(mod) )
{
  a %= mod;
  ll ans = 1;
  for(;b;b>>=1)
  {
    if(b&1)ans = bin_mul(ans , a , mod);
    a = bin_mul(a , a , mod);
  }
  return ans;
}

const vector<int> check_set = {2,3,5,7,11,13,17,19,23,29,31,37};

bool check_composite_int(int a,int mod,int t,int m) // O( log(n) )
{
  ll n = bin_pow(a,m,mod);
  if(n == 1 || n == mod-1)return 0;
  while(t--)
  {
    n = n * n % mod;
    if(n == mod-1)return 0;
  }
  return 1;
}

bool prime_check_int(int n) // O( log(n) ^ 2 )
{
  for(int k : check_set)if(n == k)return 1;
  if(n < 41)return 0;
  
  int m = n - 1;
  int t = __builtin_ctz(m);
  m>>=t;
  for(int k : check_set)if(check_composite_int(k,n,t,m))return 0;
  return 1;
}

bool check_composite_longlong(ll a,ll mod,int t,ll m) // O( log(n) )
{
  ll n = bin_pow_large_mod(a,m,mod);
  if(n == 1 || n == mod-1)return 0;
  while(t--)
  {
    n = bin_mul(n,n,mod);
    if(n == mod-1)return 0;
  }
  return 1;
}

bool prime_check_longlong(ll n) // O( log(n) ^ 2 )
{
  for(int k : check_set)if(n == k)return 1;
  if(n < 41)return 0;
  
  ll m = n - 1;
  int t = __builtin_ctzll(m);
  m>>=t;
  for(int k : check_set)if(check_composite_longlong(k,n,t,m))return 0;
  return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}