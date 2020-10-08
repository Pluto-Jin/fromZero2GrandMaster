#include "bits/stdc++.h"
using namespace std;

int main() 
{
	int n,m;
	cin>>n>>m;
	vector<string> ar;
	ar.resize(n);
	for (auto &i:ar) cin>>i;

	map<string,int> dic;
	set<string> st;
	string ans="";
	int res=0;
	for (auto i:ar) {
		string tmp="";
		for (int j=m-1;j>=0;j--) tmp+=i[j];
		if (dic.count(i)) {
			ans+=i;
			res++;
			dic[tmp]--;
			if (st.count(tmp)) st.erase(tmp);
		}
		else
		{
			dic[tmp]=1;
			if (i.compare(tmp)==0) st.insert(tmp);
		}
	}
	if (!st.empty()) ans+=*st.begin();
	for (int i=res*m-1;i>=0;i--) {
		ans+=ans[i];
	}
	cout<<ans.size()<<endl<<ans<<endl;
}

