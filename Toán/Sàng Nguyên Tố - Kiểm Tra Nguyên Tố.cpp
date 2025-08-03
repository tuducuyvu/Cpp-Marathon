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
bool not_prime[maxn];

void sieve_is_prime()
{
  not_prime[0] = not_prime[1] = 1;//   1 = true
  for(ll i = 2;i<maxn;i++)
  {
    if(!not_prime[i])
    {
      for(ll j = i * i;j<maxn;j+=i)not_prime[j] = 1;
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve_is_prime();
    
    
    return 0;
}