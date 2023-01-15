package test;

import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] num;
    static int n,m;
    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        num = new int[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
        }

        int cnt=0;
        int sum=0;

        for (int i = 0; i < num.length; i++) {

            sum+=num[i];
            re(i, cnt+1, sum);
            sum-=num[i];

        }

        System.out.println(max);

    }

    public static void re(int idx, int cnt, int sum) {

//        System.out.println("idx :" + idx + " cnt : " + cnt + " sum : " + sum);


        if (cnt == 3) {
            if (sum == m) {
                System.out.println(m);
                System.exit(0);
            } else if (sum < m) {
                max = Math.max(max, sum);
            }


        } else {

            for (int i = idx + 1; i < num.length; i++) {

                sum+=num[i];
                re(i, cnt + 1, sum);
                sum-=num[i];

            }

        }
    }
}



