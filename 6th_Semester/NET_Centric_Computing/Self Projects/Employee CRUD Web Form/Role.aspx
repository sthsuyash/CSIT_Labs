<%@ Page Title="Add Role" MasterPageFile="~/Site.Master" Language="C#" AutoEventWireup="true" CodeBehind="Role.aspx.cs" Inherits="Employee_CRUD_Web_Form.Role" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
    <main>
        <div class="container">
            <h2>Add Role</h2>
            <div class="row">
                <div class="col-md-6">
                    <!-- Role Name -->
                    <div class="form-group">
                        <label for="role_name">Role Name:</label>
                        <asp:TextBox ID="role_name" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
                <div class="col-md-6">
                    <!-- Salary -->
                    <div class="form-group">
                        <label for="salary">Salary:</label>
                        <asp:TextBox ID="salary" CssClass="form-control" runat="server"></asp:TextBox>
                    </div>
                </div>
            </div>
            <div class="form-group">
                <!-- Job Description -->
                <label for="job_description">Job Description:</label>
                <asp:TextBox ID="job_description" CssClass="form-control" runat="server" TextMode="MultiLine" Rows="4"></asp:TextBox>
            </div>
            <br />
            <!-- Button to Add Role -->
            <div class="form-group">
                <asp:Button ID="addRoleButton" CssClass="btn btn-primary" Text="Add Role" runat="server" OnClick="AddRole_Click" />
            </div>
            <!-- Label to display the result -->
            <asp:Label ID="result" runat="server"></asp:Label>
        </div>
    </main>
</asp:Content>
