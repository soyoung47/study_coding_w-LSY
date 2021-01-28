/**
 * 
 * S1
 * using DP
 * 29480 kb
 * 312 ms
 * 
 */
package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1932_정수삼각형 {
	
	static long[][] map, dp;
	static int N;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());	// 삼각형
		map = new long[N+1][N+1];
		dp = new long[N+1][N+1];
		
		for(int i=1; i<N+1; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<i+1; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		dp[1][1] = map[1][1];
		for(int i=1; i<N+1; i++) {
			for(int j=1; j<i+1; j++) {
				dp[i][j] = Math.max(dp[i-1][j-1]+map[i][j], dp[i-1][j]+map[i][j]);
			}
		}
		
		//show();
		long answer = 0;
		for(int i=0; i<N+1; i++) {
			answer = Math.max(answer, dp[N][i]);
		}
		
		System.out.println(answer);
	}
	
	public static void show() {
		for(int i=1; i<N+1; i++) {
			for(int j=1; j<N+1; j++) {
				System.out.print(map[i][j]+"	");
			}
			System.out.println();
		}
		
		for(int i=1; i<N+1; i++) {
			for(int j=1; j<N+1; j++) {
				System.out.print(dp[i][j]+"	");
			}
			System.out.println();
		}
	}

}
