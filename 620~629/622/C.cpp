#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define mp make_pair

typedef pair<int,int> pii;
typedef long long ll;

int main() 
{
	int n;
	cin>>n;
	vector<ll> ar;
	ar.resize(n+1);
	for (int i=1;i<=n;i++) cin>>ar[i];
	vector<ll> up,dw;
	up.resize(n+2);
	dw.resize(n+2);

	up[1]=ar[1];
	dw[n]=ar[n];
	deque<pii> dq;
	dq.pb(mp(0,0));
	dq.pb(mp(ar[1],1));
	for (int i=2;i<=n;i++) {
		ll tmp=dq.back().fi;
		if (ar[i]>=tmp) {
			up[i]=up[i-1]+ar[i];
			if (ar[i]==tmp) dq.back().se++;
			else dq.pb(mp(ar[i],i));
		}
		else {
			while (dq.back().fi>ar[i]) dq.ppb();
			up[i]=up[dq.back().se]+(i-dq.back().se)*ar[i];
			dq.pb(mp(ar[i],i));
		}
	}
	dq.clear();
	dq.pb(mp(0,n+1));
	dq.pb(mp(ar[n],n));
	for (int i=n-1;i>=1;i--) {
		ll tmp=dq.back().fi;
		if (ar[i]>=tmp) {
			dw[i]=dw[i+1]+ar[i];
			if (ar[i]==tmp) dq.back().se++;
			else dq.pb(mp(ar[i],i));
		}
		else {
			while (dq.back().fi>ar[i]) dq.ppb();
			dw[i]=dw[dq.back().se]+(dq.back().se-i)*ar[i];
			dq.pb(mp(ar[i],i));
		}
	}

	int ind;
	ll m=0;
	for (int i=1;i<=n;i++) {
		if (up[i]+dw[i]-ar[i]>m) {m=up[i]+dw[i]-ar[i];ind=i;}
	}
	vector<ll> ans;
	ans.resize(n+1);
	ans[ind]=ar[ind];
	ll tmp=ar[ind];
	for (int i=ind;i>=1;i--) {
		if (ar[i]<=tmp) {ans[i]=ar[i];tmp=ar[i];}
		else ans[i]=tmp;
	}
	tmp=ar[ind];
	for (int i=ind;i<=n;i++) {
		if (ar[i]<=tmp) {ans[i]=ar[i];tmp=ar[i];}
		else ans[i]=tmp;	
	}
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;

}
