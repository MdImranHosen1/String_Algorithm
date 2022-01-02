#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<ll> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define     YES   printf("YES\n")
#define     NO    printf("NO\n")
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)

const int lim = 1048576;
const int Inf           = (int)2e9 + 5;
const ll  Lnf           = (ll)2e18 + 5;
const int N             = 5e5 + 5;
const int NN            = 1e6 + 5;
ll dp[1000001];
ll inverse[1000001];
ll power(ll a, ll m)
{
	ll result = 1;
	while (m)
	{
		if (m & 1)
		{
			result = (a * result) % mod;
		}
		m >>= 1;
		a = (a * a) % mod;
	}
	return result;
}
//ok
ll hashsubstring(string s)
{
	ll hash = 31;
	ll power = 1;
	ll value = 0;

	for (char ch : s)
	{
		value = (value + power * (ch - 'a' + 1)) % mod;
		power = (hash * power) % mod;
	}
	return value;
}
//ok
void stringHash( string s)
{
	ll p_power = 1;
	ll hash = 31;
	dp[0] = s[0] - 'a' + 1;
	inverse[0] = 1;
	for (ll i = 1; i < s.size(); i++)
	{
		char ch = s[i];
		p_power = (p_power * hash) % mod;
		inverse[i] = power(p_power, mod - 2);
		dp[i] = (dp[i - 1] + p_power * (ch - 'a' + 1)) % mod;
	}
}
//ok

ll substringhashrange(ll L , ll R)
{
	int result = dp[R];

	if (L > 0) result = (result - dp[L - 1] + mod) % mod;

	result = (result * inverse[L]) % mod;

	return result;
}

int main() {

	string ss;
	getline(cin,ss);
	ll substringhash = hashsubstring(ss);
	cout << substringhash << endl;
	stringHash(ss);
	int q; cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		cout << substringhashrange(l, r) << endl;
	}

}



