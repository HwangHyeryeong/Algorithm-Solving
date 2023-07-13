import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main  {
	static ArrayList<StringBuilder> result = new ArrayList<>();
	static char[] str;
	static int n;
	static int[] select;
	static boolean[] isSelected;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String input;
		while((input= br.readLine()) != null) {
			st = new StringTokenizer(input);			
			str = st.nextToken().toCharArray();
			Arrays.sort(str);
			n = Integer.parseInt(st.nextToken());
			select = new int[str.length];
			isSelected = new boolean[str.length];
			
			permutation(0);
			
			if(result.size() < n)
				System.out.println(input + " = No permutation");
			else
				System.out.println(input + " = " + result.get(n - 1));
			
			result.clear();
		}
		
	}
	
	public static void permutation(int cnt) {
		if(cnt == str.length) {
			StringBuilder tmp = new StringBuilder();
			for(int i = 0; i < select.length; i++) 
				tmp.append(str[select[i]]);
			result.add(tmp);
			return;
		}
		
		for(int i = 0; i < select.length; i++) {
			if(isSelected[i] == true) continue;
			
			select[cnt] = i;
			isSelected[i] = true;
			permutation(cnt+1);
			isSelected[i] = false;
		}
	}
}
