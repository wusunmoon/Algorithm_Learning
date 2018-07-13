/*
	程序：最优二叉查找树 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

struct Record{
	char ch;	//记录 
	double pb;	//查找概率 
};
struct TNode{
	char ch;
	TNode * lchild, * rchild;
};
void CreatTree(const vector<Record> &rd, int s, int t, const vector<vector<int>> &R, TNode* &root)
{
	if(s == t)
		return;
	else{
		int k = R[s][t];
		root = new TNode{rd[k].ch,NULL,NULL};
		CreatTree(rd,s,k,R,root->lchild);
		CreatTree(rd,k+1,t,R,root->rchild);
	}
}
double OptimalBST(const vector<Record> &rd, TNode * &root) 
{
	int n = rd.size();
	vector<vector<double>> C(n+1,vector<double>(n+1,0));
	vector<vector<int>> R(n+1,vector<int>(n+1,0));
	for(int i = 0; i < n; ++i){
		C[i][i+1] = rd[i].pb;
		R[i][i+1] = i;
	}
	for(int d = 2; d <= n; ++d){
		for(int i = 0; i <= n-d; ++i){
			int j = i + d;
			double sum = 0;
			double min = numeric_limits<double>::max();
			int mink = i;
			for(int k = i; k < j; ++k){
				sum += rd[k].pb;
				if(min > C[i][k] + C[k+1][j]){
					min = C[i][k] + C[k+1][j];
					mink = k;
				}
			}
			C[i][j] = min + sum;
			R[i][j] = mink;
		}
	}
	CreatTree(rd,0,n,R,root);
	return C[0][n];
}
void InOrder(TNode * root)
{
	if(root != NULL){
		InOrder(root->lchild);
		cout << root->ch << " ";
		InOrder(root->rchild);
	}
}
int main()
{
	TNode * root;
	vector<Record> rd{{'A',0.1},{'B',0.2},{'C',0.4},{'D',0.3}};
	double dr = OptimalBST(rd, root);
	cout << dr << endl;
	InOrder(root);
	return 0;
}
