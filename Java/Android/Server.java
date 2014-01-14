package com.example.untitled;

import android.util.Log;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * Created by Kristoffer on 1/13/14.
 */
public class Server extends Thread{
    ServerInterface serverInterface;

    public Server(ServerInterface serverInterface) {
        this.serverInterface = serverInterface;
    }

    @Override
    public void run() {
        super.run();
        try {
            ServerSocket serverSocket = new ServerSocket();
            serverSocket.setReuseAddress(true);
            Log.i("workshop", "waiting for connection");
            serverSocket.accept();
            Socket clientSocket = serverSocket.accept();
            Log.i("workshop", "wrote");

            BufferedReader reader = new BufferedReader( new InputStreamReader(
                    clientSocket.getInputStream()));

            String s = reader.readLine();
            Log.i("workshop", "read in " + String.valueOf(s));
            clientSocket.close();
            serverSocket.close();

        } catch (Exception e) {
            e.printStackTrace();

        }
    }

    public interface ServerInterface {
        public void gotData(String data);

    }
}
