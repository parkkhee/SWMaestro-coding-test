
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
    static long[] dp;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        dp = new long[1000001];

        for (int i = 0; i < dp.length; i++) {
            dp[i] = -1;
        }

        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        System.out.println(re(n));

    }

    public static long re(int num) {

        if (dp[num] == -1) {
            dp[num] = (re(num-1) + re(num-2)) % 15746;
        }

        return dp[num];

    }


}



