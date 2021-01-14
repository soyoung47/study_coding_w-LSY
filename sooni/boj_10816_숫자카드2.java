package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_B_10816_숫자카드2 {

	static int N, M;
	static int[] arr1, arr2;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		N = Integer.parseInt(st.nextToken());
		arr1 = new int[N];

		st = new StringTokenizer(br.readLine());
		int temp;
		for(int i=0; i<N; i++) {
			temp = Integer.parseInt(st.nextToken());
			arr1[i] = temp;
		}
		
		M = Integer.parseInt(br.readLine());
		arr2 = new int[M];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<M; i++) {
			arr2[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr1);
		
		int lower, upper;
		for(int i=0; i<M; i++) {
			temp = arr2[i];
			lower = lowerBound(0, N, temp);
			upper = upperBound(0, N, temp);
			
			sb.append((upper-lower)).append(' ');
		}
		
		System.out.println(sb.toString());
		
	}
	private static int upperBound(int s, int e, int temp) {
		while(s<e) {
			int mid=(s+e)/2;
			if(arr1[mid]<=temp) {
				s=mid+1;
			}else {
				e=mid;
			}
		}
		
		return e;
	}
	private static int lowerBound(int s, int e, int temp) {
		while(s<e) {
			int mid=(s+e)/2;
			if(arr1[mid]>=temp) {
				e=mid;
			}else {
				s=mid+1;
			}
		}
		
		return e;
	}
}
