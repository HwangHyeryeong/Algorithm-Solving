import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = 1; i <= n; i++)
			q.add(i);
		
		StringBuilder ans = new StringBuilder();
		ans.append("<");
		while(q.size() != 1) {
			for(int i = 1; i < k; i++)
				q.add(q.poll());
			ans.append(q.poll() + ", ");
		}
		ans.append(q.poll() + ">");
		
		System.out.println(ans);
	}
}