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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,q; cin>>n>>q;
	set<int> shu,qu;
	map<int,int> cnt;
	vi tmp(n); 
	for (auto &i:tmp) cin>>i,shu.insert(i);
	sort(tmp.begin(),tmp.end());
	for (int i=1;i<n;i++) 
		if (!cnt[tmp[i]-tmp[i-1]]++) qu.insert(tmp[i]-tmp[i-1]);
	cout<<tmp.back()-tmp[0]-(qu.size()?*qu.rbegin():0)<<endl;
	for (int t=0;t<q;t++) {
		int a,x; cin>>a>>x;
		if (a) {
			if (!shu.size());
			else if (x<*shu.begin()) {
				int tmp=*shu.begin()-x; 
				if (!cnt[tmp]++) qu.insert(tmp);
			} else if (x>*shu.rbegin()) {
				int tmp=x-*shu.rbegin();
				if (!cnt[tmp]++) qu.insert(tmp);
			} else {
				auto lb=shu.lower_bound(x);
				int hi=*lb,lo=*(--lb);
				if (!--cnt[hi-lo]) qu.erase(hi-lo);
				if (!cnt[hi-x]++) qu.insert(hi-x);
				if (!cnt[x-lo]++) qu.insert(x-lo);
			}
			shu.insert(x);
		} else {
			shu.erase(x);
			if (!shu.size());
			else if (x<*shu.begin()) {
				int tmp=*shu.begin()-x;
				if (!--cnt[tmp]) qu.erase(tmp);				
			} else if (x>*shu.rbegin()) {
				int tmp=x-*shu.rbegin();
				if (!--cnt[tmp]) qu.erase(tmp);
			} else {
				auto lb=shu.lower_bound(x);
				int hi=*lb,lo=*(--lb);
				if (!cnt[hi-lo]++) qu.insert(hi-lo);
				if (!--cnt[hi-x]) qu.erase(hi-x);
				if (!--cnt[x-lo]) qu.erase(x-lo);
			}
		}
		cout<<(shu.size()?*shu.rbegin()-*shu.begin():0)-(qu.size()?*qu.rbegin():0)<<endl;
	}

}
