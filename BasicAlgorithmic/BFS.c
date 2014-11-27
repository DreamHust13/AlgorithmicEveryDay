/*图的广度优先遍历：
 *思想：首先以一个未被访问过的顶点作为起始顶点，访问其所有相邻的顶点，然后对每个相邻的顶点，再访问它们相邻的未被访问过的顶点，
 *      直到所有所有顶点都被访问过，便利结束。
 *实现：使用队列
 *
*/

#include <stdio.h>
void bfs(int edge[][100],int n)
{
    int que[10000];
    int book[100]={0};
    int head,tail;
    int cur;//当前顶点
    int i;//循环控制变量
    //初始化队列
    head=0;
    tail=0;
    
    //从顶点1出发，将1入队
    que[tail]=0;
    tail++;
    book[0]=1;//标记0已被访问

    //当队列不为空时，循环
    while(head<tail)
    {
        cur=que[head];
        for(i=0;i<n;++i)//从1~n依次尝试
        {
            //判断cur与i间是否有边，且i是否被访问
            if(edge[cur][i]==1 && book[i]==0)
            {
                //若有边且i未被访问，i入队
                que[tail]=i;
                tail++;
                book[i]=1;//标记i
            }
            //tail等于n，表明所有顶点已被访问！！！勿忘
            if(tail>=n)
                break;
        }
        //!!!勿忘
        head++;
    }

    printf("访问顺序为：");
    for(i=0;i<n;++i)
        printf("%d ",que[i]+1);
    printf("\n");
}

int main()
{
    int edge[100][100];//边集
    int i,j;//循环控制变量
    int n;//顶点数
    int m;//边数
    int a,b;//输入临时变量

    printf("请输入顶点数、边数:");
    scanf("%d %d",&n,&m);
    //初始化二维矩阵
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)//笨蛋，j写成i,还找不到错误！！！但是，为什么会改变m的值呢？？？
            if(i==j)
                edge[i][j]=0;
            else
                edge[i][j]=99999999;//假设99999999为正无穷

    //读入边集
    printf("请输入边集(两点间的边只输入一条即可)：\n");
    for(i=0;i<m;++i)
    {
        scanf("%d %d",&a,&b);
        edge[a-1][b-1]=1;
        edge[b-1][a-1]=1;
    }

    bfs(edge,n);

    return 0;
}
