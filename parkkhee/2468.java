import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[][] map;
    static boolean[][] visited;
    static int max = Integer.MIN_VALUE;
    static int[] xx = {-1, 1, 0, 0};
    static int[] yy = {0, 0, -1, 1};

    public static class Node {
        int x,y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;

        }

    }



    public static void main(String[] args) throws IOException {
        int result =1;  // 하나인 경우가 있으니 1로 

        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {

                //int n2 = Integer.parseInt(st.nextToken());

                map[i][j] = Integer.parseInt(st.nextToken());

                max = Math.max(map[i][j], max);


            }

        }


        for (int i = 1; i <= max; i++) {
            init();  // visited를 전부 초기화 시키는 함수
            result = Math.max(bfs(i),result);
        }

        System.out.println(result);


    }

    public static void init() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
    }

    public static int bfs(int hight) {
        int cnt=0; // 계속 초기화 해줘야지

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if(map[i][j] <= hight || visited[i][j]) continue;

                Deque<Node> dq = new LinkedList<>();

                dq.offer(new Node(i, j));
                visited[i][j] = true;

                while (!dq.isEmpty()) {

                    Node node = dq.poll();


                    for (int d = 0; d < 4; d++) {
//                        System.out.println(node.x + xx[d] + "   " +  (node.y + yy[d]));

                        if (boundck(node.x + xx[d], node.y + yy[d]) && !visited[node.x + xx[d]][node.y + yy[d]]) {
//                            System.out.println(node.x + xx[d] + "   " +  (node.y + yy[d]) + "sadsa");
                            if (map[node.x + xx[d]][node.y + yy[d]] > hight) {
                                dq.offer(new Node(node.x + xx[d], node.y + yy[d]));
                                visited[node.x + xx[d]][node.y + yy[d]] = true;
                            }
                        }

                    }
                }
                cnt++;


            }
        }

        return cnt;


    }

    public static boolean boundck(int x, int y) {

        if (x >= 0 && y >= 0 && x < n && y < n) {
            return true;
        } else {
            return false;
        }

    }



}

