
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] nums;
    static int[] cal = new int[4];
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;
    static int sum=0;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        nums = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            cal[i] = Integer.parseInt(st.nextToken());

        }

        re(0);

        System.out.println(max);
        System.out.println(min);

    }

    public static void re(int idx) {

        if (idx == n - 1) {
            min = Math.min(min, sum);
            max = Math.max(max, sum);
            sum =0;
            return;
        }

        for (int i = 0; i < 4; i++) {

            if (cal[i] != 0) {

                switch (i) {
                    case 0:
                        if (idx == 0) {
                            sum = nums[idx] + nums[idx + 1];
                        } else {
                            sum = sum + nums[idx+1];
                        }

                        cal[i]--;
                        re(idx+1);
                        cal[i]++;
                        break;
                    case 1:
                        if (idx == 0) {
                            sum = nums[idx] - nums[idx + 1];
                        } else {
                            sum = sum - nums[idx+1];
                        }

                        cal[i]--;
                        re(idx+1);
                        cal[i]++;
                        break;
                    case 2:
                        if (idx == 0) {
                            sum = nums[idx] * nums[idx + 1];
                        } else {
                            sum = sum * nums[idx+1];
                        }

                        cal[i]--;
                        re(idx+1);
                        cal[i]++;
                        break;
                    case 3:
                        if (idx == 0) {
                            sum = nums[idx] / nums[idx + 1];
                        } else {
                            sum = sum / nums[idx+1];
                        }

                        cal[i]--;
                        re(idx+1);
                        cal[i]++;
                        break;

                }


            }



        }

    }


}

