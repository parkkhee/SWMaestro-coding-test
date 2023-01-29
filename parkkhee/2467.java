
import java.io.*;
import java.nio.Buffer;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static Long[] nums;
    static Long solution = Long.MAX_VALUE;
    static Long solf;
    static Long solt;

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        nums = new Long[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nums[i] = Long.parseLong(st.nextToken());
        }

//        arr = new ArrayList<>();
        for (int i = 0; (n%2==1 ? i <=n/2+1 : i < n/2); i++) {

            for (int j = n-1; (n%2==1 ? j >n/2+1 : j >=n/2); j-- ) {

                if (nums[i] + nums[j] == 0) {
                    System.out.println(nums[i] + " " + nums[j]);
                    System.exit(0);
                }
                if(Math.abs(nums[i] + nums[j]) > solution) break;

                solution = Math.min(Math.abs(nums[i] + nums[j]) , solution);
                solf = nums[i];
                System.out.println("fi: " + nums[i]);
                solt = nums[j];
                System.out.println("fj: " + nums[j]);
            }

        }

//        for (int i = 0; i <=1; i++) {
//            System.out.print(arr.get(i) + " ");
//        }
        System.out.println(solf + " " + solt);

    }


}



