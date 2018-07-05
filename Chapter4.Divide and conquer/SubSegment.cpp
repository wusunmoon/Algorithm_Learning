#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MaxSum(const vector<int> &v, int lo, int hi)
{
	if(hi - lo == 1)
		return v[lo];
	else{
		int m = (lo + hi) / 2;
		int lsum = MaxSum(v,lo,m);
		int rsum = MaxSum(v,m,hi);
		int s0 = 0;
		int ts = 0;
		for(int i = m-1; i >= lo; --i){
			ts += v[i];
			if(s0 < ts)
				s0 = ts;
		}
		int s1 = 0;
		ts = 0;
		for(int i = m; i < hi; ++i){
			ts += v[i];
			if(s1 < ts)
				s1 = ts;
		}
		int msum = s0 + s1;
		return max({lsum,msum,rsum});
	}
}
int main()
{
	vector<int> v = {-20,11,-4,13,-5,-2};
	cout << MaxSum(v,0,v.size()) << endl;
	return 0;
}
