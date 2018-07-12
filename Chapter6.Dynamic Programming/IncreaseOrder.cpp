#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> IncreaseOrder(vector<int> &v)
{
	int n = v.size();
	vector<int> len(n,1);
	vector<vector<int>> subOrder(n);
	for(int i = 0; i < n; ++i)
		subOrder[i].push_back(v[i]);
	for(int i = 1; i < n; ++i){
		for(int j = i - 1; j >=0; --j){
			if((v[j] < v[i]) && (len[i] < len[j] + 1)){
				len[i] = len[j] + 1;
				subOrder[i].assign(subOrder[j].size(),0);
				copy(subOrder[j].begin(),subOrder[j].end(),subOrder[i].begin());
				subOrder[i].push_back(v[i]);
			}
		}
	}
	int index = 0;
	for(int i = 1; i < subOrder.size(); ++i){
		if(subOrder[i].size() > subOrder[index].size())
			index = i;
	}
	return subOrder[index];
}
int main()
{
	vector<int> v{5,2,8,6,3,6,9,7};
	vector<int> subOrder = IncreaseOrder(v);
	for(auto i : subOrder)
		cout << i << " ";
	cout << endl;
	return 0;
}
