<%@ Page Title="Add Employee" MasterPageFile="~/Site.Master" Language="C#" AutoEventWireup="true" CodeBehind="Employee.aspx.cs" Inherits="Employee_CRUD_Web_Form.Employee" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
  <main>
    <div class="container">
      <h2>Add Employee</h2>
      <div>
        <div>
          <!-- First Name -->
          <div>
            <label for="first_name">First Name:</label>
            <asp:TextBox ID="first_name" runat="server"></asp:TextBox>
          </div>
        </div>
        <div>
          <!-- Last Name -->
          <div>
            <label for="last_name">Last Name:</label>
            <asp:TextBox ID="last_name" runat="server"></asp:TextBox>
          </div>
        </div>
      </div>
      <div>
        <div>
          <!-- Date of Birth -->
          <div>
            <label for="dob">Date of Birth:</label>
            <asp:Calendar ID="dob_calendar" runat="server"></asp:Calendar>
          </div>
        </div>
        <div>
          <!-- Gender -->
          <div>
            <label for="gender">Gender:</label>
            <asp:DropDownList ID="gender" runat="server">
              <asp:ListItem Text="Male" Value="M"></asp:ListItem>
              <asp:ListItem Text="Female" Value="F"></asp:ListItem>
            </asp:DropDownList>
          </div>
        </div>
      </div>
      <div>
        <div>
          <!-- Email -->
          <div>
            <label for="email">Email:</label>
            <asp:TextBox ID="email" runat="server"></asp:TextBox>
          </div>
        </div>
        <div>
          <!-- Phone Number -->
          <div>
            <label for="phone">Phone Number:</label>
            <asp:TextBox ID="phone" runat="server"></asp:TextBox>
          </div>
        </div>
      </div>
      <div>
        <div>
          <!-- Address -->
          <div>
            <label for="address">Address:</label>
            <asp:TextBox ID="address" runat="server"></asp:TextBox>
          </div>
        </div>
        <div>
          <!-- Department -->
          <div>
            <label for="department">Department:</label>
            <asp:DropDownList ID="department" runat="server">
            </asp:DropDownList>
          </div>
        </div>
      </div>
      <div>
        <!-- Employee Roles -->
        <label for="employee_roles">Employee Roles:</label>
        <asp:ListBox
          ID="employee_roles"
          SelectionMode="Multiple"
          runat="server"
        ></asp:ListBox>
      </div>
      <!-- Button to Add Employee -->
      <br />
      <div>
        <asp:Button ID="addEmployeeButton" Text="Add Employee"
        runat="server" OnClick="AddEmployee_Click" />
      </div>
      <br />
      <!-- Label to display the result -->
      <asp:Label ID="result" runat="server"></asp:Label>
    </div>
  </main>
</asp:Content>
