
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        Deque<Integer> dq = new LinkedList<>();

        for (int i = 1; i <= n; i++) {
            dq.offer(i);
        }

        sb.append("<");

        while (dq.size() !=1) {

            for (int i = 0; i < k - 1; i++) {
                dq.offer(dq.poll());
            }

            sb.append(dq.poll()+", ");

        }

        sb.append(dq.poll()+">");

        System.out.println(sb);

    }

}



