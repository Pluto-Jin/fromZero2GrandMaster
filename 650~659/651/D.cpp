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

	int n,k; cin>>n>>k;
	vi ar(n),xiao(n);
	for (auto &i:ar) cin>>i;
	int lo=0,hi=1e9;
	while (lo<hi-1) {
		int mid=lo+(hi-lo)/2;
		for (int i=0;i<n;i++) xiao[i]=ar[i]<=mid;
		int cur=0,cnt=0,bg,ed;
		for (int i=0;i<n;i++) {
			if (!xiao[i]) cnt+=(cur+1)/2,cur=0;
			else cur++;
		}
		cnt+=(cur+1)/2,cur=0;
		for (int i=0;i<n;i++) {
			if (!xiao[i]) break;
			else cur++;
		}
		bg=cur,cur=0;
		for (int i=n-1;i>=0;i--) {
			if (!xiao[i]) break;
			else cur++;
		}
		ed=cur;
		int tg=k/2;
		if (k%2==0 and bg%2 and ed%2) cnt--; 
		if (k%2 and (bg%2 or ed%2)) cnt--;
		if (cnt>=tg) hi=mid;
		else lo=mid;	
	}
	cout<<hi<<endl;
}

