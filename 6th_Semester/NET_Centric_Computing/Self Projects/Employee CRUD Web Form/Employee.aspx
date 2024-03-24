<%@ Page Title="Add Employee" MasterPageFile="~/Site.Master" Language="C#" AutoEventWireup="true" CodeBehind="Employee.aspx.cs" Inherits="Employee_CRUD_Web_Form.Employee" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <main>
        <div class="container">
            <h2>Add Employee</h2>
            <div class="row">
                <div class="col-md-6">
                    <!-- First Name -->
                    <div class="form-group">
                        <label for="first_name">First Name:</label>
                        <asp:TextBox ID="first_name" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
                <div class="col-md-6">
                    <!-- Last Name -->
                    <div class="form-group">
                        <label for="last_name">Last Name:</label>
                        <asp:TextBox ID="last_name" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-6">
                    <!-- Date of Birth -->
                    <div class="form-group">
                        <label for="dob">Date of Birth:</label>
                        <asp:Calendar ID="dob_calendar" CssClass="form-control" runat="server"></asp:Calendar>
                    </div>
                </div>
                <div class="col-md-6">
                    <!-- Gender -->
                    <div class="form-group">
                        <label for="gender">Gender:</label>
                        <asp:DropDownList ID="gender" CssClass="form-control" runat="server">
                            <asp:ListItem Text="Male" Value="M"></asp:ListItem>
                            <asp:ListItem Text="Female" Value="F"></asp:ListItem>
                        </asp:DropDownList>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-6">
                    <!-- Email -->
                    <div class="form-group">
                        <label for="email">Email:</label>
                        <asp:TextBox ID="email" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
                <div class="col-md-6">
                    <!-- Phone Number -->
                    <div class="form-group">
                        <label for="phone">Phone Number:</label>
                        <asp:TextBox ID="phone" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
            </div>
            <div class="row">
                <div class="col-md-6">
                    <!-- Address -->
                    <div class="form-group">
                        <label for="address">Address:</label>
                        <asp:TextBox ID="address" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
                <div class="col-md-6">
                    <!-- Department -->
                    <div class="form-group">
                        <label for="department">Department:</label>
                        <asp:DropDownList ID="department" CssClass="form-control" runat="server">
                        </asp:DropDownList>
                    </div>
                </div>
            </div>
            <div class="form-group">
                <!-- Employee Roles -->
                <label for="employee_roles">Employee Roles:</label>
                <asp:ListBox ID="employee_roles" CssClass="form-control" SelectionMode="Multiple" runat="server"></asp:ListBox>
            </div>
            <!-- Button to Add Employee -->
            <br />
            <div class="form-group">
                <asp:Button ID="addEmployeeButton" CssClass="btn btn-primary" Text="Add Employee" runat="server" OnClick="AddEmployee_Click" />
            </div>
            <br />
            <!-- Label to display the result -->
            <asp:Label ID="result" runat="server"></asp:Label>
        </div>
    </main>
</asp:Content>
