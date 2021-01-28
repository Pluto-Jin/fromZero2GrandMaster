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

int pr[10]={2,3,5,7,11,13,17,19,23,29},n,ma,ans;

void dfs(int at,int pre,int cnt,ll cur) {
	if (chkmax(ma,cnt)) ans=cur;
	if (ma==cnt) chkmin(ans,cur);
	if (1ll*cur*pr[at]>n) return;
	for (int i=1;i<=pre;i++) {
		cur*=pr[at];
		if (cur<=n) dfs(at+1,i,cnt*(1+i),cur);
		else break;
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n;
	dfs(0,31,1,1);
	cout<<ans<<endl;
	
	return 0;
}
