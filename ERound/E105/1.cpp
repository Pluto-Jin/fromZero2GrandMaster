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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	char tt[]={'(',')'};
	while (t--) {
		string s; cin>>s;
		int okk=0;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) for (int k=0;k<2;k++) {
			string tmp;
			for (auto c:s) {
				if (c=='A') tmp+=tt[i];
				else if (c=='B') tmp+=tt[j];
				else tmp+=tt[k];
			}
			stack<char> stk;
			int ok=1;
			for (auto c:tmp) {
				if (c=='(') stk.push(c);
				else if (stk.empty()) {ok=0;break;}
				else stk.pop();
			} 
			if (!ok or stk.size()) continue;
			if (ok) {okk=1;break;}
		}
		cout<<(okk?"YES":"NO")<<endl;
	}
	
	return 0;
}
