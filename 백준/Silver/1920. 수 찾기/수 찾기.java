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

		int[] nums = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			nums[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(nums);
		
		st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < m; i++) {
			int target = Integer.parseInt(st.nextToken());
			
			int left = 0, right = n - 1;
			boolean find = false;
			while(left <= right) {
				int mid = (left + right) / 2;

				if(nums[mid] == target) {
					find = true;
					break;
				}
				
				if(target > nums[mid])
					left = mid + 1;
				else
					right = mid - 1;
			}
			System.out.println(find? 1 : 0);
		}
		
	}
}
