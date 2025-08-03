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
int small_prime_divisor[maxn];

void sieve_prime_divisor()
{
  small_prime_divisor[0] = small_prime_divisor[1] = 0;
  
  for(ll i = 2;i<maxn;i++)
  {
    if(small_prime_divisor[i] == 0)
    {
      small_prime_divisor[i] = i;
      for(ll j = i * i;j<maxn;j+=i)if(small_prime_divisor[j]==0) small_prime_divisor[j] = i;
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve_prime_divisor();
    
    
    return 0;
}