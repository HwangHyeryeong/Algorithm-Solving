import java.util.Scanner;

public class Main {
	static int n, k, cnt = 0;
	static int[] coins;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		k = sc.nextInt();
		coins = new int[n];
		for(int i = 0; i < n; i++)
			coins[i] = sc.nextInt();
		
		for(int i = n-1; i >= 0; i--) {
			int numOfCurCoin = k / coins[i];
			cnt += numOfCurCoin;
			k -= (numOfCurCoin * coins[i]);
		}
		
		System.out.println(cnt);
	}
}
