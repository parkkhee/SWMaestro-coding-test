package test;
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[] money;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        money = new int[n];

        int s = Integer.MAX_VALUE;
        int e = Integer.MIN_VALUE;
        int mid;

        for (int i = 0; i < n; i++) {

            money[i] = Integer.parseInt(br.readLine());

            s = Math.min(money[i], s);
            e = Math.max(money[i], e);


        }

        mid = (s + e) / 2;


        while (s <= e) {
            int rm = mid;
            int cnt=0;
            for (int i = 0; i < n; i++) {

                if (rm < money[i]) {
                    while (rm - money[i] < 0) {
                        rm += mid;
                        cnt++;
                    }
                    rm = rm - money[i];
                    continue;
                }

                if (cnt > m) {
                    s=mid+1;
                    mid = (s + e) / 2;
                    break;
                }

                rm = rm - money[i];


            }
            if (cnt < m) {
                e = mid-1;
                mid = (s + e) / 2;
            } else if(cnt==m){
                break;
            }
        }

        System.out.println(mid);



    }


}

