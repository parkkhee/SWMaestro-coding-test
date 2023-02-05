package test;
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String n;
    static Integer[] nums;
//    static String str = "";
    static boolean[] visited;

    public static void main(String[] args) throws IOException {

        n = br.readLine();

        nums = new Integer[n.length()];
        visited = new boolean[n.length()];

        for (int i = 0; i < n.length(); i++) {

            nums[i] = n.charAt(i) - '0';

        }

        Arrays.sort(nums,Collections.reverseOrder());


        for (int i = 0; i < nums.length; i++) {
            visited[i] = true;
            f(i,String.valueOf(nums[i]),1);
        }


    }

    public static void f(int cnt, String str, int idx) {

        if (idx == (nums.length-1)) {
            String result = str+nums[cnt];
            if (Integer.parseInt(result) % 30 == 0) {
                System.out.println(Integer.parseInt(result));
                System.exit(0);
            }
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            System.out.println("c:"+i + "s:"+str + "i:"+idx);
            if (!visited[i]) {
                visited[i] = true;
//                System.out.println(str);
//                str+=nums[i];
                f(i,str+nums[i], idx+1);
                visited[i] = false;
            }

        }

    }


}

