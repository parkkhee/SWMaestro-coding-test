import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class main {
        static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) {
        int[] map;

        StringTokenizer st = new StringTokenizer(br.readLine());
        map = new int[100];

        //사다리
        int N = Integer.parseInt(st.nextToken());
        //뱀
        int M = Integer.parseInt(st.nextToken());
        for(int i = 0 ; i < N ; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            map[start - 1] = end - 1;
        }

        for(int i = 0 ; i < M ; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            map[start - 1] = end - 1;
        }

        bfs();


    }

    public static void bfs(){

    }
}

