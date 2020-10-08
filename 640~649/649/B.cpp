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
		deque<int> s;
		int sg=0;
		for (int i=0;i<n;i++) {
			int x; cin>>x;
			if (s.empty()) s.pb(x);
			else {
				int tmp=s.back();
				if (!sg) sg=(x>tmp?1:-1);
				else {
					if (sg==1 and x>tmp or sg==-1 and x<tmp) s.ppb();
					else sg=-sg;
				}
				s.pb(x);
			}	
		}
		cout<<s.size()<<endl;
		while (s.size()) cout<<s.front()<<' ', s.ppf();
		cout<<endl;
	}
}

