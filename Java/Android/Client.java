package com.example.untitled;

import android.util.Log;

import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.net.Socket;

/**
 * Created by Kristoffer on 1/13/14.
 */
public class Client extends Thread {
    String ip;
    public Client(String ip) {
        this.ip = ip;
    }

    @Override
    public void run() {
        super.run();
        try {
            Log.i("workshop", "starting connection");
            Socket socket = new Socket(ip, 12345);
            socket.setReuseAddress(true);
            socket.setKeepAlive(true);
            Log.i("workshop", "starting established");

            BufferedWriter writer = new BufferedWriter(
                    new OutputStreamWriter(
                            socket.getOutputStream()));
            writer.write("Hello World");
            writer.newLine();
            Log.i("workshop", "wrote data");
            writer.flush();
            writer.close();
            Log.i("workshop", "connection closed");


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
