
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String str,alphb;
    static int cnt=0;


    public static void main(String[] args) throws IOException {

        str = br.readLine();

        alphb = br.readLine();

        for (int i = 0; i < str.length(); i++) {

            if (str.substring(i).length() < alphb.length()) {  //substring(시작idx,끝) 넣어줘야 알아서 갯수를 파악하고 길이 비교가능
                break;
            }

            if (alphb.equals(str.substring(i, i + alphb.length()))) {  //equals()= string끼리 같은지 비교 가능, substrig()= 필요한 string 부분만큼 추출가능

                cnt++;
                i += alphb.length() -1;

            }

        }

        System.out.println(cnt);

    }


}



