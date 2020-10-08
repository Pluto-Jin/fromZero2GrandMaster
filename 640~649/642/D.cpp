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
		int n,cnt=1; cin>>n;
		vi ar(n);
		priority_queue<pii> pq;
		pq.push(mp(n,0));
		while (pq.size()) {
			vi tmp;
			int len=pq.top().fi;	
			while (pq.size() and pq.top().fi==len) tmp.pb(pq.top().se),pq.pop();
			sort(tmp.begin(),tmp.end());
			for (auto i:tmp) {
				int pos=(len-1)/2+i,r=len/2,l=len-r-1;
				ar[pos]=cnt++;
				if (l) pq.push(mp(l,i));
				if (r) pq.push(mp(r,pos+1));
			}
		}
		for (auto i:ar) cout<<i<<' '; cout<<endl;
	}
}

