import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int[] time = new int[n];
		for(int i = 0; i < n; i++)
			time[i] = Integer.parseInt(st.nextToken());
		
		Arrays.sort(time);
		
		int ans = 0;
		for(int i = 0, j = n; i < n; i++, j--) {
			ans += time[i] * j;
		}
		
		System.out.println(ans);		
	}
}
