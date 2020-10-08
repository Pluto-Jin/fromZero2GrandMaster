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
		vi ar(n);
		for (auto &i:ar) cin>>i;
		stack<int> s;
		ll ans=0,h,cur=0;
		for (auto i:ar) {
			if (s.empty() or i>s.top()) {
				ans+=cur;
				while (s.size()) s.pop();
				s.push(h=i); cur=0;
			} else {
				s.push(i);
				cur=h-i;
			}
		}
		cout<<ans+cur<<endl;
	}
}

