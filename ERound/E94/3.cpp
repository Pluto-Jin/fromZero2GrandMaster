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

int n;
vi ar;

ll solve(int d=0,int l=0,int r=n-1) {
	if (l==r) return ar[l]!=d;
	int mi=1e9+1,cnt=0;
	for (int i=l;i<=r;i++) {
		if (ar[i]<mi) cnt=0,mi=ar[i];
		if (ar[i]==mi) cnt++;
	}
	ll res=1ll*(mi-d);
	for (int bg,i=l;i<=r;i++) {
		if (ar[i]!=mi) {
			if (i==l or ar[i-1]==mi) bg=i;
			if (i==r) res+=solve(mi,bg,i);
		}
		if (ar[i]==mi) if (i!=l and ar[i-1]!=mi) res+=solve(mi,bg,i-1);
		if (res>=r-l+1) break;
	}
	return min(res,r-l+1ll);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n; ar.resize(n);
	for (auto &i:ar) cin>>i;

	cout<<solve()<<endl;
}

