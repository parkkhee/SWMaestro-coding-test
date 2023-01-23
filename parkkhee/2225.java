import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] dp; //long형으로도 가능


    public static void main(String[] args) throws IOException {


        st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        dp = new int[K+1][N+1];

        for (int i = 0; i <=N; i++) {  //K가 1일떄는 딱 한번
            dp[1][i]=1;
        }
        for (int i = 1; i <= K; i++) {  //0을 더해야 하는 경우는 (실제로 N >0이지만, N+0의 경우를 더해야 하므로) 무조건 한번
            dp[i][0] = 1;
        }

        re(K,N);

        System.out.println(dp[K][N]);

    }

    public static int re(int k, int n) {

        if (dp[k][n] != 0) {
            return dp[k][n];
        }

        for (int i = 0; i <= n; i++) {
            dp[k][n] = (dp[k][n] + re(k-1,n-i))%1000000000;  //줄여나가면서
        }

        return dp[k][n];

    }

}
