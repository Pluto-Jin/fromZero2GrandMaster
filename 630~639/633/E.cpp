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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--)	{
		ll n; cin>>n;
		int cur=1;
		while (n>(1ull<<2*cur)-1) cur++;
		cur--;
		n-=1ll<<2*cur;
		int mod=n%3;
		n/=3;
		ll a=(1ll<<2*cur)+n,tmp=a;
		if (mod==0) cout<<a<<endl;
		else {
			ll b=0;
			int cnt=0,x;
			while (tmp) {
				switch (tmp&3) {
					case 0: x=0;break;
					case 1: x=2;break;
					case 2: x=3;break;
					case 3: x=1;break;
				}	
				b|=1ll*x<<2*cnt;
				cnt+=1;
				tmp>>=2;
			}
			if (mod==1) cout<<b<<endl;
			if (mod==2) cout<<(a^b)<<endl;
		}
	}
}

