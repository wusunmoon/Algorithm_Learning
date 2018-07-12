/*
	程序：最长公共子序列问题 
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void CommonOrder(const vector<char> &v1, const vector<char> &v2,vector<char> &cv)
{
	int m = v1.size();
	int n = v2.size();
	vector<vector<int>> len(m+1, vector<int>(n+1,0));
	vector<vector<int>> st(m+1, vector<int>(n+1,0));
	for(int i = 1; i <= m; ++i){
		for(int j = 1; j <= n; ++j){
			if(v1[i-1] == v2[j-1]){
				len[i][j] = len[i-1][j-1] + 1;
				st[i][j] = 1;
			}
			else{
				if(len[i][j-1] >= len[i-1][j]){
					len[i][j] = len[i][j-1];
					st[i][j] = 2;
				}
				else{
					len[i][j] = len[i-1][j];
					st[i][j] = 3;
				}
			}
		}
	}
	int k = len[m][n];
	cv.assign(k,0);
	while(m > 0 && n > 0){
		if(st[m][n] == 1){
			cv[--k] = v1[--m];
			--n;
		}
		else if(st[m][n] == 2)
			--n;
		else
			--m;
	}
}
int main()
{
	vector<char> v1{'a','b','c','b','d','b'};
	vector<char> v2{'a','c','b','b','a','b','d','b','b'};
	vector<char> cv;
	CommonOrder(v1,v2,cv);
	for(auto ch : cv)
		cout << ch << " ";
	cout << endl;
	return 0;
}
