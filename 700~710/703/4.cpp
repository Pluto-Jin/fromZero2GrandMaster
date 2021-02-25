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

const int N=2e5+1;
int a[N],mi[N],n,k;

bool check(int mid) {
	for (int i=1,cur=0;i<=n;i++) {
		if (a[i]>=mid) cur++;
		else cur--;
		mi[i]=min(mi[i-1],cur);
		if (i>=k and cur-mi[i-k]>0) return true;
	}	
	return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	int lo=1,hi=n+1;
	while (lo<hi-1) {
		int mid=lo+hi>>1;
		if (check(mid)) lo=mid;
		else hi=mid;
	}
	cout<<lo<<endl;
	
	return 0;
}
