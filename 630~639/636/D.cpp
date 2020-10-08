#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef long long ll;

const int N=1e5+1,K=4e5+2;
int n,k,l[N],r[N],sum[K];

bool compare(pii a,pii b) {
	if (a.se!=b.se) return a.se<b.se;
	else return a.fi<b.se;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int ans=1e9;
		memset(sum,0,sizeof(sum));
		cin>>n>>k;
		vi ar(n);
		vii pi(n/2);
		for (auto &i:ar) cin>>i;
		for (int i=0;i<n/2;i++) {
			sum[ar[i]+ar[n-1-i]]++;
			pi[i]=mp(1+min(ar[i],ar[n-1-i]),k+max(ar[i],ar[n-1-i]));
		}
		sort(pi.begin(),pi.end());

		priority_queue<int,vi,greater<int>> pq;
		for (int i=pi[0].fi,p=0;i<=k*2;) {
			while (!pq.empty() and pq.top()<i) pq.pop();
			while (p<n/2 and pi[p].fi==i) pq.push(pi[p++].se);
			//cout<<pq.size()<<' '<<i<<endl;
			int cur=(n/2-pq.size())*2+pq.size()-sum[i];
			//cout<<cur<<endl;
			ans=min(ans,cur);
			i++;
		}
		cout<<ans<<endl;
	}
}

