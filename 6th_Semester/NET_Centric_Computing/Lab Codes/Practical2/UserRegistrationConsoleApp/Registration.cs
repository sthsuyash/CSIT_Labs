using System;
using System.Data.SqlClient;

namespace UserRegistrationConsoleApp
{
    class Registration
    {
        // Method to create connection
        public SqlConnection CreateConnection()
        {
            string connectionString = "Data Source=KSUYASH;Initial Catalog=UserRegistrationPractical;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            return conn;
        }

        // Method to create table
        public void CreateTable()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();
                string createTableQuery = "CREATE TABLE tbl_registration(" +
                    "id INT PRIMARY KEY IDENTITY(1, 1)," +
                    "username VARCHAR(50)," +
                    "password VARCHAR(50)," +
                    "repassword VARCHAR(50)," +
                    "gender VARCHAR(10)," +
                    "course VARCHAR(50)," +
                    "country VARCHAR(50)" +
                    ")";

                SqlCommand sc = new SqlCommand(createTableQuery, conn);
                int res = sc.ExecuteNonQuery();
                Console.WriteLine("Table created successfully");
            }
            catch (SqlException e)
            {
                Console.WriteLine("Error: " + e.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // Method to insert data
        public void InsertData()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();

                // Taking input from user
                Console.Write("Enter username: ");
                string username = Console.ReadLine();
                Console.Write("Enter password: ");
                string password = Console.ReadLine();
                Console.Write("Re-enter password: ");
                string repassword = Console.ReadLine();
                if (password != repassword)
                {
                    Console.WriteLine("Password and re-entered password do not match");
                    return;
                }
                Console.Write("Enter gender: ");
                string gender = Console.ReadLine();
                Console.Write("Enter course: ");
                string course = Console.ReadLine();
                Console.Write("Enter country: ");
                string country = Console.ReadLine();

                // Inserting data into table
                string insertQuery = "INSERT INTO tbl_registration(username, password, repassword, gender, course, country)" +
                    "VALUES(@username, @password, @repassword, @gender, @course, @country)";
                SqlCommand sc = new SqlCommand(insertQuery, conn);
                sc.Parameters.AddWithValue("@username", username);
                sc.Parameters.AddWithValue("@password", password);
                sc.Parameters.AddWithValue("@repassword", repassword);
                sc.Parameters.AddWithValue("@gender", gender);
                sc.Parameters.AddWithValue("@course", course);
                sc.Parameters.AddWithValue("@country", country);
                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    Console.WriteLine("Data inserted successfully");
                }
                else
                {
                    Console.WriteLine("Data not inserted");
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // Method to display data
        public void DisplayData()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();
                string selectQuery = "SELECT * FROM tbl_registration";
                SqlCommand sc = new SqlCommand(selectQuery, conn);
                SqlDataReader res = sc.ExecuteReader();

                Console.WriteLine("Data from table:");
                while (res.Read())
                {
                    Console.WriteLine("Id: " + res["id"]);
                    Console.WriteLine("Username: " + res["username"]);
                    Console.WriteLine("Password: " + res["password"]);
                    Console.WriteLine("Repassword: " + res["repassword"]);
                    Console.WriteLine("Gender: " + res["gender"]);
                    Console.WriteLine("Course: " + res["course"]);
                    Console.WriteLine("Country: " + res["country"]);
                    Console.WriteLine();
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // Method to update username and course of a person according to given id of user
        public void UpdateData()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();

                Console.Write("Enter id of user to update: ");
                int id = Convert.ToInt32(Console.ReadLine());
                Console.Write("Enter new username: ");
                string username = Console.ReadLine();
                Console.Write("Enter new course: ");
                string course = Console.ReadLine();

                string updateQuery = "UPDATE tbl_registration SET username = @username, course = @course WHERE id = @id";
                SqlCommand sc = new SqlCommand(updateQuery, conn);
                sc.Parameters.AddWithValue("@username", username);
                sc.Parameters.AddWithValue("@course", course);
                sc.Parameters.AddWithValue("@id", id);

                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    Console.WriteLine("Record updated successfully");
                }
                else
                {
                    Console.WriteLine("Record not found");
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // delete record using id of user
        public void DeleteData()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();

                Console.Write("Enter id of user to delete: ");
                int id = Convert.ToInt32(Console.ReadLine());

                string deleteQuery = "DELETE FROM tbl_registration WHERE id = @id";
                SqlCommand sc = new SqlCommand(deleteQuery, conn);
                sc.Parameters.AddWithValue("@id", id);

                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    Console.WriteLine("Record deleted successfully");
                }
                else
                {
                    Console.WriteLine("Record not found");
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                conn.Close();
            }
        }

        // display all records of person who are male from country Nepal
        public void DisplayMaleFromNepal()
        {
            SqlConnection conn = CreateConnection();
            try
            {
                conn.Open();
                string selectQuery = "SELECT * FROM tbl_registration" +
                    "WHERE gender=male AND country=Nepal";
                SqlCommand sc = new SqlCommand(selectQuery, conn);
                SqlDataReader res = sc.ExecuteReader();
                while (res.Read())
                {
                    Console.WriteLine("Id: " + res["id"]);
                    Console.WriteLine("Username: " + res["username"]);
                    Console.WriteLine("Password: " + res["password"]);
                    Console.WriteLine("Repassword: " + res["repassword"]);
                    Console.WriteLine("Gender: " + res["gender"]);
                    Console.WriteLine("Course: " + res["course"]);
                    Console.WriteLine("Country: " + res["country"]);
                }
            }
            catch (SqlException e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                conn.Close();
            }
        }
    }
}
