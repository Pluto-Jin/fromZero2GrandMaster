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

	int n,h,m,k; cin>>n>>h>>m>>k;
	vii ar(n);
	for (int i=0;i<n;i++) {
		int h,m; cin>>h>>m;
		ar[i]=mp(m,i);
	}
	sort(ar.begin(),ar.end());

	int mi=1e9,ans;
	for (int i=0;i<n;i++) {
		int ed=ar[i].fi,t=ed-k,cnt,x,x1,p;		
		if (t>=0) cnt=upper_bound(ar.begin(),ar.end(),mp(t,(int)1e9))-ar.begin(),x=i-cnt;
		else t=(m+t)%m,cnt=upper_bound(ar.begin(),ar.end(),mp(t,(int)1e9))-ar.begin(),x=n+i-cnt;
		ed+=m/2,ed%=m,t=ed-k,p=lower_bound(ar.begin(),ar.end(),mp(ed,0))-ar.begin();
		if (t>=0) cnt=upper_bound(ar.begin(),ar.end(),mp(t,(int)1e9))-ar.begin(),x1=p-cnt;
		else t=(m+t)%m,cnt=upper_bound(ar.begin(),ar.end(),mp(t,(int)1e9))-ar.begin(),x1=n+p-cnt;
		if (x+x1<mi) ans=min(t,(t+m/2)%m),mi=x+x1;

		t=ar[i].fi;
		if (t+k<m) cnt=lower_bound(ar.begin(),ar.end(),mp(t+k,0))-ar.begin(),x=cnt-i-1;
		else cnt=lower_bound(ar.begin(),ar.end(),mp((t+k)%m,0))-ar.begin(),x=cnt+n-i-1;
		t+=m/2,t%=m,p=upper_bound(ar.begin(),ar.end(),mp(t,(int)1e9))-ar.begin()-1;
		if (t+k<m) cnt=lower_bound(ar.begin(),ar.end(),mp(t+k,0))-ar.begin(),x1=cnt-p-1;
		else cnt=lower_bound(ar.begin(),ar.end(),mp((t+k)%m,0))-ar.begin(),x1=cnt+n-p-1;
		if (x+x1<mi) ans=min(t,(t+m/2)%m),mi=x+x1;
	}
	vi res;
	for (int i=0;i<n;i++) {
		if (ar[i].fi>ans and ar[i].fi<ans+k) res.pb(ar[i].se+1);
		else if (ans+m/2+k<m) {
			if (ar[i].fi>ans+m/2 and ar[i].fi<ans+m/2+k) res.pb(ar[i].se+1);
		} else {
			if (ar[i].fi>ans+m/2 or ar[i].fi<(ans+m/2+k)%m) res.pb(ar[i].se+1);
		}
	}
	cout<<res.size()<<' '<<min(ans+k,(ans+m/2+k)%m)<<endl;
	for (auto i:res) cout<<i<<' ';
	cout<<endl;
}

