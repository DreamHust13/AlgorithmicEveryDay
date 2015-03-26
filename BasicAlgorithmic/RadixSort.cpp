#include "stdafx.h"
#include <iostream>
using namespace std;
//链表使用功底有待加强！！
struct Node
{
	int value;
	Node *next;
};

int getDigit(int num, int loc)
{
	//取数字num第loc位上的数字
	for(int i=0; i < loc; i++)//i从0开始
		num /= 10;
	return num%10;
}

int maxBits(int data[], int size)
{
	//数组中数字的最大位数;相当于进行几趟分配
	int max = 0, temp, current;
	for(int i=0; i<size; i++)
	{
		temp = 0;
		current = data[i];
		while(current)
		{
			temp++;
			current /= 10;
		}
		if(temp > max)
			max = temp;
	}
	return max;
}

void RadixSort(int data[], int size)
{
	//其实应该还可以有个表示基数的参数，现在默认为10
	if(data == NULL || size <= 0)
		return;
	int rankNum = maxBits(data, size);
	Node Bucket[10];//建立10个桶
	if(Bucket == NULL)
		return ;

	int i,idNum;
	Node *p,*q;//插入节点时所用的临时变量
	for(int rank = 0; rank < rankNum; rank++)
	{
		//进行rankNum趟排序

		for(int i = 0; i < 10; i++)
		{
			//初始化桶
			Bucket[i].value = -1;
			Bucket[i].next = NULL;
		}

		for(int i = 0; i < size; i++)
		{
			//依次如桶
			Node *pNew = new Node();//()表示值初始化
			pNew->value = data[i];
			pNew->next = NULL;
			idNum = getDigit(data[i],rank);

			if(Bucket[idNum].next == NULL)
				Bucket[idNum].next = pNew;
			else
			{
				p = &Bucket[idNum];//注意&
				while(p->next != NULL)
					p = p->next;
				p->next = pNew;
			}
		}

		int j=0;//初始化
		for(i=0; i < 10; i++)
		{
			//依次遍历10个桶
			p = Bucket[i].next;
			if(p == NULL)
				continue;
			while(p != NULL)
			{
				data[j++] = p->value;
				q = p;
				p = p->next;
				delete q;//勿忘释放空间！！
			}
		}
		for(int i=0; i<size; ++i)
			cout<<data[i]<<" ";
		cout<<endl;
	}
}

int  main()
{
	int unsorted[] = {3,36,1,4,15,5,8,14,9,9,10};
	int length = sizeof(unsorted)/sizeof(int);

	for(int i=0; i<length; ++i)
		cout<<unsorted[i]<<" ";
	cout<<endl;

	RadixSort(unsorted,length);

	for(int i=0; i<length; ++i)
		cout<<unsorted[i]<<" ";
	cout<<endl;

	return 0;
}


/*
失败！！且没找到原因！！
#include <iostream>
using namespace std;

struct DNode
{
	int value;
	struct DNode *next;
};

struct Bucket
{
	struct DNode *first;
	struct DNode *tail;
};

int getDigit(int num, int loc)
{//取数字num第loc位上的数字
	for(int i=1; i < loc; i++)
		num /= 10;
	return num%10;
}

int maxBits(int data[], int size)
{//数组中数字的最大位数;相当于进行几趟分配
	int max = 0, temp, current;
	for(int i=0; i<size; i++)
	{
		temp = 0;
		current = data[i];
		while(current)
		{
			temp++;
			current /= 10;
		}
		if(temp > max)
			max = temp;
	}
	return max;
}

void RadixSort(int data[], int size)
{//其实应该还可以有个表示基数的参数，现在默认为10
	if(data == NULL || size <= 0)
		return;
	int rankNum = maxBits(data, size);
	Bucket *pBucket = new Bucket[10];//建立10个桶
	if(pBucket == NULL)
		return ;

	int i,idNum;
	for(int rank = 0; rank < rankNum; rank++)
	{//进行rankNum趟排序

		for(i=0 ; i < 10; i++)
		{//每次装桶之前要清桶！！
			pBucket[i].first = NULL;
			pBucket[i].tail = NULL;
		}

		for(i=0; i<size; i++)
		{//数组数据依次入桶
			idNum = getDigit(data[i],rank);
			DNode *p = pBucket[idNum].first;

			DNode *pNew = new DNode;
			pNew->value = data[i];
			pNew->next = NULL;

			if(p == NULL)
			{
				pBucket[idNum].first = pNew;
				pBucket[idNum].tail = pNew;
			}
			else
			{
				pBucket[idNum].tail->next = pNew;
				pBucket[idNum].tail = pNew;
			}
		}

		int j=0;//初始化
		DNode *pTemp = NULL;
		for(i=0; i <=9; i++)
		{//依次遍历10个桶
			while(pBucket[i].first->next != NULL && pBucket[i].tail != NULL)//注意链表和结构的使用方式
			{
				pTemp = pBucket[i].first->next;
				data[j++] = pTemp->value;
				pBucket[i].first->next = pTemp->next;
				delete pTemp;//勿忘！！
			}
		}
	}
	delete []pBucket;//勿忘！！
}
*/
