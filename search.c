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

//1219.黄金矿工(回溯)
class Solution {
    int ans=0,m,n;
    int[][] dir={{1,0},{-1,0},{0,1},{0,-1}};
    int[][] grid;
    public int getMaximumGold(int[][] grid) {
        int i,j;
        this.grid = grid;
        this.m=grid.length;
        this.n=grid[0].length;
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(grid[i][j]!=0)
            bfs(i,j,0);
        }
        return ans;
    }
    public void bfs(int x,int y,int glod){
        int rec;
        glod=glod+grid[x][y];
        rec=grid[x][y];
        grid[x][y]=0;
        int i,px,py;
        for(i=0;i<4;i++)
        {
            px=x+dir[i][0];
            py=y+dir[i][1];
            if(px>=0&&py>=0&&px<m&&py<n&&grid[px][py]!=0)
            {
                bfs(px,py,glod);
            }
        }
        grid[x][y]=rec;
        ans=Math.max(ans,glod);
    }
}

//494.目标和(回溯法)
class Solution {
    int count=0;
    public void bfs (int[] nums, int target, int index, int sum)
    {
        if(index==nums.length){
            if(sum==target){
                count++;
            }
        }
        else{
        bfs(nums, target, index+1,  sum+nums[index]);
        bfs(nums, target, index+1,  sum-nums[index]);
        }
    }
    public int findTargetSumWays(int[] nums, int target) {
        bfs(nums, target, 0, 0);
        return count;
    }
}

//1020.飞地的数量（自己的思路，无参考）
class Solution {
    int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int[][] grid;
    public int numEnclaves(int[][] grid) {
        this.grid = grid;
        int count=0;
        for(int i=0; i<grid[0].length; i++){
            if(this.grid[0][i]==1){
                bfs(0,i);
            }
            if(this.grid[grid.length-1][i]==1){
                bfs(grid.length-1,i);
            }
        }
        for(int j=0; j<grid.length; j++){
            if(this.grid[j][0]==1){
                bfs(j,0);
            }
            if(this.grid[j][grid[0].length-1]==1){
                bfs(j,grid[0].length-1);
            }
        }
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(this.grid[i][j]==1)
                count++;
            }
        }
        return count;
    }
    public void bfs(int x,int y){
        grid[x][y]=0;
        int px,py;
        for(int i=0;i<4;i++){
            px=x+dir[i][0];
            py=y+dir[i][1];
            if(px>=0&&px<grid.length&&py>=0&&py<grid[0].length&&grid[px][py]==1){
                bfs(px,py);
            }
        }
    }
}
