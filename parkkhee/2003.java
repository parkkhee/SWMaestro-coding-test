
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,m;
    static int[] num;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        num = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {

            num[i] = Integer.parseInt(st.nextToken());

        }

        int start =0;
        int end = 1;
        int cnt=0;


        while (start <= end) {

            if (end == n) {
                break;
            }
            int sum=0;
            for (int i = start; i <= end; i++) {
                sum += num[i];
            }

            if (sum == m) {
                cnt++;
                end++;
            } else if (sum > m) {
                start++;

            } else if (sum < m) {
                end++;
            }


        }

        System.out.println(cnt);



    }



}

