/*
	程序：0/1背包问题 
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Good{
	int w;
	int v;
};
int knapsack(vector<Good> &vg, int C, vector<bool> &choice)
{
	int n = vg.size();
	vector<vector<int>> value(n+1,vector<int>(C+1,0));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= C; ++j){
			if(vg[i-1].w > j)
				value[i][j] = value[i-1][j];
			else{
				value[i][j] = max(value[i-1][j], value[i-1][j-vg[i-1].w]+vg[i-1].v);
			}
		}
	}
	int vm = value[n][C];
	for(int i = n-1; i >= 0; --i){
		if(value[n][C] > value[n-1][C]){
			choice[i] = true;
			C = C - vg[n-1].w;
		}
		else{
			choice[i] = false;
		}
		--n;
	}
	return vm;
}
int main()
{
	vector<Good> vg{{2,6},{2,3},{6,5},{5,4},{4,6}};
	int C = 10;
	vector<bool> choice(vg.size(),false);
	int vm = knapsack(vg,C,choice);
	for(auto b : choice)
		cout << b << " ";
	cout << ": " << vm << endl;
	return 0;
}
