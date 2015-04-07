/*
	字符串全排列【无/有重复字符】
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
//法一：
bool isSwap(char *pBegin, char *pCh)
{
	char *p;
	for(p=pBegin; p != pCh; p++)
	{
		if(*p == *pCh)
			return false;
	}
	return true;
}
void Permutation(char* pStr, char* pBegin)
{
	assert(pStr && pBegin);
	static int num=1;
	if(*pBegin == '\0')
		printf("%d : %s\n",num++,pStr);
	else
	{
		for(char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			if(isSwap(pBegin,pCh))
			{
				swap(*pBegin,*pCh);
				Permutation(pStr, pBegin+1);
				swap(*pBegin,*pCh);
			}
		}
	}
}

int main(void)
{
	char str[] = "abcd";
	Permutation(str,str);
	return 0;
}

//法二：
/*
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const vector<int>& num, vector<int> &path,vector<vector<int> > &result) ;

vector<vector<int> > permute(vector<int>& num) 
{
	sort(num.begin(), num.end());
	vector<vector<int>> result;
	vector<int> path; // 中间结果
	dfs(num, path, result);
	return result;
}

void dfs(const vector<int>& num, vector<int> &path,vector<vector<int> > &result) 
{
	if (path.size() == num.size()) 
	{ // 收敛条件
		result.push_back(path);
		return;
	}
	// 扩展状态
	for (auto i : num) 
	{
		// 查找 i 是否在 path 中出现过
		auto pos = find(path.begin(), path.end(), i);
		if (pos == path.end()) 
		{
			path.push_back(i);
			dfs(num, path, result);
			path.pop_back();
		}
	}
}

int main()
{
	int data[] = {1,2,3,4};
	vector<int> sour(data,data+4);
	vector<vector<int>> result;
	int num = 0;
	result = permute(sour);
	for(auto i : result)
	{
		cout << ++num <<" : ";
		for(auto j : i)
			cout << j;
		cout << endl;
	}

	return 0;
}
*/