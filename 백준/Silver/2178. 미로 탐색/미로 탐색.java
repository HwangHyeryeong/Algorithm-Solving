import java.util.*;
import java.io.*;

public class Main {
    static int n, m;
    static char[][] maze;
    static int[][] dist;
    static boolean[][] visited;
    
    static int[] dr = {-1, 0, 1, 0};
    static int[] dc = {0, -1, 0, 1};
    
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        maze = new char[n][m];
        dist = new int[n][m];
        visited = new boolean[n][m];
        
        for(int i = 0; i < n; i++){
            String tmp = br.readLine();
            maze[i] = tmp.toCharArray();
        }
        
        bfs(0, 0);
        
        System.out.println(dist[n - 1][m - 1]);
	}
	
	static void bfs(int r, int c){
	    Queue<Point> q = new LinkedList<>();
	    
	    visited[r][c] = true;
	    dist[r][c] = 1;
	    q.add(new Point(r, c));
	    
	    while(!q.isEmpty()){
	        int curR = q.peek().r;
	        int curC = q.peek().c;
	        q.poll();
	        
	        for(int i = 0; i < 4; i++){
	            int nextR = curR + dr[i];
	            int nextC = curC + dc[i];
	            
	            if(isValid(nextR, nextC) && !visited[nextR][nextC] && maze[nextR][nextC] == '1'){
	                visited[nextR][nextC] = true;
	                dist[nextR][nextC] = dist[curR][curC] + 1;
	                q.add(new Point(nextR, nextC));
	            }
	        }
	    }
	}
	
	static boolean isValid(int r, int c){
	    return r >= 0 && r < n && c >= 0 && c < m;
	}
}

class Point{
	    int r, c;
	    Point(int r, int c){
	        this.r = r;
	        this.c = c;
	    }
	}
