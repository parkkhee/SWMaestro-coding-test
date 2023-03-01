package org.example;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {


        int n = Integer.parseInt(br.readLine());

        int wint;
        int mT;
        int[] score = {0, 0};
        int[] ans_time = {0, 0};
        Record[] records = new Record[n];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            wint = Integer.parseInt(st.nextToken());
            String tmp = st.nextToken();
            String[] time = tmp.split(":");
            mT = Integer.parseInt(time[0]) * 60 + Integer.parseInt(time[1]);
            records[i] = new Record(wint, mT);
        }

        wint = records[0].team;
        score[wint - 1] += 1;
        mT = records[0].time;

        for (int i = 1; i < n; i++) {
            int tmpT = records[i].team;
            int tmpMT = records[i].time;
            if (score[0] > score[1]) {
                ans_time[0] += (tmpMT - mT);
            }
            if (score[0] < score[1]) {
                ans_time[1] += (tmpMT - mT);
            }
            score[tmpT - 1] += 1;

            mT = tmpMT;

        }

        if (score[0] > score[1]) {
            ans_time[0] += (48 * 60 - mT);
        }
        if (score[0] < score[1]) {
            ans_time[1] += (48 * 60 - mT);
        }

        for (int i = 0; i < 2; i++) {
            int h = ans_time[i] / 60;
            int m = ans_time[i] % 60;
            String hour;
            String min;
            if (h < 10) {
                hour = "0" + Integer.toString(h);
            }else {
                hour = Integer.toString(h);
            }

            if (m < 10) {
                min = "0" + Integer.toString(m);
            }else {
                min = Integer.toString(m);
            }

            System.out.println(hour + ":" + min);

        }
    }
}

class Record {
    int team;
    int time;

    public Record(int team, int time) {
        this.team = team;
        this.time = time;
    }
}
