using System;
using System.Data.SqlClient;

namespace Employee_CRUD_Web_Form
{
    public partial class Role : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e){ }

        private SqlConnection ConnectToDatabase()
        {
            string connectionString = "Data Source=KSUYASH;Initial Catalog=EmployeeDB;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            return conn;
        }

        protected void AddRole_Click(object sender, EventArgs e)
        {
            // Retrieve role data
            string roleName = role_name.Text;
            decimal roleSalary = Convert.ToDecimal(salary.Text);
            string jobDescription = job_description.Text;

            // Perform database operations to add role
            SqlConnection conn = ConnectToDatabase();
            try
            {
                conn.Open();
                string query = "INSERT INTO Role (RoleName, Salary, JobDescription) " +
                               "VALUES (@RoleName, @Salary, @JobDescription)";
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.AddWithValue("@RoleName", roleName);
                cmd.Parameters.AddWithValue("@Salary", roleSalary);
                cmd.Parameters.AddWithValue("@JobDescription", jobDescription);
                int rowsAffected = cmd.ExecuteNonQuery();
                if (rowsAffected > 0)
                {
                    result.Text = "Role added successfully!";
                }
                else
                {
                    result.Text = "Failed to add role!";
                }
            }
            catch (SqlException error)
            {
                result.Text = "Error: " + error.Message;
            }
            finally
            {
                conn.Close();
                // Reset the form
                role_name.Text = "";
                salary.Text = "";
                job_description.Text = "";
            }
        }
    }
}
