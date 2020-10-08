#include "bits/stdc++.h"
using namespace std;

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define mp make_pair
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t; cin>>t;
	while (t--) {
		int n; cin>>n;
		vi ar(n);
		for (int i=0;i<n;i++) cin>>ar[i];
		int ok=1;
		for (int i=1;i<n;i++) {
			if (ar[i]!=ar[i-1]) {
				ok=0;
				break;
			}
		}
		if (ok) {
			cout<<1<<endl;
			for (int i=0;i<n;i++) cout<<1<<' ';
			cout<<endl;
			continue;
		}
		if (n%2==0) {
			cout<<2<<endl;
			for (int i=0;i<n/2;i++) cout<<1<<' '<<2<<' ';
			cout<<endl;
		}
		else {
			if (ar[0]==ar[n-1]) {
				cout<<2<<endl;
				for (int i=0;i<n/2;i++) cout<<1<<' '<<2<<' ';
				cout<<1<<endl;
			}
			else {
				vi ans(n);
				int i=0,ok=0;
				ans[0]=1;
				for (i=1;i<n;i++) {
					if (ar[i]==ar[i-1]) {
						ok=1;
						break;
					}
				}
				if (!ok) {
					cout<<3<<endl;
					for (int i=0;i<n/2;i++) cout<<1<<' '<<2<<' ';
					cout<<3<<endl;
				}
				else {
					for (int j=1;j<n;j++) {
						if (j==i) ans[j]=ans[j-1];
						else ans[j]=3-ans[j-1];
					}
					cout<<2<<endl;
					for (int j=0;j<n;j++) cout<<ans[j]<<' ';
					cout<<endl;
				}
				

			}
		}
	}

}

