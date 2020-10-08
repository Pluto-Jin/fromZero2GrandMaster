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

	int t; cin>>t;
	while (t--) {
		int n,x; cin>>n>>x;
		int cur=0,bg=0,ans=0;
		for (int i=1;i<=n;i++) {
			int tmp; cin>>tmp;
			cur=(tmp+cur)%x;
			if (!bg and cur) bg=i;
			if (cur) ans=i;
			else if (bg) ans=max(ans,i-bg);
		}
		cout<<(ans?ans:-1)<<endl;
	}
}

