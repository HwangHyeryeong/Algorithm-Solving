import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static char[][] graph;
    static int[][] dist;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        graph = new char[n][m];
        visited = new boolean[n][m];
        dist = new int[n][m];

        for(int i = 0; i < n; i++){
            String tmp = br.readLine();
            graph[i] = tmp.toCharArray();
        }

        bfs(0, 0);

        System.out.println(dist[n-1][m-1]);
    }

    static void bfs(int x, int y){
        Queue<Loc> q = new LinkedList<>();

        visited[x][y] = true;
        dist[x][y] = 1;
        q.add(new Loc(x, y));

        while(!q.isEmpty()){
            int curX = q.peek().x;
            int curY = q.peek().y;
            q.poll();

            for(int i = 0; i < 4; i++){
                int nextX = curX + dx[i];
                int nextY = curY + dy[i];

                if(nextX >= 0 && nextX < m && nextY >= 0 && nextY < n){
                    if(!visited[nextY][nextX] && graph[nextY][nextX] == '1'){
                        visited[nextY][nextX] = true;
                        dist[nextY][nextX] = dist[curY][curX] + 1;
                        q.add(new Loc(nextX, nextY));
                    }
                }
            }
        }
    }
}

class Loc{
    int x;
    int y;

    Loc(int x, int y){
        this.x = x;
        this.y = y;
    }
}