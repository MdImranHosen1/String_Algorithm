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

void kmp(string& text,string& pat,int lps[])
{
	int tss=text.size();
	int pss=pat.size();
	int i=0,j=0;
	while(i<tss)
	{
		if(text[i]==pat[j])
		{
			i++,j++;
			if(j==pss)
			{
				cout<<"Item found at position:"<<i-j<<endl;
				j=lps[j-1];
			}
		}
		else 
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

void conputeLPSarray(string& s,int lps[])
{
	int len=0;
	int ps=s.size();
	int i=1;
	lps[0]=0;
	while(i<ps)
	{
		if(s[len]==s[i])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else 
			{
				i++;
			}
			
		}
	}
}
int main()
{
	string text,pattern;
	cin>>text>>pattern;
	int lps[pattern.size()];
	memset(lps,0,sizeof lps);
	conputeLPSarray(pattern,lps);
	kmp(text,pattern,lps);

}


