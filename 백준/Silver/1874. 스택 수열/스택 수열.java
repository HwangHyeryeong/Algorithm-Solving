import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] target = new int[n];
		for(int i = 0; i < n; i++)
			target[i] = sc.nextInt();
		
		Stack<Integer> s = new Stack<>();
		ArrayList<Character> ans = new ArrayList<>();
		int cur = 0;
		for(int i = 1; i <= n; i++) {
			s.push(i);
			ans.add('+');
			while(!s.isEmpty() && s.peek() == target[cur]) {
				ans.add('-');
				s.pop();
				cur++;
			}
		}
		while(!s.isEmpty() && s.peek() == target[cur]) {
			ans.add('-');
			s.pop();
			cur++;
		}
		
		if(s.size() == 0)
			for(char c : ans)
				System.out.println(c);
		else
			System.out.println("NO");
	}
}
