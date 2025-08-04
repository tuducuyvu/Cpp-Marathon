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

//Prime check code
bool trial_check(ll n) // O( sqrt(n) )
{
  if(n < 2)return 0; // 0 = false
  for(int k : {2,3,5})
  {
    if(n == k)return 1; // 1 = true
    if(n % k == 0)return 0;
  }
  int i = 0;
  const int next[] = {4,2,4,2,4,6,2,6};
  for(ll k = 7;k*k <= n;k+=next[i++],i%=8)
  {
    if(n % k == 0)
    {
      return 0;
    }
  }
  return 1;
}
//End prime check code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    
    return 0;
}