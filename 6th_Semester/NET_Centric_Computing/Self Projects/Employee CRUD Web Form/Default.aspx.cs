using System;
using System.Data;
using System.Data.SqlClient;
using System.Web.UI.WebControls;

namespace Employee_CRUD_Web_Form
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Load employee data when the page is first loaded
                BindEmployeeData();
            }
        }

        private SqlConnection ConnectToDatabase()
        {
            string connectionString = "Data Source=KSUYASH;Initial Catalog=EmployeeDB;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            return conn;
        }

        protected void BindEmployeeData()
        {
            SqlConnection conn = ConnectToDatabase();
            try
            {
                conn.Open();
                string query = @"SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName 
                                FROM Employee e 
                                INNER JOIN Department d ON e.DepartmentID = d.DepartmentID";
                SqlCommand cmd = new SqlCommand(query, conn);
                SqlDataAdapter adapter = new SqlDataAdapter(cmd);
                DataTable dt = new DataTable();
                adapter.Fill(dt);

                // Bind the DataTable to the GridView
                employeeGridView.DataSource = dt;
                employeeGridView.DataBind();
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

        protected void employeeGridView_RowEditing(object sender, GridViewEditEventArgs e)
        {
            // Set the gridview edit index
            employeeGridView.EditIndex = e.NewEditIndex;
            // Rebind the gridview to show the editing interface
            BindEmployeeData();
        }

        protected void employeeGridView_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            // Cancel editing mode
            employeeGridView.EditIndex = -1;
            // Rebind the gridview to show the original data
            BindEmployeeData();
        }

        protected void employeeGridView_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            // Get the row being edited
            GridViewRow row = employeeGridView.Rows[e.RowIndex];
            // Retrieve updated values
            string firstName = (row.FindControl("txtFirstName") as TextBox).Text;
            string lastName = (row.FindControl("txtLastName") as TextBox).Text;
            // You can retrieve other updated values in a similar manner

            // Perform update operation within a transaction
            SqlConnection conn = ConnectToDatabase();
            SqlTransaction transaction = null;
            try
            {
                conn.Open();
                transaction = conn.BeginTransaction();

                // Assuming EmployeeID is bound to the gridview (you might need to add it to the gridview)
                int employeeID = Convert.ToInt32(employeeGridView.DataKeys[e.RowIndex].Value);
                string query = @"UPDATE Employee 
                                 SET FirstName = @FirstName, LastName = @LastName
                                 WHERE EmployeeID = @EmployeeID";
                SqlCommand cmd = new SqlCommand(query, conn, transaction);
                cmd.Parameters.AddWithValue("@FirstName", firstName);
                cmd.Parameters.AddWithValue("@LastName", lastName);
                cmd.Parameters.AddWithValue("@EmployeeID", employeeID);
                cmd.ExecuteNonQuery();

                // Commit the transaction
                transaction.Commit();

                // Exit edit mode after successful update
                employeeGridView.EditIndex = -1;
                // Rebind the gridview with updated data
                BindEmployeeData();
            }
            catch (SqlException ex)
            {
                // Rollback the transaction if an error occurs
                if (transaction != null)
                {
                    transaction.Rollback();
                }
                // Handle exception
            }
            finally
            {
                conn.Close();
            }
        }

        protected void employeeGridView_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            // Get the employee ID to be deleted
            int employeeID = Convert.ToInt32(employeeGridView.DataKeys[e.RowIndex].Value);

            // Perform delete operation within a transaction
            SqlConnection conn = ConnectToDatabase();
            SqlTransaction transaction = null;
            try
            {
                conn.Open();
                transaction = conn.BeginTransaction();

                string query = "DELETE FROM Employee WHERE EmployeeID = @EmployeeID";
                SqlCommand cmd = new SqlCommand(query, conn, transaction);
                cmd.Parameters.AddWithValue("@EmployeeID", employeeID);
                cmd.ExecuteNonQuery();

                transaction.Commit();
                // Rebind the gridview with updated data after deletion
                BindEmployeeData();
            }
            catch (SqlException error)
            {
                transaction?.Rollback();
                result.Text = "Error: " + error.Message;
            }
            finally
            {
                conn.Close();
            }
        }

        protected void employeeGridView_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            // Hide the DepartmentName column during edit mode
            if (e.Row.RowType == DataControlRowType.DataRow && employeeGridView.EditIndex == e.Row.RowIndex)
            {
                e.Row.Cells[3].Visible = false;
            }
        }
    }
}
