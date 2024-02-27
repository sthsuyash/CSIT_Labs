using System;
using System.Collections.Generic;
using System.Data.SqlClient; // for sql connection
using System.Data;

// To connect with external data source like database, xml file
// System.SQLClient package should be imported
// to connect with database SQLConnection class is used and
// to execute the query SQLCommand class is used

/*
 
* Steps to connect with database:

1. Import SQLClient class
2. Create connection string that contains all the necessary parameter to connect with database like server, dbname and security
3. Create object of SQLConnection class to connect with server
4. Write necessary query and handle SQLException
5. Execute the query using SQLCommand class
 */

/*
SqlClient => sql query and .net application
SqlConnection => to create connection between server and sql
SqlCommand => to know if the sql are correct

SQLReader => to fetch data
 */
namespace DatabaseConnection
{
    class Insert
    {
        public void createTable()
        {
            try
            {
                String server_name = "KSUYASH";
                String dbname = "db_net";
                String connectionString = $"Data Source={server_name};Initial Catalog={dbname};Integrated Security=true";
                // integrated security = true means windows authentication
                // if we want to use sql server authentication then we have to provide username and password

                // in exam, data source can be SERVER

                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open(); // opening connection

                /* Creating table */
                string tableQuery = "CREATE TABLE tbl_emp(" +

                                    "id INT PRIMARY KEY IDENTITY(1,1)," +
                                    "name VARCHAR(255)," +
                                    "age INT," +
                                    "gender VARCHAR(50)," +
                                    "department VARCHAR(50)," +
                                    "salary FLOAT" +
                                    ")";

                /* Execute the query */
                SqlCommand sc = new SqlCommand(tableQuery, conn); // first parameter => query, second parameter => connection
                sc.ExecuteNonQuery(); // to execute the query
                // use it for insert, update and delete
                // not for display
                Console.WriteLine("Table created successfully");

            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public void insertData()
        {
            try
            {
                String server_name = "KSUYASH";
                String dbname = "db_net";
                String connectionString = $"Data Source={server_name};Initial Catalog={dbname};Integrated Security=true";
                // integrated security = true means windows authentication
                // if we want to use sql server authentication then we have to provide username and password

                // in exam, data source can be SERVER

                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open(); // opening connection

                /*Inserting into table */
                string insertQuery = "INSERT INTO tbl_emp" +
                    "(name, age, gender, department, salary)" +
                    "VALUES('Suyash', 22, 'Male', 'IT', 50000)";

                SqlCommand sc = new SqlCommand(insertQuery, conn);
                int response = sc.ExecuteNonQuery();

                if (response > 0)
                {
                    Console.WriteLine(response + " Data inserted successfully.");
                }
                else
                {
                    Console.WriteLine(response + " Data insertion failed.");
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
