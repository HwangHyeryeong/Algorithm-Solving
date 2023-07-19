import java.util.Scanner;

public class Main {
	static int n, cnt = 0;
	static int[] location;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		location = new int[n];

		dfs(0);
		System.out.println(cnt);
	}

	static void dfs(int cur) {
		if(cur == n) {
			cnt++;
			return;
		}

		for(int i = 0; i < n; i++) {
			location[cur] = i;
			if(valid(cur))
				dfs(cur + 1);
		}
	}

	static boolean valid(int cur) {
		for(int i = 0; i < cur; i++) {
			if(location[i] == location[cur] || Math.abs(location[cur] - location[i]) == (cur - i))
				return false;
		}

		return true;
	}
}
