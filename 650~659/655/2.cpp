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
		int a=1;
		for (int i=2;i<=sqrt(n);i++) {
			if (n%i==0) {
				int tmp=n/i;
				a=tmp*(i-1);
				break;
			}
		}
		cout<<a<<' '<<n-a<<endl;
	}
}

