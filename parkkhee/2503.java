
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] ball;
    static int[] strike;
    static int[] num;
    static int cnt=0;

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        ball = new int[n];
        strike = new int[n];
        num = new int[n];

        for (int i = 0; i < n; i++) {

            st = new StringTokenizer(br.readLine());
            num[i] = Integer.parseInt(st.nextToken());
            strike[i] = Integer.parseInt(st.nextToken());
            ball[i] = Integer.parseInt(st.nextToken());

        }

        for (int i = 123; i <= 987; i++) {

            if(Integer.toString(i).charAt(0) == '0' || Integer.toString(i).charAt(1) == '0' || Integer.toString(i).charAt(2) == '0') continue;
            if(Integer.toString(i).charAt(0) == Integer.toString(i).charAt(1)) continue;
            if(Integer.toString(i).charAt(0) == Integer.toString(i).charAt(2)) continue;
            if(Integer.toString(i).charAt(2) == Integer.toString(i).charAt(1)) continue;

            for (int j = 0; j < n; j++) {
                int str =0;
                int bal =0;
                for (int k = 0; k < 3; k++) {
                    for (int h = 0; h < 3; h++) {
                        if (Integer.toString(i).charAt(h) == Integer.toString(num[j]).charAt(k)) {

                            if (k == h) {
                                str++;
                            }
                            bal++;

                        }
                    }


                }

                if (str == strike[j] && bal == ball[j]) {
                    cnt++;
                }
            }

        }


        System.out.println(cnt);



    }

}
