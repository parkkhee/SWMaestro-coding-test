import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n;
  
    public static void main(String[] args) throws IOException {
        
        n = Integer.parseInt(br.readLine());

        int[] dp = new int[1001]; // new int[n+1] 로 하면 런타임에러(ArrayIndexOutOfBounds) 발생
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
        System.out.println(dp[n]);
    }
}
