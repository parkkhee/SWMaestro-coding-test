package test;
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int goaln;
    static int[] line;
    static long end = Long.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        goaln = Integer.parseInt(st.nextToken());

        line = new int[n];

        for (int i = 0; i < n; i++) {
            line[i] = Integer.parseInt(br.readLine());
            end = Math.max(end, line[i]);
        }
        long start = 1;
        long mid = 0;

        while (start <= end) {
            mid = (start + end) / 2;
            long cnt =0;

            for (int i = 0; i < n; i++) {

                cnt += line[i] / mid;

            }

            if (cnt < goaln) {
                end = mid-1;
            }else {
                start = mid + 1;
            }

        }

        System.out.println(end);

    }


}

