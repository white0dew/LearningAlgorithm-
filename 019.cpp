//这是剑指offer上给的一个解法，使用递归而不是动态规划
//解法一 因为有这样的测试用例："aaaaaaaaaaaaab"
//"a*a*a*a*a*a*a*a*a*a*c"----会超时
//也就是说必须用动态规划
/*class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0;
        int j=0;
        return matchcore(s,i,p,j);
    }

    bool matchcore(string s,int i,string p,int j){
        if(i==s.length() && j==p.length())
            return true;
        if(i!=s.length() && j==p.length())
            return false;
        if(p[j+1]=='*'){
            if(p[j]==s[i]||(p[j]=='.'&&i!=s.length()))
                return matchcore(s,i+1,p,j+2)||matchcore(s,i+1,p,j)||matchcore(s,i,p,j+2);
            else
                return matchcore(s,i,p,j+2);
        }

        if(s[i]== p[j] || (p[j]=='.'&& i!= s.length()))
            return matchcore(s,i+1,p,j+1);
        return false;
    }
};*/
//解法二 动态规划 https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/jian-zhi-offer-19-zheng-ze-biao-da-shi-pi-pei-dong/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1, n = p.size() + 1;
        vector<vector<bool>> dp(m, vector<bool>(n, false));
        dp[0][0] = true;
        for(int j = 2; j < n; j += 2)
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = p[j - 1] == '*' ?
                    dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'):
                    dp[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};


