
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[][] line;

    public static void main(String[] args) throws IOException {

        int n = Integer.parseInt(br.readLine());

        line = new int[n][2];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            line[i][0] = Integer.parseInt(st.nextToken());
            line[i][1] = Integer.parseInt(st.nextToken());

        }

        int min = line[0][0];
        int max = line[0][1];
        int len = max - min;

        for (int i = 1; i < line.length; i++) {

            if (min < line[i][0] && max > line[i][1]) {
                continue;
            } else if (line[i][1] < min) {
                len += line[i][1] - line[i][0];
            } else if (line[i][0] > max) {
                len += line[i][1] - line[i][0];
            } else if (line[i][0] < min && line[i][1] > max) {
                len = line[i][1] - line[i][0];
            } else if (line[i][0] <= min && line[i][1] <= max) {
                len = max - line[i][0];
                min = line[i][0];
            } else {
                len = line[i][1] - max;
                max = line[i][1];
            }

        }

        System.out.println(len);


    }



}



