import java.util.Scanner;

public class Main {
	static int n, r;
	static int[] s, b;
	static boolean[] isSelected;
	static int ans = 2_000_000_000;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		isSelected = new boolean[n];
		s = new int[n];
		b = new int[n];
		for(int i = 0; i < n; i++) {
			s[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}

		subset(0);

		System.out.println(ans);
	}

	static void subset(int cnt) {
		if(cnt == n) {
			int curS = 1, curB = 0;
			for(int i = 0; i < n; i++) {
				if(isSelected[i]) {
					curS *= s[i];
					curB += b[i];
				}
			}
			if(curB != 0) {
				int curSub = Math.abs(curB - curS);
				ans = (ans < curSub)? ans : curSub;
			}
			return;
		}

		isSelected[cnt] = true;
		subset(cnt + 1);

		isSelected[cnt] = false;
		subset(cnt + 1);
	}
}