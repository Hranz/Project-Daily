/*

Programmers: Kris Larson

Description: Prints a count every cycle. Cycle times can
   be adjusted. Done in one class.
   
*/
import java.util.Timer;
import java.util.TimerTask;

public class TimeCounter extends TimerTask {
   private int times = 0;
   private static long interval = 1000; //In milliseconds
   private static int count = 10;
   
   public TimeCounter() {
      //run();
   }
 
   public void run() {
      if (times <= count) {
         System.out.println(times);
      }
      else {
         this.cancel();
         System.exit(0);
      }
      times++;
   }
    
    
   
   public static void main(String[] args) {
      Timer timer = new Timer("Printer");

      TimeCounter t = new TimeCounter();
 
      timer.schedule(t, 0, interval);
   }
}
