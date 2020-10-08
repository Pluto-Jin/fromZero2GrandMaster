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
		ll sum=0,d1=0,d2=0,m1=0,m2=0;
		for (int i=0;i<n;i++) {
			if (i%2==0) sum+=ar[i];
			else {
				d1+=ar[i]-ar[i-1],m1=max(m1,d1);
				if (d1<0) d1=0;
				if (i+1<n) d2+=ar[i]-ar[i+1],m2=max(m2,d2);
				if (d2<0) d2=0;
			}
		}
		cout<<sum+max(m1,m2)<<endl;
	}
}

