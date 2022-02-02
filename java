5.最长回文子串(中心法)
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