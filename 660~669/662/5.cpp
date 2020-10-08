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

const int MOD=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	vector<string> ar(n);
	for (auto &i:ar) cin>>i;

	if (n==1) {cout<<ar[0].size()+1<<endl; return 0;}

	vector<string> pre;
	vector<ll> sum;
	string tmp=ar.back();
	for (int i=0;i<=tmp.size();i++) {
		string s=tmp.substr(0,i)+(i+1<tmp.size()?tmp.substr(i+1):"");
		pre.pb(s);
	}
	sort(pre.begin(),pre.end());
	for (int i=0;i<pre.size();i++) sum.pb(i+1);
		
	for (int i=n-2;i>=1;i--) {
		vector<string> cur_pre;
		vector<ll> cur_sum;
		string tmp=ar[i];
		for (int i=0;i<=tmp.size();i++) {
			string s=tmp.substr(0,i)+(i+1<tmp.size()?tmp.substr(i+1):"");
			if (s<=pre.back()) cur_pre.pb(s);
		}
		if (!cur_pre.size()) {cout<<0<<endl; return 0;}
		sort(cur_pre.begin(),cur_pre.end());
		for (int i=0;i<cur_pre.size();i++) {
			string s=cur_pre[i];
			int lo=lower_bound(pre.begin(),pre.end(),s)-pre.begin();
			cur_sum.pb(sum.back()-(lo?sum[lo-1]:0));
			if (i) cur_sum[i]+=cur_sum[i-1];
			cur_sum[i]+=MOD,cur_sum[i]%=MOD;
		}
		pre.resize(0); swap(pre,cur_pre);
		sum.resize(0); swap(sum,cur_sum);
	}
	ll ans=0;
	tmp=ar[0];
	for (int i=0;i<=tmp.size();i++) {
		string s=tmp.substr(0,i)+(i+1<tmp.size()?tmp.substr(i+1):"");
		if (s>pre.back()) continue;
		int lo=lower_bound(pre.begin(),pre.end(),s)-pre.begin();
		ans+=sum.back()-(lo?sum[lo-1]:0);
		ans+=MOD,ans%=MOD;

	}
	cout<<ans<<endl;
}

