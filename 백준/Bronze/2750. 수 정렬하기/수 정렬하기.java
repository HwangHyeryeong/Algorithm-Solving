import java.util.Scanner;

public class Main {
	
		public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		int[] sorted = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = sc.nextInt();

		mergeSort(arr, 0, n - 1, sorted);
		
		for(int i : arr)
			System.out.println(i);
	}
	
	static void mergeSort(int[] arr, int left, int right, int[] sorted) {
		if(left >= right) return;
		
		int mid = (left + right) / 2;
		
		mergeSort(arr, left, mid, sorted);
		mergeSort(arr, mid+1, right, sorted);
		
		merge(arr, left, right, mid, sorted);		
	}
	
	static void merge(int[] arr, int left, int right, int mid, int[] sorted) {
		int pl = left, pr = mid + 1, pc = left;
		
		while(pl <= mid && pr <= right) 
			sorted[pc++] = (arr[pl] <= arr[pr])? arr[pl++] : arr[pr++];
		
		while(pl <= mid)
			sorted[pc++] = arr[pl++];
		while(pr <= right)
			sorted[pc++] = arr[pr++];
		
		for(int i = left; i <= right; i++)
			arr[i] = sorted[i];
	}
}