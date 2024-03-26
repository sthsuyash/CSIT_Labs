using System;
using System.Data.SqlClient;

namespace RegistrationForm
{
    public partial class Registration : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        { }

        protected void SignUp(object sender, EventArgs e)
        {
            String usernameValue = username.Text;
            String passwordValue = password.Text;
            String rePasswordValue = rePassword.Text;

            // check if username and password are empty
            if (usernameValue == "" || passwordValue == "" || rePasswordValue == "")
            {
                result.Text = "Please fill all the fields";
                return;
            }

            // check if the password and confirm password are same
            if (passwordValue != rePasswordValue)
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
            // if none of the courses are selected, return an error
            if (!c.Checked && !cpp.Checked && !java.Checked)
            {
                result.Text = "Please select a course";
                return;
            }

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
            string countryValue;
            if (country.SelectedValue != "")
            {
                countryValue = country.SelectedValue;
            }
            else
            {
                result.Text = "Please select a country";
                return;
            }

            string connectionString = "Data Source=KSUYASH;Initial Catalog=UserRegistrationPractical;Integrated Security=True";
            SqlConnection conn = new SqlConnection(connectionString);
            try
            {
                conn.Open();
                string query = "INSERT INTO tbl_registration (username, password, repassword, gender, course, country) VALUES (" +
                    "@username, @password, @repassword, @gender, @courses, @country)";
                SqlCommand sc = new SqlCommand(query, conn);
                sc.Parameters.AddWithValue("@username", usernameValue);
                sc.Parameters.AddWithValue("@password", passwordValue);
                sc.Parameters.AddWithValue("@repassword", rePasswordValue);
                sc.Parameters.AddWithValue("@gender", gender);
                sc.Parameters.AddWithValue("@courses", courses);
                sc.Parameters.AddWithValue("@country", countryValue);

                int res = sc.ExecuteNonQuery();
                // reset the form
                username.Text = "";
                password.Text = "";
                rePassword.Text = "";
                // deselect the radio buttons
                male.Checked = false;
                female.Checked = false;
                // deselect the checkboxes
                c.Checked = false;
                cpp.Checked = false;
                java.Checked = false;
                // deselect the dropdown
                country.SelectedIndex = 0;


                if (res > 0)
                {
                    result.Text = "Registration successful";
                }
                else
                {
                    result.Text = "Registration failed";
                }
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
    }
}
