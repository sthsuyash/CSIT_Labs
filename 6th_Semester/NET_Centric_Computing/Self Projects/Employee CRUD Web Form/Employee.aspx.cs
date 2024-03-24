using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Web.UI.WebControls;

namespace Employee_CRUD_Web_Form
{
    public partial class Employee : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                BindDepartments();
                BindRoles();
            }
        }

        private SqlConnection ConnectToDatabase()
        {
            string connectionString = "Data Source=KSUYASH;Initial Catalog=EmployeeDB;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            return conn;
        }

        protected void BindDepartments()
        {
            SqlConnection conn = ConnectToDatabase();
            try
            {
                conn.Open();
                string query = "SELECT DepartmentID, DepartmentName FROM Department";
                SqlCommand cmd = new SqlCommand(query, conn);
                SqlDataReader reader = cmd.ExecuteReader();

                // Clear existing items
                department.Items.Clear();

                while (reader.Read())
                {
                    ListItem item = new ListItem();
                    item.Text = reader["DepartmentName"].ToString();
                    item.Value = reader["DepartmentID"].ToString();
                    department.Items.Add(item);
                }
            }
            catch (SqlException error)
            {
                result.Text = "Error: " + error.Message;
            }
            finally
            {
                conn.Close();
            }
        }

        protected void BindRoles()
        {
            SqlConnection conn = ConnectToDatabase();
            try
            {
                conn.Open();
                string query = "SELECT RoleID, RoleName FROM Role";
                SqlCommand cmd = new SqlCommand(query, conn);
                SqlDataReader reader = cmd.ExecuteReader();

                // Clear existing items
                employee_roles.Items.Clear();

                while (reader.Read())
                {
                    ListItem item = new ListItem();
                    item.Text = reader["RoleName"].ToString();
                    item.Value = reader["RoleID"].ToString();
                    employee_roles.Items.Add(item);
                }
            }
            catch (SqlException error)
            {
                result.Text = "Error: " + error.Message;
            }
            finally
            {
                conn.Close();
            }
        }

        protected void AddEmployee_Click(object sender, EventArgs e)
        {
            // Retrieve employee data
            string firstName = first_name.Text;
            string lastName = last_name.Text;
            DateTime dob = dob_calendar.SelectedDate;
            string genderValue = gender.SelectedValue;
            string emailValue = email.Text;
            string phoneNumber = phone.Text;
            string addressValue = address.Text;
            int departmentID = Convert.ToInt32(department.SelectedValue);

            // Retrieve selected roles
            List<int> selectedRoles = new List<int>();
            foreach (ListItem item in employee_roles.Items)
            {
                if (item.Selected)
                {
                    selectedRoles.Add(Convert.ToInt32(item.Value));
                }
            }

            // Perform database operations to add employee and roles
            SqlConnection conn = ConnectToDatabase();
            SqlTransaction transaction = null;
            try
            {
                conn.Open();
                transaction = conn.BeginTransaction();

                // Insert employee
                string employeeQuery = "INSERT INTO Employee (FirstName, LastName, DateOfBirth, Gender, Email, PhoneNumber, Address, DepartmentID) " +
                                       "VALUES (@FirstName, @LastName, @DateOfBirth, @Gender, @Email, @PhoneNumber, @Address, @DepartmentID); " +
                                       "SELECT SCOPE_IDENTITY();";
                SqlCommand employeeCmd = new SqlCommand(employeeQuery, conn, transaction);
                employeeCmd.Parameters.AddWithValue("@FirstName", firstName);
                employeeCmd.Parameters.AddWithValue("@LastName", lastName);
                employeeCmd.Parameters.AddWithValue("@DateOfBirth", dob);
                employeeCmd.Parameters.AddWithValue("@Gender", genderValue);
                employeeCmd.Parameters.AddWithValue("@Email", emailValue);
                employeeCmd.Parameters.AddWithValue("@PhoneNumber", phoneNumber);
                employeeCmd.Parameters.AddWithValue("@Address", addressValue);
                employeeCmd.Parameters.AddWithValue("@DepartmentID", departmentID);
                int employeeID = Convert.ToInt32(employeeCmd.ExecuteScalar());

                // Insert employee roles
                foreach (int roleId in selectedRoles)
                {
                    string employeeRoleQuery = "INSERT INTO EmployeeRole (EmployeeID, RoleID, StartDate, EndDate) " +
                                               "VALUES (@EmployeeID, @RoleID, @StartDate, @EndDate)";
                    SqlCommand employeeRoleCmd = new SqlCommand(employeeRoleQuery, conn, transaction);
                    employeeRoleCmd.Parameters.AddWithValue("@EmployeeID", employeeID);
                    employeeRoleCmd.Parameters.AddWithValue("@RoleID", roleId);
                    employeeRoleCmd.Parameters.AddWithValue("@StartDate", DateTime.Now);
                    employeeRoleCmd.Parameters.AddWithValue("@EndDate", DBNull.Value); // Assuming no end date for now
                    employeeRoleCmd.ExecuteNonQuery();
                }

                // Commit the transaction
                transaction.Commit();
                result.Text = "Employee added successfully!";
            }
            catch (SqlException ex)
            {
                // Rollback the transaction if an exception occurs
                transaction?.Rollback();
                result.Text = "Error adding employee: " + ex.Message;
            }
            finally
            {
                conn.Close();
                // Reset form fields
                first_name.Text = "";
                last_name.Text = "";
                dob_calendar.SelectedDate = DateTime.Today;
                gender.SelectedIndex = 0;
                email.Text = "";
                phone.Text = "";
                address.Text = "";
                department.SelectedIndex = 0;
                // Clear selected roles
                foreach (ListItem item in employee_roles.Items)
                {
                    item.Selected = false;
                }
            }
        }
    }
}
