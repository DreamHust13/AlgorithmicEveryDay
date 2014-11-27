/*迷宫问题解法之深度度优先搜索
 *《啊哈》
 *规则：迷宫中最短路径
 *扩展：另有广度优先搜索方法
*/

#include <stdio.h>

int n,m;//迷宫是n行m列的
int endx,endy;//终止位置坐标
int min=99999999;//记录当前最小值

int map[50][50],book[50][50];//地图数据数组和标记数组

void dfs(int x,int y,int step)	
{
	//定义一个用于表示前进方向的数组//!!!想清楚!!!
    int next[4][2] = {
                       {0,1},//向右走
                       {1,0},//向下走
                       {0,-1},//向左走
                       {-1,0},//向上走
                     };
	int testx=x,testy=y;//尝试的下一坐标
    int k;//循环控制变量
	//判断是否到达终点
	if(testx==endx && testy==endy)
	{
		//是否变更最小值
		if(step<min)
			min = step;
		return;//!!!一定要返回
	} 
	
	//枚举四个方向//!!!之前没反应过来!!!
    for(k=0;k<4;k++)
    {
        //计算下一个点的坐标
        testx=x+next[k][0];
        testy=y+next[k][1];
        //判断是否越界
        if(testx<0||testx>=n||testy<0||testy>=m)
            continue;//!!!
        //判断是否是障碍物或者已经在路径中
        if(map[testx][testy] == 0 && book[testx][testy] == 0)
        {
            //将该坐标标记
            //!!!注意DFS与BFS不同，不是每个点之入队一次，而是要将book还原
            book[testx][testy]=1;
            dfs(testx,testy,step+1);//!!!+1
			book[testx][testy]=0;//尝试结束，取消该点标记
        }	
	}
	return;
}
	
int main()
{
    int i,j;//循环控制变量
    int startx,starty;//起始位置坐标
    
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

    //从起点开始搜索
	book[startx][starty]=1;//标记起点，防止以后多走
	dfs(startx,starty,0);
	

    printf("从(%d,%d)到(%d,%d)至少需要%d步\n",startx,starty,endx,endy,min);

    return 0;
}


