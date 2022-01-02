#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
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

void rabin_karp(string& T, string& P)
{
    int ps = P.size();
    int ts = T.size();
    int prime = 227;
    int q =256;
    int nexthash = 1;
    int hashp = 0;
    int hasht = 0;

    for (int i = 0; i < ps - 1; ++i)
    {
        nexthash = (nexthash * q) % prime;
    }
    for (int i = 0; i < ps; ++i)
    {
        hasht = (hasht * q + T[i]) % prime;
        hashp = (hashp * q + P[i]) % prime;
    }

    for (int i = 0; i < ts - ps + 1; ++i)
    {
        if (hashp == hasht)
        {
            int found = 1;

            for (int j = 0; j < ps; ++j)
            {
                if (P[j] != T[i + j])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)cout << "Item found at position " << i+1 << endl;
        }
        if (i < ts - ps)
        {
            hasht = (q * (hasht - T[i] * nexthash) + T[i + ps]) % prime;
            if (hasht < 0)
            {
                hasht+=prime;
            }
        }
    }


}

int main() {

    string txt, pat;
    getline(cin, txt);
    getline(cin, pat);
    int q = 101;
    rabin_karp(txt, pat);
    return 0;
}


