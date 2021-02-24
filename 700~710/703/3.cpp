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
#include<numeric>
#include<cstdlib>
#include<ctime>
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;
typedef std::vector<std::vector<int>> vvi;

using namespace std;

template<class T,class T2>
inline bool chkmax(T &x,const T2 &y){return x<y?(x=y,1):0;}
template<class T,class T2>
inline bool chkmin(T &x,const T2 &y){return x>y?(x=y,1):0;}

int n;
map<pii,int> qq;

int query(int l,int r) {
	if (l>=r) return -1;
	if (qq.count({l,r}))  return qq[{l,r}];
	cout<<"? "<<l<<' '<<r<<endl<<flush;
	int x; cin>>x;
	qq[{l,r}]=x;
	return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	int l=1,r=n,k,t,mid,nd=1;
	while (1) {
		mid=l+r>>1;
		if (l+1>=r) break;
		if (nd) k=query(l,r);
		if (k>mid) {
			t=query(mid+1,r);
			if (t==k) l=mid+1,nd=0;
			else {
				t=query(l+mid>>1,k);
				if (t==k) r=mid,l=l+mid>>1;
				else r=l+mid>>1,r--;
				nd=1;
			}
		} else {
			t=query(l,mid);
			if (t==k) r=mid,nd=0;
			else {
				t=query(k,mid+1+r>>1);
				if (t==k) l=mid+1,r=mid+1+r>>1;
				else l=mid+1+r>>1,l++;
				nd=1;
			}
		}
	}
	int ans;
	if (l==r) ans=l;
	else if (nd) ans=l+r-query(l,r);
	else ans=l+r-k;
	cout<<"! "<<ans<<endl<<flush;
	
	return 0;
}
