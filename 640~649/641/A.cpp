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
		int n,k; cin>>n>>k;
		if (n%2) {
			int tmp=n;
			for (int i=3;i<=sqrt(n);i+=2) {
				if (n%i==0) {tmp=i;break;}
			} 
			n+=tmp;
			k--;
		}
		cout<<2ll*k+n<<endl;
	}
}

