// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
		vector<int> ans,tmp; ans.pb(1);
		for (int i=2;i<=N;i++) {
			int lo=-1,hi=i;
			while (lo<hi-1) {
				int mid=lo+hi>>1;
				if (compare(ans[mid],i)) lo=mid;
				else hi=mid;
			}
			for (int j=0;j<hi;j++) tmp.pb(ar[j]);
			tmp.pb(i);
			for (int j=hi;j<ar.size();j++) tmp.pb(ar[j]);
			ans.resize(0);
			swap(ans,tmp);
		}	
		return ans;
    }
};
