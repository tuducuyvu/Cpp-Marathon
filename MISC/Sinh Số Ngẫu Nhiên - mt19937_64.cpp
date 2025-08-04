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

//Random Number Generator code
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random_range(ll l,ll r) // O(1)
{
  return uniform_int_distribution<ll>(l,r)(rng);
}
//End Random Number Generator code

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout<<random_range(12987,1271292698);
    
    return 0;
}