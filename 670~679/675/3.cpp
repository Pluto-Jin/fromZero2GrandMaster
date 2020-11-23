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
#include<iomanip>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
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

const int N=1e5+1,MOD=1e9+7;
ll ten[N],cnt[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string s; cin>>s;
	ten[0]=1;
	for (int i=1;i<=1e5;i++) ten[i]=10*ten[i-1]%MOD,cnt[i]=(cnt[i-1]+ten[i-1]*i)%MOD;
	ll cur=0,ans=0;
	for (int i=0;i<(int)s.size()-1;i++) {
		cur=(s[i]-'0');
		int len=(int)s.size()-i-1;
		ans+=cur*cnt[len]%MOD;
		ans%=MOD;
	}
	cur=0;
	for (int i=0;i<(int)s.size()-1;i++) {
		cur=ten[i]*(s[s.size()-1-i]-'0');
		int len=(int)s.size()-i-1;
		ans+=cur*((1ll*len*(len+1)/2)%MOD)%MOD;
		ans%=MOD;
	}
	cout<<ans<<endl;
	
	return 0;
}
