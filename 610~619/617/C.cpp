#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int main() 
{
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		string s;
		cin>>s;

		int x=0,y=0;
		int ans[2]={-1,-1},len=2e5;
		map<pii,int> dic;
		dic[mp(0,0)]=0;
		for (int i=0;i<n;i++) {
			if (s[i]=='L') x--;
			if (s[i]=='R') x++;
			if (s[i]=='U') y++;
			if (s[i]=='D') y--;
			if (dic.count(mp(x,y))) {
				if (i+1-dic[mp(x,y)]<=len) {
					len=i+1-dic[mp(x,y)];
					ans[0]=dic[mp(x,y)]+1;
					ans[1]=i+1;
				}
			}
			dic[mp(x,y)]=i+1;
		}
		if (ans[0]==-1) cout<<-1<<endl;
		else cout<<ans[0]<<" "<<ans[1]<<endl;
	}
}

