/*迷宫问题解法之广度优先搜索
 *《啊哈》
 *规则：迷宫中最短路径
 *扩展：另有广度优先搜索方法
*/

#include <stdio.h>
struct node
{
    int x;//横坐标
    int y;//纵坐标
    int f;//父亲在队列中的编号
    int step;//步数
};

int main()
{
    struct node que[2500];//规定，地图大小不超过50*50，因此队列扩展不会超过2500个

    int map[50][50],book[50][50];//地图数据数组和标记数组
    //定义一个用于表示前进方向的数组//!!!想清楚!!!
    int next[4][2] = {
                       {0,1},//向右走
                       {1,0},//向下走
                       {0,-1},//向左走
                       {-1,0},//向上走
                     };
    int head,tail;//队列首尾
    int n,m;//迷宫是n行m列的
    int i,j,k;//循环控制变量
    int startx,starty;//起始位置坐标
    int endx,endy;//终止位置坐标
    int testx,testy;//尝试的下一坐标
    int flag;//标记，标记是否已到达目标点，0表示暂时没有，1表示到达

    //初始化迷宫数据
    printf("请输入迷宫行、列：");
    scanf("%d %d",&n,&m);
    printf("请输入迷宫地图(0表示可到，1表示障碍物):\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    printf("请输入起始位置坐标((0,0)到(50,50))：");
    scanf("%d %d",&startx,&starty);
    printf("请输入终点坐标：");
    scanf("%d %d",&endx,&endy);

    //初始化队列
    head=0;
    tail=0;
    //将起始坐标插入队列
    que[tail].x=startx;
    que[tail].x=starty;
    que[tail].f=0;
    que[tail].step=0;
    tail++;
    book[startx][starty]=1;

    flag=0;
    while(head < tail)//队列为空则循环
    {
        //枚举四个方向//!!!之前没反应过来!!!
        for(k=0;k<4;k++)
        {
            //计算下一个点的坐标
            testx=que[head].x+next[k][0];
            testy=que[head].y+next[k][1];
            //判断是否越界
            if(testx<0||testx>=n||testy<0||testy>=m)
                continue;//!!!
            //判断是否是障碍物或者已经在路径中
            if(map[testx][testy] == 0 && book[testx][testy] == 0)
            {
                //将该坐标标记
                //!!!注意BFS与DFS不同，每个点之入队一次，不需要将book还原
                book[testx][testy]=1;
                //将该点插入队列
                que[tail].x=testx;
                que[tail].y=testy;
                que[tail].f=head;//由于该点是从head扩展出来的，所以它的前节点为head
                que[tail].step=que[head].step+1;//前节点步数加1
                tail++;
            }
            //若到达目标点，停止扩展，任务结束，退出循环
            if(testx==endx && testy==endy)
            {
                //注意，顺序不要颠倒
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
        head++;//!!!千万不要忘记，当一个点扩展结束后（四个方向），head++才能对后面的点扩展
    }

    //打印队列中末尾最后一个点（目标点）的步数
    //！！！注意tail是指向队列队尾的下一个位置，所以要-1
    printf("从(%d,%d)到(%d,%d)至少需要%d步\n",startx,starty,endx,endy,que[tail-1].step);

    return 0;
}


