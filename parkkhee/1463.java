
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] dp;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        dp = new int[n+1];

        dp[1] = 0;

        re(n);

        bw.append(String.valueOf(dp[n]));

        bw.flush();
        bw.close();

//        int cnt=0;
//
//        while (n!=1) {
//            if (n % 3 == 0) {
//                n = n / 3;
//                cnt++;
//            } else if (n % 2 == 0) {
//                n = n / 2;
//                cnt++;
//            } else {
//                n = n - 1;
//                cnt++;
//            }
//        }

//        System.out.println(cnt);



    }

    public static int re(int num) {

        if (num % 3 == 0) {
            dp[num] = re(num/3) + 1;
        } else if (num % 2 == 0) {
            dp[num] = re(num / 2) + 1;
        } else {
            dp[num] = re(num - 1) + 1;
        }


        return dp[num];

    }


}

