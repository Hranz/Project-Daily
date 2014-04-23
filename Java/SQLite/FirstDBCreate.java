/*Programmer: Kristoffer Larson
 *Date: April 22, 2014
 *
 *Description: Create a test.db
 *
 */
import java.sql.*;

public class FirstDBCreate
{
   public FirstDBCreate()
   {
      Connection c = null;
      try 
      {
         Class.forName("org.sqlite.JDBC");
         c = DriverManager.getConnection("jdbc:sqlite:test.db");
      } 
      catch ( Exception e ) 
      {
         System.err.println( e.getClass().getName() + ": " + e.getMessage() );
         System.exit(0);
      }
      System.out.println("Opened database successfully");
   }
   
   public static void main(String[] args)
   {
      FirstDBCreate app = new FirstDBCreate();
   }

}
