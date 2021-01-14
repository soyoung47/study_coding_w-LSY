package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_B_1654_랜선자르기 {
	
	static int K;
	static long N;
	static long[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		K = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr = new long[K];
		
		for(int i=0; i<K; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		
		Arrays.sort(arr);
		long count = binarySearch();
		
		System.out.println(count);
		
	}
	
	private static long binarySearch() {
		
		long s=1, e=arr[K-1]+1, mid=0, count=0;
		while(s<e) {
			mid=(s+e)/2;
			
			count = getLine(mid);
			
			if(count<N) {
				e=mid;
			}else {
				s=mid+1;
			}
		}
		
		return e-1;
	}

	private static long getLine(long mid) {
		long sum=0;
		for(long i: arr) {
			sum += (i/mid);
		}
		return sum;
	}

}
