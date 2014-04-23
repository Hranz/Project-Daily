/*Programmer: Kristoffer Larson
 *Date: April 23, 2014
 *
 *Description: Create a test.db and make a table in it.
 *
 */

import java.sql.*;

public class DBTable
{
   Connection c = null;
   public DBTable()
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
         //System.out.println("Opened database successfully");
      
         stmt = c.createStatement();
         String sql = "CREATE TABLE COMPANY " +
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
      
      DBTable app = new DBTable();
   }

}
