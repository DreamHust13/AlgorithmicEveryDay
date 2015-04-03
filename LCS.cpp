/*
	最长公共子串【连续】
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const  string LCS(const string &str1,const string &str2)
{
	int s1len = str1.size();    //横向长度
	int s2len = str2.size();    //纵向长度
	vector<int> temp(s1len);	//保存矩阵上一行
	vector<int> current(s1len); //当前行
	int max = 0;				//当前矩阵中最大值
	int pos = 0;				//矩阵最大值出现在第几列

	for(int i = 0; i<s2len; i++)
	{
		//string s = str2.substr(i,1);;
		current.assign(s1len,0);
		for(int j=0; j<s1len; j++)
		{
			if(str1[j]== str2[i])
			{
				if(j==0)//第一列，无前驱元素
					current[j]= 1;
				else
					current[j] = temp[j-1] + 1;
				if(current[j] > max)
				{
					max = current[j];
					pos = j;
				}
			}
		}
		temp.assign(current.begin(),current.end());
	}
	string res = str1.substr(pos-max+1,max);//公共子串很巧妙
	return res;
}

int main()
{
	string str1("acbac");
	string str2("acaccbabb");
	string lcs = LCS(str1,str2);
	cout << lcs << endl;

	return 0;
}