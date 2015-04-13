/*
冒泡排序
算法思想：对n个数进行排序，需进行n-1趟排序，每次归位一个数。
          每次比较两个相邻的元素，如果他们的顺序错误，就把它们交换过来。
复杂度：O(N2)

优化：记录是否发生交换（true：是，false：否）

*/
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int unsorted[], int size)
{
    bool flag = true;

    while(flag)
    {
        for(int i = 0; i < size - 1; ++i) //n-1次排序
        {
            flag = false;

            for(int j = 1; j < size - i; j++) //！！！注意i和j的范围！！
            {
                if(unsorted[j - 1] > unsorted[j])
                {
                    swap(unsorted[j - 1], unsorted[j]); //是对j，而不是i
                    flag = true;
                }
            }

            if(!flag)
                return;
        }
    }
}

int  main()
{
    int unsorted[] = {3, 6, 1, 4, 5};
    int length = sizeof(unsorted) / sizeof(int);

    for(int i = 0; i < length; ++i)
        cout << unsorted[i] << " ";

    cout << endl;

    BubbleSort(unsorted, length);

    for(int i = 0; i < length; ++i)
        cout << unsorted[i] << " ";

    cout << endl;

    return 0;
}
