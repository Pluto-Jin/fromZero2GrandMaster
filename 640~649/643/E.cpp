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

int n,a,r,m; 
vi ar;

ll cal(int h) {
	ll less=0,more=0;
	for (int i=0;i<n;i++) {
		if (ar[i]<h) less+=h-ar[i];
		if (ar[i]>h) more+=ar[i]-h;
	}
	return min(less,more)*m+(more>less?(more-less)*r:(less-more)*a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>a>>r>>m;
	m=min(m,a+r);
	ar.resize(n);
	int mi=1e9,ma=0;
	for (auto &i:ar) cin>>i,mi=min(mi,i),ma=max(ma,i);
	int lo=mi-1,hi=ma+1;
	while (lo<hi-2) {
		int mid=(hi-lo)/2+lo;
		if (cal(mid)>cal(mid+1)) lo=mid;
		else hi=mid+1;
	}
	cout<<cal(lo+1)<<endl;
}

