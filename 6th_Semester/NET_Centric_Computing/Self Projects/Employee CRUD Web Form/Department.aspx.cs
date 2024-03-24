using System;
using System.Data.SqlClient;
using System.Web.UI.WebControls;

namespace Employee_CRUD_Web_Form
{
    public partial class Department : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Bind the dropdown list with the department manager on initial page load
                BindDepartmentManagers();
            }
        }

        private SqlConnection ConnectToDatabase()
        {
            string connectionString = "Data Source=KSUYASH;Initial Catalog=EmployeeDB;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            return conn;
        }

        protected void BindDepartmentManagers()
        {
            SqlConnection conn = ConnectToDatabase();
            try
            {
                conn.Open();
                string query = "SELECT EmployeeID, FirstName + ' ' + LastName AS FullName FROM Employee";
                SqlCommand sc = new SqlCommand(query, conn);
                SqlDataReader reader = sc.ExecuteReader();

                // Clear existing items
                department_manager.Items.Clear();

                while (reader.Read())
                {
                    ListItem item = new ListItem();
                    item.Text = reader["FullName"].ToString();
                    item.Value = reader["EmployeeID"].ToString();
                    department_manager.Items.Add(item);
                }

                // Add a default "Select Manager" option
                department_manager.Items.Insert(0, new ListItem("Select Manager", "0"));
            }
            catch (SqlException error)
            {
                result.Text = error.Message;
            }
            finally
            {
                conn.Close();
            }
        }

        protected void AddDepartment_Click(object sender, EventArgs e)
        {
            string dept_name = department_name.Text;
            string dept_location = department_location.Text;
            string dept_manager_id = department_manager.SelectedValue;

            SqlConnection conn = ConnectToDatabase();
            SqlTransaction sqlTransaction = null;
            try
            {
                conn.Open();
                // start a transaction
                sqlTransaction = conn.BeginTransaction();

                // check if the department name already exists in the specified location
                String query = "SELECT COUNT(*) FROM Department WHERE DepartmentName=@DepartmentName AND Location=@Location";
                SqlCommand sc = new SqlCommand(query, conn, sqlTransaction);
                sc.Parameters.AddWithValue("@DepartmentName", dept_name);
                sc.Parameters.AddWithValue("@Location", dept_location);
                int departmentCount = Convert.ToInt32(sc.ExecuteScalar());
                if (departmentCount > 0)
                {
                    result.Text = "Department already exists in the specified location!";
                    return;
                }

                // first insert into the Department table
                query = "INSERT INTO Department " +
                    "(DepartmentName, Location) VALUES " +
                    "(@DepartmentName, @Location)";
                SqlCommand insertSc = new SqlCommand(query, conn, sqlTransaction);
                insertSc.Parameters.AddWithValue("@DepartmentName", dept_name);
                insertSc.Parameters.AddWithValue("@Location", dept_location);
                int dept_id = Convert.ToInt32(insertSc.ExecuteScalar());

                // insert into the DepartmentManager table
                query = "INSERT INTO DepartmentManager " +
                    "(DepartmentID, ManagerID) VALUES " +
                    "(@DepartmentID, @ManagerID)";
                SqlCommand managerSc = new SqlCommand(query, conn, sqlTransaction);
                managerSc.Parameters.AddWithValue("@DepartmentID", dept_id);
                managerSc.Parameters.AddWithValue("@ManagerID", dept_manager_id);
                managerSc.ExecuteNonQuery();

                // commit the transaction if everything was successful
                sqlTransaction.Commit();
                result.Text = "Department added successfully!";
            }
            catch (SqlException error)
            {
                // rollback the transaction if there is an error
                if (sqlTransaction != null)
                {
                    sqlTransaction.Rollback();
                }
                result.Text = error.Message;
            }
            finally
            {
                conn.Close();
                // reset the form
                department_name.Text = "";
                department_location.Text = "";
                department_manager.SelectedIndex = 0;
            }
        }
    }
}
