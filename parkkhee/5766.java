
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n,m;
    static int[] player;


    public static void main(String[] args) throws IOException {


        while (true) {

            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            if (n == 0 && m == 0) {
                break;
            }

            int max = Integer.MIN_VALUE;
            player = new int[10001];


            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    int num = Integer.parseInt(st.nextToken());
                    player[num] +=1;
                    if (max < player[num]) {
                        max = player[num];
                    }
                }
            }


            for (int i = 0; i < 10001; i++) {
                if(max == player[i]){
                    player[i] =0;
                }
            }
            max = Integer.MIN_VALUE;
            for (int i = 0; i < 10001; i++) {
                if (max < player[i]) {
                    max = player[i];
                }
            }

            ArrayList<Integer> arr = new ArrayList<>();

            for (int i = 0; i < 10001; i++) {
                if (max == player[i]) {
                    arr.add(i);
                }
            }
            Collections.sort(arr);

            for (int i = 0; i < arr.size(); i++) {
                System.out.print(arr.get(i) + " ");

            }
            System.out.println();

        }


    }



}



