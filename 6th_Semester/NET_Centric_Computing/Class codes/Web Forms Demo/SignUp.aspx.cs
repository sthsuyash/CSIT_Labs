using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Web_Forms_Demo
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e) { }

        protected void SignUp(object sender, EventArgs e)
        {
            String usernameValue = username.Text;
            String passwordValue = password.Text;
            String confirmPasswordValue = confirmPassword.Text;

            // check if the password and confirm password are same
            if (passwordValue != confirmPasswordValue)
            {
                result.Text = "Passwords do not match";
                return;
            }

            // check if the gender is selected
            string gender; // it is a radio button so we need to check which one is selected
            if (male.Checked)
            {
                gender = male.Text;
            }
            else if (female.Checked)
            {
                gender = female.Text;
            }
            else
            {
                result.Text = "Please select a gender";
                return;
            }

            // select courses
            string courses = "";
            if (c.Checked)
            {
                courses += c.Text + ", ";
            }
            if (cpp.Checked)
            {
                courses += cpp.Text + ", ";
            }
            if (java.Checked)
            {
                courses += java.Text + ", ";
            }

            // check if the country is chosen
            string countryValue = "";
            if (country.SelectedValue != "")
            {
                countryValue = country.SelectedValue;
            }
            else
            {
                result.Text = "Please select a country";
                return;
            }

            try
            {
                string connectionString = "Data Source=KSUYASH;Initial Catalog=db_net;Integrated Security=True";
                SqlConnection conn = new SqlConnection(connectionString);
                conn.Open();

                string query = "INSERT INTO tbl_signup (username, password, gender, courses, country) VALUES (" +
                    "@username, @password, @gender, @courses, @country)";
                SqlCommand sc = new SqlCommand(query, conn);
                sc.Parameters.AddWithValue("@username", usernameValue);
                sc.Parameters.AddWithValue("@password", passwordValue);
                sc.Parameters.AddWithValue("@gender", gender);
                sc.Parameters.AddWithValue("@courses", courses);
                sc.Parameters.AddWithValue("@country", countryValue);

                int res = sc.ExecuteNonQuery();
                if (res > 0)
                {
                    result.Text = "Sign up successful";
                }
                else
                {
                    result.Text = "Sign up failed";
                }
            }
            catch (SqlException error)
            {
                result.Text = error.Message;
            }
        }
    }
}
