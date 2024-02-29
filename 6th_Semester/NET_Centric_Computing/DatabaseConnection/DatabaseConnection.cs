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
    class DatabaseConnection
    {
        public void CreateTable()
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
                string tableQuery = "CREATE TABLE tbl_emp IF_NOT_EXISTS(" +

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

        public void InsertData()
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

        /*
         * Insert data from input of user
         */
        public void InsertUserInput()
        {
            try
            {
                String connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=true";

                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open();

                Console.Write("Enter name: ");
                string name = Console.ReadLine();

                Console.Write("Enter age: ");
                int age = Convert.ToInt32(Console.ReadLine());

                Console.Write("Enter gender: ");
                string gender = Console.ReadLine();

                Console.Write("Enter department: ");
                string department = Console.ReadLine();

                Console.Write("Enter salary: ");
                float salary = float.Parse(Console.ReadLine());

                string insertQuery = "INSERT INTO tbl_emp" +
                    "(name, age, gender, department, salary)" +
                    "VALUES (@name, @age, @gender, @department, @salary)";

                SqlCommand sc = new SqlCommand(insertQuery, conn);

                sc.Parameters.AddWithValue("@name", name);
                sc.Parameters.AddWithValue("@age", age);
                sc.Parameters.AddWithValue("@gender", gender);
                sc.Parameters.AddWithValue("@department", department);
                sc.Parameters.AddWithValue("@salary", salary);

                int response = sc.ExecuteNonQuery();
                if (response > 0)
                {
                    Console.WriteLine(response + " Data inserted successfully.");
                }

            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        /*
         * Get all data from database
         */
        public void GetAllData()
        {
            try
            {
                string connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=true";

                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open();

                string fetchQuery = "SELECT * FROM tbl_emp";
                // to fetch the  data, ExecuteReader is used.
                SqlCommand sc = new SqlCommand(fetchQuery, conn);

                SqlDataReader response = sc.ExecuteReader();

                Console.WriteLine();
                Console.WriteLine("---------------------------------------");
                Console.WriteLine("Data from database:");
                Console.WriteLine("---------------------------------------");
                Console.WriteLine();

                while (response.Read())
                {
                    Console.WriteLine($"Id: {response["id"]}");
                    Console.WriteLine($"Name: {response["name"]}");
                    Console.WriteLine($"Age: {response["age"]}");
                    Console.WriteLine($"Gender: {response["gender"]}");
                    Console.WriteLine($"Department: {response["department"]}");
                    Console.WriteLine($"Salary: {response["salary"]}");
                    Console.WriteLine("--------------------------------------\n");
                }

            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        /*
         * Get data of individual user by ID
         */
        public void GetDataById()
        {
            try
            {
                string connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=true";
                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open();

                string fetchQuery = "SELECT * FROM tbl_emp WHERE id=@id";
                SqlCommand sc = new SqlCommand(fetchQuery, conn);

                Console.Write("Enter id to get: ");
                int id = Convert.ToInt32(Console.ReadLine());
                sc.Parameters.AddWithValue("@id", id);

                SqlDataReader response = sc.ExecuteReader();
                while (response.Read())
                {
                    Console.WriteLine($"Id: {response["id"]}");
                    Console.WriteLine($"Name: {response["name"]}");
                    Console.WriteLine($"Age: {response["age"]}");
                    Console.WriteLine($"Gender: {response["gender"]}");
                    Console.WriteLine($"Department: {response["department"]}");
                    Console.WriteLine($"Salary: {response["salary"]}");
                }
            }
            catch(SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        /*
         * Update the data of user by ID
         */
        public void UpdateData()
        {
            try
            {
                string connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=true";
                SqlConnection conn = new SqlConnection(connectionString);

                conn.Open();

                string updateQuery = "UPDATE tbl_emp SET " +
                    "name=@name, salary=@salary " +
                    "WHERE id=@id";
                Console.Write("Enter the id of user you want to update: ");
                int id = Convert.ToInt32(Console.ReadLine());

                Console.Write("Enter new name: ");
                string name = Console.ReadLine();

                Console.Write("Enter new salary: ");
                float salary = float.Parse(Console.ReadLine());

                SqlCommand sc = new SqlCommand(updateQuery, conn);
                sc.Parameters.AddWithValue("@id", id);
                sc.Parameters.AddWithValue("@name", name);
                sc.Parameters.AddWithValue("@salary", salary);

                int response = sc.ExecuteNonQuery();
                if (response > 0)
                {
                    Console.WriteLine("Data updated.");
                }

            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public void DeleteData()
        {
            try
            {
                string connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=true";
                SqlConnection conn = new SqlConnection(connectionString);

                conn.Open();

                string deleteQuery = "DELETE FROM tbl_emp WHERE id=@id";

                Console.WriteLine("Enter the id to delete: ");
                int id = Convert.ToInt32(Console.ReadLine());

                SqlCommand sc = new SqlCommand(deleteQuery, conn);
                sc.Parameters.AddWithValue("@id", id);
            }
            catch(SqlException e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
