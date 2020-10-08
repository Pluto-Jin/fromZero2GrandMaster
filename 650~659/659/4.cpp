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
		int n; cin>>n;
		int cnt[31]={0};
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			for (int i=0;i<31;i++) if (x&(1<<i)) cnt[i]++;
		}
		int ans=0;
		for (int i=30;!ans and i>=0;i--) {
			if (cnt[i]%2==0) continue;
			if (cnt[i]%4==1 or n%2==0) ans=1;
			else ans=-1; 
		}
		if (!ans) cout<<"DRAW"<<endl;
		else cout<<(ans==1?"WIN":"LOSE")<<endl;
	}
}

