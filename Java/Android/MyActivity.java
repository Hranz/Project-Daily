package com.example.untitled;

import android.app.Activity;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
//import android.content.DialogInterface;
import android.os.Vibrator;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MyActivity extends Activity {
    /**
     * Called when the activity is first created.
     */
    Button host, connect;
    TextView txtInfo;
    EditText txtIP;
    Vibrator vibe;
    SensorManager sensorManager;
    Sensor sensor;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        host = (Button) findViewById(R.id.butHost);
        connect = (Button) findViewById(R.id.butConnect);
        txtInfo = (TextView) findViewById(R.id.txtInfo);
        txtIP = (EditText) findViewById(R.id.txtIP);

        host.setOnClickListener(onClickListener);
        connect.setOnClickListener(onClickListener);

        initializeVibrator();
        initializeSensors();
    }

    void initializeVibrator() {
        vibe = (Vibrator) getSystemService(SENSOR_SERVICE);
    }

    SensorEventListener eventListener = new SensorEventListener() {
        public void onSensorChanged(SensorEvent event) {
            if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
                txtInfo.setText(String.valueOf(event.values[0]));
                Log.i("workshop",String.valueOf(event.values[0]));
            }
        }

        public void onAccuracyChanged(Sensor sensor, int accuracy) {

        }
    };


    void initializeSensors() {
        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        Sensor sensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        sensorManager.registerListener(eventListener, sensor, SensorManager.SENSOR_DELAY_GAME);
    }

    View.OnClickListener onClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            if (v.equals(host)) {
                Server server = new Server(null);
                server.start();
                Log.i("workshop","host");
            } else if (v.equals(connect)) {
                Client client = new Client(String.valueof(txtIP.getText()));
                client.start();
                Log.i("workshop","connect");
            }
        }
    };
}
