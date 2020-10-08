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
		int a,b; cin>>a>>b;
		if (a>b) swap(a,b);
		int lo=0,hi=b;
		while (lo<hi-1) {
			int mid=(hi-lo)/2+lo;
			if (a>=mid and (a+b)/3>=mid) lo=mid;
			else hi=mid;
		}
		cout<<lo<<endl;
	}
}

