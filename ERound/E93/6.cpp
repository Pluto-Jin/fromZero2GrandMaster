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

const int N=1e6+5;
int n,cnt0[N],cnt1[N],nxt[N];

int gn(int cur,int i) {
	if (cur+i-1>n or cnt1[cur+i-1]-cnt1[cur-1]==i or cnt0[cur+i-1]-cnt0[cur-1]==i) return cur;
	return nxt[cur]=gn(nxt[cur],i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	string s; cin>>s;
	for (int i=0;i<n;i++) {
		if (s[i]=='1' or s[i]=='?') cnt1[i+1]=1+cnt1[i];
		if (s[i]=='0' or s[i]=='?') cnt0[i+1]=1+cnt0[i];
	}
	for (int i=1;i<=n;i++) nxt[i]=i+1;
	for (int i=1;i<=n;i++) {
		int ans=0,cur=1;
		while (cur+i-1<=n) {
			if (cnt1[cur+i-1]-cnt1[cur-1]==i or cnt0[cur+i-1]-cnt0[cur-1]==i) ans++,cur+=i;
			else cur=gn(cur,i);
		}	
		cout<<ans<<' ';
	}
	cout<<endl;
}

