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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		set<int> vis,pr; vis.insert(n);
		int tmp=n;
		for (ll i=2;i*i<=tmp;i++) if (tmp%i==0) {
			pr.insert(i);
			while (tmp%i==0) tmp/=i;
		}
		if (tmp!=1) pr.insert(tmp);
		for (ll i=2;i*i<=n;i++) {
			if (n%i==0) {
				if (!pr.count(i)) vis.insert(i);
				if (!pr.count(n/i)) vis.insert(n/i);
			}
		}
		vi p; for (auto i:pr) p.pb(i);
		vi ans(p.size()*2);
		for (int i=0;i<p.size();i++) ans[i*2]=p[i];
		int ok=1;
		if (p.size()==2) {
			ans[1]=ans[0]*ans[2]; vis.erase(ans[1]);
			ll x=1ll*p[0]*p[0]*p[1],y=1ll*p[0]*p[1]*p[1];
			if (n%x==0) ans[3]=x,vis.erase(x);
			else if (n%y==0) ans[3]=y,vis.erase(y);
			else ok=0;	
		} else if (p.size()!=1) {
			ans.back()=ans[0]*ans[ans.size()-2]; vis.erase(ans.back());
			for (int i=1;i<ans.size()-1;i+=2) ans[i]=ans[i-1]*ans[i+1],vis.erase(ans[i]);
		}
		for (int i=0;i<ans.size();i+=2) {
			cout<<ans[i]<<' ';
			vi tmp;
			for (auto x:vis) if (x%ans[i]==0) cout<<x<<' ',tmp.pb(x);
			for (auto x:tmp) vis.erase(x);
			if (i+2!=ans.size()) cout<<ans[i+1]<<' ';
			else if (ok and p.size()!=1) cout<<ans[i+1]<<' ';
		}
		cout<<endl;
		cout<<1-ok<<endl;
	}
}
