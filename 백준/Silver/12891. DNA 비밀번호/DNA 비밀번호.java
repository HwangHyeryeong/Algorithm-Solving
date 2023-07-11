import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		String str = br.readLine();

		st = new StringTokenizer(br.readLine());
		int[] pattern = new int[4];
		pattern[0] = Integer.parseInt(st.nextToken()); //A
		pattern[1] = Integer.parseInt(st.nextToken()); //C
		pattern[2] = Integer.parseInt(st.nextToken()); //G
		pattern[3] = Integer.parseInt(st.nextToken()); //T


		int cnt = 0;
		HashMap<Character, Integer> curPattern = new HashMap<>();
		curPattern.put('A', 0);
		curPattern.put('C', 0);
		curPattern.put('G', 0);
		curPattern.put('T', 0);


		for(int i = 0; i < p; i++) {
			if(curPattern.containsKey(str.charAt(i)))
				curPattern.put(str.charAt(i), curPattern.get(str.charAt(i)) + 1);
			else
				curPattern.put(str.charAt(i), 1);
		}

		for(int i = p; i <= str.length(); i++) {
			boolean find = true;
			if(pattern[0] > curPattern.get('A')) find = false;
			if(pattern[1] > curPattern.get('C')) find = false;
			if(pattern[2] > curPattern.get('G')) find = false;
			if(pattern[3] > curPattern.get('T')) find = false;
			if(find) cnt++;

			if(i < str.length()) {
				curPattern.put(str.charAt(i - p), curPattern.get(str.charAt(i - p)) - 1);
				curPattern.put(str.charAt(i), curPattern.get(str.charAt(i)) + 1);	
			}
		}

		System.out.println(cnt);
	}
}
