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
		int n,cnt=0,ans=0; cin>>n;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (x%2==i%2) continue;
			if (x%2) cnt++;
			else cnt--,ans++;
		}
		cout<<(cnt?-1:ans)<<endl;
	}
}

