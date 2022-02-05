//5.最长回文子串(中心法)
class Solution {
    public String longestPalindrome(String s) {
        int star=0,end=0,left,right,i,j;
        int n=s.length();
        if(n<2)
        return s;
        for(i=0;i<n;i++)
        {
            right=left=i;
            while(right<n-1&&s.charAt(right)==s.charAt(right+1))
            right++;
            while(right<n&&left>=0&&s.charAt(right)==s.charAt(left))
            {
                left--;
                right++;
            }
            if(right-left>=end-star)
            {
                end=right;
                star=left;
            }
        }
        return s.substring(star+1,end);
    }
}

//221.最大正方形(还是很骚的)
class Solution {
    public int maximalSquare(char[][] matrix) {
        int m=matrix.length,n=matrix[0].length;
        if(m==0||n==0)
        return 0;
        int i,j,max=0,tmp=0;
        int[][] ans = new int [m][n];
        for(i=0;i<m;i++)
        {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]=='1')
            {
            if(i==0||j==0)
            ans[i][j]=1;
            else
            ans[i][j]=Math.min(Math.min(ans[i-1][j],ans[i][j-1]),ans[i-1][j-1])+1;
            }
            max=Math.max(ans[i][j],max);
        }
        }
        return max*max;
    }
}
