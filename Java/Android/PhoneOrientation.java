/*
   Programmer: Kristoffer Larson
   Date: February 10, 2014
   
   Description: Listens for the orientation of the phone
      and runs information on the UI thread. The listener
      won't start with an orientation with respect to he 
      phones current position, but will calculate orientation
      with respect to that of the origin.
*/
//Some of these probably aren't necessary
import android.app.Activity;
import android.graphics.drawable.GradientDrawable;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.OrientationEventListener;
import android.widget.TextView;
import android.widget.Toast;

import java.util.List;

public class PhoneOrientation extends Activity  {
    // Orientation X, Y, and Z values
    private TextView orientXValue;
    private OrientationEventListener sensorListener;
    boolean ready = false;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView (R.layout.main);
        orientXValue=(TextView) findViewById(R.id.orient_x_value);
        orientXValue.setText("0.00");

        sensorListener = new OrientationEventListener(this, SensorManager.SENSOR_DELAY_NORMAL) {
            @Override
            public void onOrientationChanged(final int orientation) {
                MyActivity.this.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        orientXValue.setText("Orientation: " + orientation);
                        //Log.e("the x value is :", ""+orientXValue.getX()); //Log phone orientation

                        if((orientation>355)||(orientation<5)||((orientation>85)&&(orientation<95)) //True when at certain orientations
                                ||((orientation>175)&&(orientation<185))||((orientation>265)&&(orientation<285))){
                            ready=true;
                        } else {
                            ready=false;
                        }

                        if (ready){
                            Log.e("yay","it works!!!"); //Log test
                        }
                    }
                });
            }
        };
        sensorListener.enable(); //Enables Listener
    }
}
