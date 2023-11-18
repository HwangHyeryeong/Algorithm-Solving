import java.util.*;
import java.io.*;

public class Main {
    static int n;
    static int[][] map;
    static long[][] dp;
    
    static int[] dc = {1, 0};
    static int[] dr = {0, 1};
    
    static boolean isValid(int r, int c){
        return (r >= 0 && r < n && c >= 0 && c < n);
    }
    
    static long dfs(int r, int c){
        if(r == n - 1 && c == n - 1)
            return 1;
        
        
        if(dp[r][c] != -1)
            return dp[r][c];
        
        dp[r][c] = 0;
        for(int i = 0; i < 2; i++){
            int nextC = c + dc[i] * map[r][c];
            int nextR = r + dr[i] * map[r][c];
            if(isValid(nextR, nextC)){
                dp[r][c] += dfs(nextR, nextC);
            }
        }
        
        return dp[r][c];
    }
    
	public static void main(String[] args) throws IOException {
	    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	    
	    StringTokenizer token = new StringTokenizer(reader.readLine());
        n = Integer.parseInt(token.nextToken());
        map = new int[n][n];
        dp = new long[n][n];
        
		for(int i = 0; i < n; i++){
		    token = new StringTokenizer(reader.readLine());
		    for(int j = 0; j < n; j++){
                map[i][j] = Integer.parseInt(token.nextToken());
                dp[i][j] = -1L;
		    }
		}
		
		dfs(0, 0);
		
		System.out.println(dp[0][0]);
	}
}
