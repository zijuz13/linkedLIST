    public boolean isMatch(String s, String p) {
        int m=s.length();
        int n=p.length();
     boolean[][] dp=new boolean[m+1][n+1];
     dp[0][0]=true;
     for(int i=1;i<=m;++i){
         for(int j=1;j<=n;++j){
             if(p.charAt(j-1)=='*'){
                 dp[i][j]=dp[i][j-2];
                 if(ifFuckingMatch(s,p,i,j-1)){
                  dp[i][j]=dp[i][j]||dp[i-1][j];
                 }
             }else{
                 if(ifFuckingMatch(s,p,i,j)){
                     dp[i][j]=dp[i-1][j-1];
                 }
             }
         }
     }
     return dp[m][n];
    }
    private boolean ifFuckingMatch(String s,String p,int i,int j){
        //.可以匹配所有字符
        if(p.charAt(j-1)=='.')
            return true;
        return s.charAt(i-1)==p.charAt(j-1);
    }
