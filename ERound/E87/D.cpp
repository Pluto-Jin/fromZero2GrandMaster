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

const int N=1e6;
int n,q,ar[2*N];

bool check(int x) {
	int le=0,gr=0,sa=0;
	for (int i=0;i<n+q;i++) {
		if (ar[i]>0) {
			if (ar[i]>x) gr++;
			else if (ar[i]<x) le++;
			else sa++;
		} else {
			if (-ar[i]<=le) le--;
			else if (-ar[i]<=sa+le) sa--;
			else gr--;	
		}
	}
	return !le;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int cnt=0; cin>>n>>q;
	for (int i=0;i<n+q;i++) {
		cin>>ar[i];
		if (ar[i]>0) cnt++;
		else cnt--;
	}
	if (!cnt) cout<<0<<endl;
	else {
		int lo=1,hi=1e6+1;
		while (lo<hi-1) {
			int mid=(lo+hi)/2;
			if (check(mid)) lo=mid;
			else hi=mid;
		}
		cout<<lo<<endl;
	}
}

