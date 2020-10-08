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

const int N=2e5+1;
int id[N];
bool npr[N];
vi pr;

ll fpow(ll a,ll b) {
	ll res=1;
	while (b) {
		if (b%2) res*=a;
		b/=2;
		a*=a;
	}
	return res;
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i=2;i<N;i++) {
		if (!npr[i]) {
			id[i]=pr.size();
			pr.pb(i);
			for (int j=i*2;j<N;j+=i) npr[j]=1;
		}
	}

	int n; cin>>n;
	vi mi1(pr.size()),mi2(pr.size()),cnt(pr.size());
	for (auto &i:mi1) i=1e9;
	for (auto &i:mi2) i=1e9;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		for (int j=2;j<=x;j++) {
			if (!npr[x]) j=x; 
			if (x%j) continue;
			int tmp=0,ind=id[j];
			while (x%j==0) x/=j,tmp++;
			cnt[ind]++;
			if (tmp<=mi1[ind]) mi2[ind]=mi1[ind],mi1[ind]=tmp;
			else if (tmp<mi2[ind]) mi2[ind]=tmp;
			if (x==1) break;
		}
	}
	ll ans=1;
	for (int j=0;j<pr.size();j++) {
		if (n-cnt[j]==1) ans*=fpow(pr[j],mi1[j]);
		if (n-cnt[j]==0) ans*=fpow(pr[j],mi2[j]);
	}
	cout<<ans<<endl;
}

