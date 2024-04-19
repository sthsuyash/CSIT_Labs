<%@ Page Title="Add Department" MasterPageFile="~/Site.Master" Language="C#" AutoEventWireup="true" CodeBehind="Department.aspx.cs" Inherits="Employee_CRUD_Web_Form.Department" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
  <main>
    <div>
      <h2>Add Department</h2>
      <!-- Department Name -->
      <div>
        <label for="department_name">Department Name:</label>
        <asp:TextBox ID="department_name" runat="server"></asp:TextBox>
      </div>
      <!-- Department Location -->
      <div>
        <label for="department_location">Department Location:</label>
        <asp:TextBox ID="department_location" runat="server"></asp:TextBox>
      </div>
      <!-- Department Manager -->
      <div>
        <label for="department_manager">Department Manager:</label>
        <asp:DropDownList ID="department_manager" runat="server">
        </asp:DropDownList>
      </div>
      <br />
      <!-- Button to Add Department -->
      <div>
        <asp:Button
          ID="addDepartmentButton"
          Text="Add Department"
          runat="server"
          OnClick="AddDepartment_Click"
        />
      </div>
      <!-- Label to display the result -->
      <asp:Label ID="result" runat="server"></asp:Label>
    </div>
  </main>
</asp:Content>
