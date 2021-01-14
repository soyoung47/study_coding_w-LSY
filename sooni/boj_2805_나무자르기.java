package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_B_2805_나무자르기 {
	
	static int N;
	static long M;
	static long[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Long.parseLong(st.nextToken());
		arr = new long[N];
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++) {
			arr[i] = Long.parseLong(st.nextToken());
		}
		
		Arrays.sort(arr);
		long length = binarySearch();
		
		System.out.println(length);
	}
	
	private static long binarySearch() {
		long s = 1, e = arr[N-1]+1, mid=0, count=0;
		
		while(s<e) {
			mid = (s+e)/2;
			count = getTree(mid);
//			System.out.println(mid+" "+count);
			
			if(count<M) {
				e = mid;
			}else {
				s = mid+1;
			}
		}
		
		return e-1;
	}

	private static long getTree(long mid) {
		long sum=0;
		for(long i: arr) {
			if(i>mid) {
				sum += (i-mid);
			}
		}
		return sum;
	}
}
