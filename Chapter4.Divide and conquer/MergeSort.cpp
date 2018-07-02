/*
	程序：分治法递归排序
	作者：Moyu 
*/
#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int> &v, int lo, int m, int hi)
{
	vector<int> vl(v.begin()+lo,v.begin()+m);//赋值左半个数组 
	int i = lo;
	int j = 0;
	int k = m;
	while(i < hi){
		if(j < vl.size() && (k == hi || vl[j] <= v[k]))
			v[i++] = vl[j++];
		if(k < hi && (j == vl.size() || vl[j] > v[k]))
			v[i++] = v[k++];
	}		
} 
void MergeSort(vector<int> &v, int lo, int hi)
{
	if(hi - lo == 1)
		return;
	else{
		int m = (lo + hi) / 2;
		MergeSort(v,lo,m);
		MergeSort(v,m,hi);
		Merge(v,lo,m,hi);
	}
}
int main()
{
	vector<int> v = {2,3,1,9,11,6,4,18,5};
	MergeSort(v,0,v.size());
	for(auto i : v)
		cout << i << " ";
	cout << endl;
	return 0;
}

