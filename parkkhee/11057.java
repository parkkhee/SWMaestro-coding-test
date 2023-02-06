
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static int[][] dp;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        dp = new int[n+1][10];

        for (int i = 0; i < 10; i++) {
            dp[0][i] = 0;
            dp[1][i] = 1;
        }

        if (n == 1) {
            System.out.println(10);
            System.exit(0);
        }



        for (int i = 2; i < n+1; i++) {
            for (int j = 0; j < 10; j++) {

                for (int a = j; a < 10; a++) {
                    dp[i][j] += dp[i - 1][a];
                    dp[i][j] %= 10007;
                }

            }
        }

        int result=0;
        for (int i = 0; i < 10; i++) {
            result = (result + dp[n][i])%10007;
        }

        System.out.print(result);

    }


}



