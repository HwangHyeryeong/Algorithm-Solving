import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
		
		mergeSort(time, 0, n-1);
		
		int ans = 0;
		for(int i = 0, j = n; i < n; i++, j--) {
			ans += time[i] * j;
		}
		
		System.out.println(ans);		
	}
	
	static void mergeSort(int[] arr, int start, int end) {
		if(start >= end) return;
		
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		
		merge(arr, start, end, mid);
	}
	
	static void merge(int[] arr, int start, int end, int mid) {
		int[] sorted = new int[end - start + 1];
		int pl = start, pr = mid + 1, pc = 0;
		
		while(pl <= mid && pr <= end) {
			sorted[pc++] = (arr[pl] < arr[pr])? arr[pl++] : arr[pr++];
		}
		
		while(pl <= mid)
			sorted[pc++] = arr[pl++];
		
		while(pr <= end)
			sorted[pc++] = arr[pr++];
		
		for(int i = start, j = 0; i <= end; i++, j++)
			arr[i] = sorted[j];
	}
}
