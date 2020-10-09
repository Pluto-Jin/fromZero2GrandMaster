#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
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

const int N=5e5+1;
int a[N];

ll solve(int l,int r) {
	if (l==r) return 0;
	int mid=l+r>>1;
	ll res=solve(l,mid)+solve(mid+1,r);
	vi tmp;
	int p1=l,p2=mid+1;
	while(p1<=mid and p2<=r) {
		if (a[p1]>a[p2]) tmp.pb(a[p2++]);
		else res+=p2-mid-1,tmp.pb(a[p1++]);
	}
	if (p1>mid) while (p2<=r) tmp.pb(a[p2++]);
	if (p2>r) while (p1<=mid) res+=r-mid,tmp.pb(a[p1++]);
	for (int i=0;i<tmp.size();i++) a[l+i]=tmp[i];
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	while (1) {
		int n; cin>>n;
		if (!n) break;
		for (int i=0;i<n;i++) cin>>a[i];
		cout<<solve(0,n-1)<<endl;
	}
}
