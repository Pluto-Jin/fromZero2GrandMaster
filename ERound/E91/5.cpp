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

const int N=2e5+1;
int cnt;
set<int> s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,m; cin>>n>>m;
	vi ar(n+1);
	for (int i=1;i<=n;i++) cin>>ar[i];
	for (int i=1;i<=n;i++) {
		if (ar[i]!=ar[i-1]) cnt++;
		s[ar[i]].insert(i);
	}
	cout<<cnt-1<<endl;
	for (int i=1;i<m;i++) {
		int a,b; cin>>a>>b;
		if (s[a].size()>s[b].size()) swap(s[a],s[b]);
		for (auto i:s[a]) {
			if (s[b].count(i-1)) cnt--;
			if (s[b].count(i+1)) cnt--;
		}
		for (auto i:s[a]) s[b].insert(i);
		swap(s[a],s[b]);
		cout<<cnt-1<<endl;
	}
}

