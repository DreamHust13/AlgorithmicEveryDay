/*全排列解法之DFS（深度优先搜索）
 *《啊哈》
 *思想：理解深度优先搜索的关键在于解决"当下该如何做"。至于"下一步如何做"则与"当下如何做"是一样的。通常方法是把每一种都去尝试一遍
 *规则：该题是输出1~n的全排列，比用在图中的DFS算法要简化
 *
 *问题：优化：data和book数组是有固定大小限制的，只能全排列1~9,；另外，数字0的特殊性
 *扩展：迷宫问题：最短路径。判断是否越界，是否遇到障碍物或者是已经在路径中
*/
#include <stdio.h>
int data[10],book[10],n;//C语言的全局变量默认初始化为0;book为标记数组

void dfs(int step)//step表示第step位数
{
    int i;
    if(step == n+1)//表示前面n位数已经排好
    {
        //输出一种排列，即data[1]~data[n]
        for(i=1;i<=n;++i)
            printf("%d",data[i]);
        printf("\n");

        return;//返回最近调用dfs的地方
    }

    //第step位：按照1.2...n的顺序依次尝试
    for(i=1;i<=n;++i)
    {
        //判断i是否已经被排序
        if(book[i]==0)//i仍未被排序
        {
            data[step] = i;//尝试用i
            book[i] = 1;//标记i被使用

            dfs(step+1);//当前排好，排下一个位置
            book[i]=0;//!!!已尝试过i，将i收回，才能尝试下一个未被排序的!!!
        }
    }
    return;
}

int main()
{
    printf("将对1~n进行全排列，请输入n：");
    scanf("%d",&n);
    dfs(1);//从1开始排序

    return 0;
}



