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
	while (t--) {
		ll l,r,m; cin>>l>>r>>m;
		int a,b,c,tmp;
		for (a=l;a<=r;a++) {
			int x=m%a,y=a-x;
			if (a<=m and x<=r-l) {tmp=x;break;}
			if (y<=r-l) {tmp=-y;break;}
		}
		if (tmp>0) c=l,b=l+tmp;
		else b=l,c=l-tmp;
		cout<<a<<' '<<b<<' '<<c<<endl;
	}
}

