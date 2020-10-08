#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

const int MOD=1e9+7,N=3e6+5;
char ar[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int x; cin>>x;
		string s; cin>>s;
		for (int i=0;i<s.size();i++) ar[i]=s[i];
		ll len=s.size();
		int ok=len>=x;
		for (int cur=0,pos=len;cur<x;) {
			int cnt=ar[cur++]-'1';
			if (!ok) for (int k=0;k<cnt;k++) 
				for (int i=0;i<len-cur;i++) ar[pos++]=ar[cur+i];
			len+=(MOD+len-cur)%MOD*cnt%MOD;
			if (len>=x) ok=1;
			len%=MOD;
		}
		cout<<len<<endl;
	}
}

