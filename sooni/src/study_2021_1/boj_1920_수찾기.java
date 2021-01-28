package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1920_수찾기 {

	static int N, M;
	static int[] arr, num;
	static boolean flag;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		arr = new int[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		M = Integer.parseInt(br.readLine());
		num = new int[M];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M; i++) {
			num[i] = Integer.parseInt(st.nextToken());
		}
		
		int temp;
		Arrays.sort(arr);
		for(int i=0; i<M; i++) {
			temp = num[i];
			if(temp<arr[0] || temp>arr[N-1]) {
				System.out.println(0);
				continue;
			}
			
			flag=false;
			dfs(0, N-1, temp);
			if(flag) System.out.println(1);
			else System.out.println(0);
		}
		
	}
	
	private static void dfs(int s, int e, int temp) {
		int mid = (s+e)/2;
		
		if(flag) return;
		if(arr[mid]==temp) {
			flag=true;
			return;
		}
		if(s>e) {
			return;
		}
		
		if(arr[mid]<temp) {
			dfs(mid+1, e, temp);
		}else {
			dfs(s, mid-1, temp);
		}
	}
}
