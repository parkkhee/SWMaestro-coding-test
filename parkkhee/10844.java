
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static long[][] dp;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        dp = new long[n+1][10];

        for (int i = 1; i <= n; i++) {
            dp[1][i] = 1L;
        }

        for (int i = 2; i <= n; i++) {

            for (int j = 1; j <= 9; j++) {

                if()

                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            }

        }

    }



}



