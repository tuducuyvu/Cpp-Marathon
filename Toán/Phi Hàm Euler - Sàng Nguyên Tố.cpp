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
int phi[maxn];

// Phi Euler code
void sieve_phi_euler() // O( n * log(n) )
{
  for(int i = 1;i<maxn;i++)
  {
    phi[i] = i;
  }
  for(int i = 2;i<maxn;i++)
  {
    if(phi[i] == i)
    {
      for(int j = i;j<maxn;j+=i)phi[j] -= phi[j] / i;
    }
  }
}
//End Phi Euler code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve_phi_euler();
    
    return 0;
}