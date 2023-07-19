import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static final int MAX = 100000; 
	static int n, k;
	static int[] time = new int[MAX + 1];
	static boolean[] visited = new boolean[MAX + 1];
	static Queue<Integer> q = new LinkedList<>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		
		bfs(n);
		System.out.println(time[k]);
	}
	
	static void bfs(int cur) {
		visited[cur] = true;
		time[cur] = 0;
		q.add(cur);

		while(!q.isEmpty()) {
			int x = q.poll();
			
			if(x == k) break;
			
			nextMove(x, x * 2);
			nextMove(x, x - 1);
			nextMove(x, x + 1);
		}
	}
	
	static void nextMove(int x, int next) {
		if(next >= 0 && next <= MAX && !visited[next]) {
			visited[next] = true;
			q.add(next);
			time[next] = time[x] + 1;
		}
	}
}
