//1765.地图中的最高点(多源点搜索)(该类型的第一题，部分参考题解才做出来的)
typedef struct {
    int x;
    int y;
} Pair;

int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int** highestPeak(int** isWater, int isWaterSize, int* isWaterColSize, int* returnSize, int** returnColumnSizes){
    int i,j;
    int m = isWaterSize, n = isWaterColSize[0];
    int ** ans = (int **)malloc(sizeof(int *) * m);
    for ( i = 0; i < m; ++i) {
        ans[i] = (int *)malloc(sizeof(int) * n);
        memset(ans[i], -1, sizeof(int) * n);
    }
    Pair * queue = (Pair *)malloc(sizeof(Pair) * m * n);
    int head = 0;
    int tail=0;
    int px,py;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    {
        if(isWater[i][j]==1)
        {
            ans[i][j]=0;
            queue[tail].x=i;
            queue[tail].y=j;
            tail++;
        }
    }
    while(head!=tail)
    {
        for(i=0;i<4;i++)
        {
            px=queue[head].x+dirs[i][0];
            py=queue[head].y+dirs[i][1];
            if(px<isWaterSize&&px>=0&&py>=0&&py<n&&ans[px][py]==-1)
            {
                ans[px][py]=ans[queue[head].x][queue[head].y]+1;
                queue[tail].x=px;
                queue[tail].y=py;
                tail++;
            }
        }
        head++;
    }
    free(queue);
    *returnSize = m;
    *returnColumnSizes = (int *)malloc(sizeof(int) * m);
    memcpy(*returnColumnSizes, isWaterColSize, sizeof(int) * m);
    return ans;
}
