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

ll bin_pow(ll a,ll b,const int &mod)
{
  ll ans = 1;
  for(;b;b>>=1)
  {
    if(b&1)ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 3 mũ 4 % 5
    cout<<bin_pow(3,4,5);
    
    return 0;
}