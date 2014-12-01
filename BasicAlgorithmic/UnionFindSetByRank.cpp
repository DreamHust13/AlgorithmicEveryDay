/*
 *并查集也称为不相交集数据结构
 *算法导论21章并查集                                                             
 *启发式策略之按秩合并：思想是使包含较少结点的树的根指向包含较多结点的树的根。
 *						并不显示记录以每个结点为根的字数的大小，而是对每个结点，用秩表示结点高度的一个上界。
 *						在按秩合并中，具有较小秩的根在Union操作中要指向具有较大秩的根。
 *						时间复杂度：O(MlgN)
 *改进：用链表实现
 *
*/

#include <iostream>
#include <memory.h>
using namespace std;

/*
*rank[]是用来存放元素x秩的数组，p[]是用来存放元素x父节点的数组
*Make_Set()用来初始化集合元素，刚开始的时候每个元素独立为一个集合
*/
void Make_Set(int rank[],int p[],int x)
{
    p[x] = x;
    rank[x] = 0;
}

/************************************************************************/
/* 寻找x元素所属的集合                                                                     */
/************************************************************************/
int Find_Set(int p[],int x)
{
    if(p[x]!=x)
    {
        p[x] = Find_Set(p,p[x]);
    }
    
        return p[x];

}


/************************************************************************/
/* 合并两个集合                                                                     */
/************************************************************************/
void Union(int rank[],int p[],int x, int y)
{
    int px = Find_Set(p,x);
    int py = Find_Set(p,y);
    if (rank[px]>rank[py])
    {
        p[py] = px;
    }
    else
    {
        p[px] = py;
        if (rank[px]==rank[py])
        {
            rank[py]++;//注意，rank的自增操作只在此时!!!
        }
    }
}

int main()
{
    int n, m;//n人分成m组
    int rank[30003];
    int p[30003];//指示父节点的数组
    int numsuspect;//最终犯罪团伙数
    int personnum;//临时成员
    int firstpersonnum;//每组输入的第一个成员
    int groupnum;//每组成员数
    int i,j;//循环控制变量
    while(1)
    {
        numsuspect = 0;
        memset(rank,0,sizeof(rank));
        memset(p,0,sizeof(p));
		cout<<"请输入犯罪团伙人数和当前已知团伙数：";
        cin >> n >> m;//n为犯罪团伙人数，m为现在已知团伙数
        if(n==0 && m==0)
            break;
        for(i=0;i<n;i++)//犯罪成员编号从0开始，到n-1
            Make_Set(rank,p,i);//初始化rank和p数组
        j=m;
        while((--j)>=0)
        {
            cout<<"第"<<m-j<<"组犯罪团伙人数为:";
            cin>>groupnum;
            if (groupnum>=1)
            {
                cout<<"       犯罪成员为：";
                cin>>firstpersonnum;
            }

            for(i=1;i<groupnum;i++)
            {
                cin >> personnum;
                Union(rank,p,firstpersonnum,personnum);
            }
            
        }
        //扫描有多少个独立的犯罪团伙
        for (i=0;i<n;i++)
        {
            if (Find_Set(p,i)==i)//若父节点是自己，就是犯罪团伙最高领导人，有多少个最高领导人，就有多少个独立犯罪团伙
            {
                numsuspect++;
            }
        }
        cout << "经计算，有"<<numsuspect <<"个独立的犯罪团伙。"<< endl;

    }

    return 0;
}
