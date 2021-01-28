package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_2110_공유기설치 {
	
	static int N, C;
	static long[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new long[N];
		
		for(int i=0; i<N; i++) {
			arr[i] = Long.parseLong(br.readLine());
		}
		
		Arrays.sort(arr);
		long dis = binarySearch();
		
		System.out.println(dis);
		
	}
	
	private static long binarySearch() {
		long s=1, e=arr[N-1]-arr[0], mid=0, dis=1;
		
		while(s<e) {
			mid = (s+e)/2;
			
			if(getWifi(mid)>=C) {
				dis = Math.max(dis, mid);
				s = mid+1;
			}else {
				e = mid;
			}
		}
		
		return dis;
	}

	private static long getWifi(long mid) {
		
		int cnt=1; long dis=arr[0];
		for(int i=1; i<N; i++) {
			if(arr[i]>=dis+mid) {
				dis=arr[i];
				cnt++;
			}
		}
		
		return cnt;
	}

}
