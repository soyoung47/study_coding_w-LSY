/**
 * 
 * S3
 * Using DP
 * 18552 kb
 * 168 ms
 * 
 */

package study_2021_1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class boj_1463_1로만들기 {
	
	static int[] dp;
	static int N;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		dp = new int[N+1];
		Arrays.fill(dp, N+1);
		
		dp[N]=0;
		for(int i=N; i>0; i--) {
			if(i%3==0) {
				dp[i/3] = Math.min(dp[i/3], dp[i]+1);
			}
			
			if(i%2==0) {
				dp[i/2] = Math.min(dp[i/2], dp[i]+1);
			}
			
			dp[i-1] = Math.min(dp[i-1], dp[i]+1);
		}
		
		System.out.println(dp[1]);
	}

}
