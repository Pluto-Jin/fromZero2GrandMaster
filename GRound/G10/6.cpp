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

	int n; cin>>n;
	ll sum=0;
	for (int i=0;i<n;i++) {
		ll x; cin>>x;
		sum+=x;
	}
	ll lo=0,hi=1e12;
	while (lo<hi-1) {
		ll mid=lo+hi>>1,tmp=(mid+mid+n-1)*n/2;
		if (tmp<=sum) lo=mid;
		else hi=mid;
	}
	ll cnt=sum-(lo+lo+n-1)*n/2;
	for (int i=0;i<n;i++) {
		ll tmp=lo+i;
		if (cnt) tmp++,cnt--;
		cout<<tmp<<' ';
	}
	cout<<endl;
}

