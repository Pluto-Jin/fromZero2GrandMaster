#include "bits/stdc++.h"
using namespace std;


vector<vector<int>> ar;

int dfs(int x,int y,int cnt) {
	for (auto &i: ar[x]) {
		if (i==y) return cnt+1;
		int tmp=dfs(i,y,cnt+1);
		if (tmp!=-1) return tmp;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	ar.resize(n+1);
	for (int i=0;i<n-1;i++) {
		int x,y;
		cin>>x>>y;
		if (x<y) ar[x].push_back(y);
		else ar[y].push_back(x);
	}

	int q;
	cin>>q;
	while (q--) {
		int qr[5];
		for (auto &i:qr) cin>>i;
		int x=min(qr[0],qr[1]),y=max(qr[0],qr[1]);
		int stp=bfs(x,y);
	}

}

