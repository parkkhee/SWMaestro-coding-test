
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] meetings;
//    static int max = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());

        meetings = new int[n][2];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 2; j++) {

                meetings[i][j] = Integer.parseInt(st.nextToken());
            }

        }

        Arrays.sort(meetings, new Comparator<int[]>() {
                    @Override
                    public int compare(int[] o1, int[] o2) {
                        if (o1[1] == o2[1]) {
                            return o1[0] - o2[0];
                        } else {
                            return o1[1] - o2[1];
                        }
                    }
                }
        );

        int end = 0;
        int cnt=0;

        for (int i = 0; i < n; i++) {
//            re(i,1);
            if (end <= meetings[i][0]) {
                end = meetings[i][1];
                cnt++;
            }

        }


        System.out.println(cnt);

    }

//    public static void re(int idx,int cnt) {
//
//        if (idx == n - 1) {
//            max = Math.max(max , cnt);
//            return;
//        }
//
//        for (int i = 0; i < n; i++) {
//
//            if (idx >= i) {
//                continue;
//            }
//
//            if (meetings[idx][1] <= meetings[i][0]) {
////                System.out.println(cnt);
//                re(i,cnt+1);
//            }
//
//
//        }
//
//        max = Math.max(max , cnt);
//
//    }


}

