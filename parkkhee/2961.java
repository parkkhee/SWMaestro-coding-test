
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] tst;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        tst = new int[n][2];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; j++) {

                tst[i][j] = Integer.parseInt(st.nextToken());

            }

        }

        if (n == 1) {
            System.out.println(Math.abs(tst[0][0] - tst[0][1]));
            System.exit(0);
        }


        for (int i = 0; i < n; i++) {
            f(i,n,min);
        }

        System.out.println(min);

    }

    public static void f(int x, int cnt, int rs) {

        int mul = 1;
        int sum = 0;

        if (cnt == 0) {
            min = rs;
            return;
        }

        for (int i = x; i < cnt; i++) {
            mul *= tst[i][0];
        }
        for (int i = x; i < cnt; i++) {
            sum += tst[i][1];
        }

        f(x, cnt - 1, Math.min(Math.abs(mul - sum), rs));


    }


}



