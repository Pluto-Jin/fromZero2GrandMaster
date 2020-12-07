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

const int N=2e5+1;
int n,fen[N]; 

void update(int x,int v) {for(;x<=n;x+=x&-x)fen[x]+=v;}
int query(int x) {int res=0;for(;x;x-=x&-x)res+=fen[x];return res;}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	string s; cin>>n>>s;
	vi pos[26];
	for (int i=0;i<n;i++) pos[s[i]-'a'].pb(i+1);
	for (int i=0;i<26;i++) reverse(pos[i].begin(),pos[i].end());
	reverse(s.begin(),s.end());
	ll ans=0;
	for (int i=0;i<n;i++) {
		int cur=pos[s[i]-'a'].back(); pos[s[i]-'a'].ppb();
		ans+=query(n)-query(cur);
		update(cur,1);	
	}
	cout<<ans<<endl;
		
	return 0;
}
