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


ll ans;
set<int> d,nd,tx,ty;
int mi;

void cal() {
	while (d.size()>tx.size()) {
		int tmp=*d.begin(); d.erase(tmp); nd.insert(tmp);
		ans-=tmp;
	}
	while (d.size()<tx.size() and nd.size()) {
		int tmp=*nd.rbegin(); nd.erase(tmp); d.insert(tmp);
		ans+=tmp;
	}
	while (nd.size() and d.size() and *nd.rbegin()>*d.begin()) {
		int a=*nd.rbegin(),b=*d.begin();
		d.insert(a); d.erase(b);
		nd.insert(b); nd.erase(a);
		ans+=a-b;
	}
}

void add(int t,int p) {
	if (t) {
		tx.insert(p);
		if (!mi) mi=p;
		else nd.insert(max(mi,p)),mi=min(mi,p);
	} else {
		nd.insert(p);
		ty.insert(p);
	}
	ans+=p;
	cal();
}

void del(int t,int p) {
	if (t) {
		tx.erase(p);
		if (mi==p) {
			mi=*tx.begin();
			if (d.count(mi)) ans-=mi,d.erase(mi);
			else nd.erase(mi);	
		} else {
			if (d.count(p)) ans-=p,d.erase(p);
			else nd.erase(p);
		}
	} else {
		ty.erase(p);
		if (d.count(p)) ans-=p,d.erase(p);
		else nd.erase(p);
	}
	ans-=p;
	cal();
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) {
		int x,y; cin>>x>>y;
		if (y<0) del(x,-y);
		else add(x,y);
		cout<<ans<<endl;
	}
}

