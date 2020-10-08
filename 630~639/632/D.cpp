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

int n,k,sum;
vector<bool> ar;
vvi ans;

void solve() {
	while (1) {
		int ok=0;
		vi tmp;
		for (int i=1;i<n;i++) {
			if (ar[i] and !ar[i-1]) {
				ok=1;
				tmp.pb(i-1);
				ar[i]=0;
				ar[i-1]=1;
				i++;
			}
		}	
		if (!ok or ans.size()>k) break;
		else ans.pb(tmp),sum+=tmp.size();
	}
	if (ans.size()>k or sum<k) {
		cout<<-1<<endl;
		exit(0);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin>>n>>k;
	ar.resize(n);
	string s; cin>>s;
	for (int i=0;i<n;i++) ar[i]=s[i]=='L';
	solve();
	k-=ans.size();
	for (auto i:ans) {
		if (!k) {
			cout<<i.size()<<' ';
			for (auto j:i) cout<<j+1<<' ';
			cout<<endl;
		} else {
			for (int j=0;j<i.size();j++) {
				if (k) {
					cout<<1<<' '<<i[j]+1<<endl;
					if (j!=i.size()-1) k--;
				} else {
					cout<<i.size()-j<<' ';
					for (;j<i.size();j++) cout<<i[j]+1<<' ';
					cout<<endl;
					break;
				}
			}
		}
	}
}

