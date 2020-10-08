#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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

const int N=2e5+1;
bool npr[N];
vi pr,fac;

void sieve() {
	for (int i=2;i<N;i++) {
		if (!npr[i]) {
			pr.pb(i);
			for (int j=i+i;j<N;j+=i) npr[j]=1;
		}
	}
}

int query(int x=1,int t=1) {
	char c=(t?'A':'B');
	cout<<c<<' '<<x<<endl<<flush;
	cin>>x; return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	sieve();
	int p=0,cnt=n;
	vi tmp;
	while (pr[p]<=n) {
		cnt-=query(pr[p],0);
		tmp.pb(pr[p]);
		if (p and p%97==0 or pr[p+1]>n) {
			int cur=query();
			if (cur!=cnt) for (auto i:tmp) { 
				if (query(i)) fac.pb(i),cnt++;
				if (cnt==cur) break;
			}
			tmp.resize(0);
			if (pr[p+1]>n) break; 
		}
		p++;
	}
	int ans=1;
	for (auto i:fac) {
		ll cur=1ll*i*i,ma=i;
		while (cur<=n) {
			if (query(cur)) ma=cur;
			cur*=i;
		}
		ans*=ma;
	}
	cout<<'C'<<' '<<ans<<endl<<flush;
}
