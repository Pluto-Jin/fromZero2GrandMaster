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

const int N=1e6+1;
int n,m,trie[N][26],cnt[N],ind;

void insert(string &s) {
	int p=0;
	for (auto i:s) {
		int &x=trie[p][i-'a'];
		if (!x) x=++ind;
		p=x;
	}
	cnt[p]++;
}

int query(string &s) {
	int p=0,res=0;
	for (auto i:s) {
		int &x=trie[p][i-'a'];
		if (!x) break;
		res+=cnt[x];
		p=x;
	}
	return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>m;
	for (int i=0;i<n;i++) {
		string s; cin>>s;
		insert(s);
	}
	for (int i=0;i<m;i++) {
		string s; cin>>s;
		cout<<query(s)<<endl;
	}
	
	return 0;
}
