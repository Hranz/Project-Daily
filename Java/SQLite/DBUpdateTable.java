/*Programmer: Kristoffer Larson
 *Date: April 26, 2014
 *
 *Description: Connect to a DB and update a table.
 *
 */

import java.sql.*;

public class DBUpdateTable
{
   Connection c = null;
   Statement stmt = null;
   
   public DBUpdateTable()
   {
      modify();
      select();
   }
   
   public void modify()
   {
      try {
         Class.forName("org.sqlite.JDBC");
         c = DriverManager.getConnection("jdbc:sqlite:test.db");
         c.setAutoCommit(false);
         System.out.println("Opened database successfully");
      
         stmt = c.createStatement();
         String sql = "UPDATE COMPANY set SALARY = 20000.00 where ID=1;";
         stmt.executeUpdate(sql);
         c.commit();
         sql = "UPDATE COMPANY set NAME = 'Jim' where ID=2;";
         stmt.executeUpdate(sql);
         c.commit();
         sql = "UPDATE COMPANY set AGE = 10 where ID=3;";
         stmt.executeUpdate(sql);
         c.commit();
         
         sql = "UPDATE COMPANY set ADDRESS = 'Washington BLVD' where ID=4;";
         stmt.executeUpdate(sql);
         c.commit();
         
         stmt.close();
         c.close();
      } 
      catch ( Exception e ) {
         System.err.println( e.getClass().getName() + ": " + e.getMessage() );
         System.exit(0);
      }
      System.out.println("Operation done successfully");
   }
   
   public void select()
   {
      try {
         Class.forName("org.sqlite.JDBC");
         c = DriverManager.getConnection("jdbc:sqlite:test.db");
         c.setAutoCommit(false);
         System.out.println("Opened database successfully");
      
         stmt = c.createStatement();
         ResultSet rs = stmt.executeQuery( "SELECT * FROM COMPANY;" );
         while ( rs.next() ) {
            int id = rs.getInt("id");
            String  name = rs.getString("name");
            int age  = rs.getInt("age");
            String  address = rs.getString("address");
            float salary = rs.getFloat("salary");
            System.out.println( "ID = " + id );
            System.out.println( "NAME = " + name );
            System.out.println( "AGE = " + age );
            System.out.println( "ADDRESS = " + address );
            System.out.println( "SALARY = " + salary );
            System.out.println();
         }
         rs.close();
         stmt.close();
         c.close();
      } 
      catch ( Exception e ) {
         System.err.println( e.getClass().getName() + ": " + e.getMessage() );
         System.exit(0);
      }
      System.out.println("Operation done successfully");
   }
   
   public static void main(String[] args)
   {
      DBUpdateTable app = new DBUpdateTable();
   }

}
