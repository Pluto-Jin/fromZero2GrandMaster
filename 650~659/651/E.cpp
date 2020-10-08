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

	int n; cin>>n;
	string s,t; cin>>s>>t;
	int cnt=0;
	for (int i=0;i<n;i++) {
		if (s[i]=='1') cnt++;
		if (t[i]=='1') cnt--;
	}
	if (cnt) cout<<-1<<endl;
	else {
		int ans=0,cur=0,ch=-1;
		vi tmp;
		for (int i=0;i<n;i++) {
			if (s[i]!=t[i]) {
				if (cur and s[i]!=ch) tmp.pb(cur),cur=0;
				ch=s[i],cur++;
			}
		}
		tmp.pb(cur);
		int cnt[2]={0};
		for (int i=0;i<tmp.size();i++) {
			int id=i%2;
			cnt[id]+=tmp[i];
			cnt[1-id]=max(0,cnt[1-id]-tmp[i]);
			ans=max(cnt[id]+cnt[1-id],ans);
		}
		cout<<ans<<endl;
	}
}

