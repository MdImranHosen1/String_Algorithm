#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
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


ll CreateHeshValue(string s)
{
	ll hash = 31;
	ll power_value = 1;
	ll hashValue = 0;
	for (char c : s) {
		hashValue = (hashValue + (c - 'a' + 1) * power_value) % mod;
		power_value = (power_value * hash) % mod;
	}
	return hashValue;

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int test = 1;
	while (test)
	{
		string s;
		getline(cin, s);
		if (s == ".")
		{
			test = false;
		}
		else
		{
			cout << CreateHeshValue(s) << endl;
		}
	}
	return 0;
}


