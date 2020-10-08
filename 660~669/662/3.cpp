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
int n,cnt[N];
vi ar;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		cin>>n;
		ar.resize(0);
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) {
			int x; cin>>x;
			cnt[x]++;
		}
		int ma=0,tmp=0;
		for (int i=1;i<=n;i++) if (cnt[i]>1) ma=max(ma,cnt[i]);
		for (int i=1;i<=n;i++) if (cnt[i]==ma) tmp++;
		cout<<(n-tmp)/(ma-1)-1<<endl;
	}
}

