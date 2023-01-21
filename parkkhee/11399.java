
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] nums;

    public static void main(String[] args) throws IOException {

        int num = Integer.parseInt(br.readLine());

        nums = new int[num];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < num; i++) {

            nums[i] = Integer.parseInt(st.nextToken());

        }

        Arrays.sort(nums);

        for (int i = 1; i < num; i++) {

            nums[i] = nums[i - 1] + nums[i];

        }

        int result =0;
        for (int i = 0; i < num; i++) {
            result += nums[i];
        }

        System.out.println(result);
        
    }



}

