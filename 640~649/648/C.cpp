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
int cnt[N],ar[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n; cin>>n;
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		ar[x]=i;
	}
	for (int i=0;i<n;i++) {
		int x; cin>>x;
		cnt[(ar[x]-i+n)%n]++;
	}
	int ans=0;
	for (int i=0;i<n;i++) ans=max(ans,cnt[i]);
	cout<<ans<<endl;
}

