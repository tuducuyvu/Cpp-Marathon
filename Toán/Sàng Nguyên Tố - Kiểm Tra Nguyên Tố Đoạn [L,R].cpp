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
bool not_prime[maxn], not_range_prime[maxn];
vector<int> primes;

//Prime sieve code
void sieve_is_prime() // O( n * log(n) )
{
  not_prime[0] = not_prime[1] = 1;//   1 = true
  for(ll i = 2;i<maxn;i++)
  {
    if(!not_prime[i])
    {
      primes.pb(i);
      for(ll j = i * i;j<maxn;j+=i)not_prime[j] = 1;
    }
  }
}
//End Prime sieve code

//Prime sieve range code
void sieve_range(ll l,ll r) // O( range * log(range) + sqrt(r) )  // r <= 1e12
{
  for(ll k : primes)
  {
    if(k * k > r)break;
    ll i = l - l % k;
    if(i < l)i+=k;
    if(i == k)i+=k;
    for(;i<=r;i+=k)
    {
      not_range_prime[i-l] = 1;
    }
  }
}
//End Prime sieve range code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve_is_prime();
    sieve_range(10,100);
    for(int i = 10;i<=100;i++)
    {
      cout<<i<<' '<<not_range_prime[i-10]<<'\n';
    }
    
    return 0;
}