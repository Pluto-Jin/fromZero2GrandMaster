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
		string s; cin>>s;
		string a="1",b="1";
		int ok=0;
		for (int i=1;i<n;i++) {
			if (s[i]=='0') {
				a+='0'; b+='0';
			}
			else if (s[i]=='1') {
				if (!ok) {
					a+='1'; b+='0';
				}
				else {
					a+='0'; b+='1';
				}
				ok=1;
			}
			else {
				if (!ok) {
					a+='1'; b+='1';
				}
				else {
					a+='0'; b+='2';
				}
			}
		}
		cout<<a<<endl<<b<<endl;
	}
}

