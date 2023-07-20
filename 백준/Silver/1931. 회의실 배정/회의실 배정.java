import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Integer[][] meeting = new Integer[n][2];

		for(int i = 0; i < n; i++) {
			meeting[i][0] = sc.nextInt();
			meeting[i][1] = sc.nextInt();
		}

		Arrays.sort(meeting, (a,b) -> ((a[1] != b[1]) ? a[1] - b[1] : a[0] - b[0]));

		int ans = 0, end = 0;
		for(int i = 0; i < n; i++) {
			if(meeting[i][0] == meeting[i][1]) {
				end = meeting[i][1];
				ans++;
				continue;
			}
			if(end <= meeting[i][0]) {
				end = meeting[i][1];
				ans++;
			}
		}

		System.out.println(ans);
		sc.close();
	}
}