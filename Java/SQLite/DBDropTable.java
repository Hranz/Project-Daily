/*Programmer: Kristoffer Larson
 *Date: April 27, 2014
 *
 *Description: Connect to a DB and drop a table if it exists.
 *
 */

import java.sql.*;

public class DBDropTable
{
   Connection c = null;
   public DBDropTable()
   {
      //Connection c = null;
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
      table();
   }
   
   public void table()
   {
      //Connection c = null;
      Statement stmt = null;
      try {
         //Class.forName("org.sqlite.JDBC");
         //c = DriverManager.getConnection("jdbc:sqlite:test.db");
         stmt = c.createStatement();
         
         String sql = "drop table if exists COMPANY";
         stmt.executeUpdate(sql);
         System.out.println("Dropped table successfully");
         
         
         sql = "CREATE TABLE COMPANY " +
                   "(ID INT PRIMARY KEY     NOT NULL," +
                   " NAME           TEXT    NOT NULL, " + 
                   " AGE            INT     NOT NULL, " + 
                   " ADDRESS        CHAR(50), " + 
                   " SALARY         REAL)"; 
         stmt.executeUpdate(sql);
         stmt.close();
         c.close();
      } 
      catch ( Exception e ) {
         System.err.println( e.getClass().getName() + ": " + e.getMessage() );
         System.exit(0);
      }
      System.out.println("Table created successfully");
   }
   
   public static void main(String[] args)
   {
      
      DBDropTable app = new DBDropTable();
   }

}
