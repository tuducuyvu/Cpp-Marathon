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

// bin_pow code
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
//End bin_pow code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    // (3 * 4) % 5
    cout<<bin_mul(3,4,5)<<'\n';
    
    // (3 mũ 4) % 5
    cout<<bin_pow(3,4,5)<<'\n';
    
    // (3410411074017137 mũ 419197317294691) % 10000000000000007
    cout<<bin_pow_large_mod(3410411074017137,419197317294691,10000000000000007)<<'\n';
    
    return 0;
}