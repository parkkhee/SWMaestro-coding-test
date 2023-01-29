
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] alc;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        alc = new int[n+1];

        for (int i = 1; i < n + 1; i++) {
            st = new StringTokenizer(br.readLine());
            alc[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < n + 1; i++) {
            f(0, 0, 0);
        }


        System.out.println(max);


    }

    public static void f(int num, int idx, int sum) {
        if (idx == 3) {
            f(num + 1, 0, sum);
        }

        if (num > n) {
            max = Math.max(max, sum);
            return;
        }

        for (int i = num+1; i < n + 1; i++) {
            f(i, idx + 1, sum + alc[num]);
        }

    }




}

