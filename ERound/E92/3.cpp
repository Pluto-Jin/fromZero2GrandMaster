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

	int t; cin>>t;
	while (t--) {
		string s; cin>>s;
		int cnt[10]={0},ma=0;
		for (auto i:s) cnt[i-'0']++,ma=max(ma,cnt[i-'0']);
		for (int i=0;i<10;i++) {
			for (int j=i+1;j<10;j++) {
				if (cnt[i]+cnt[j]<=ma) continue;
				int tmp=1,cur;
				for (auto c:s) if (c-'0'==i or c-'0'==j) {cur=c-'0';break;} 
				for (auto c:s) {
					if (c-'0'!=i and c-'0'!=j) continue;
					if (c-'0'!=cur) tmp++,cur=i+j-cur;
				}
				if (tmp%2) tmp--;
				if (tmp>ma) ma=tmp;
			}
		}
		cout<<s.size()-ma<<endl;
	}
}

