<%@ Page Title="Employee Management System || Home" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Employee_CRUD_Web_Form._Default" %>

<asp:Content ID="BodyContent" ContentPlaceHolderID="MainContent" runat="server">
  <main>
    <div class="container">
      <h2>Employee List</h2>
      <asp:GridView
        ID="employeeGridView"
        runat="server"
        AutoGenerateColumns="False"
      >
        <Columns>
          <asp:BoundField DataField="FirstName" HeaderText="First Name" />
          <asp:BoundField DataField="LastName" HeaderText="Last Name" />
          <asp:BoundField DataField="DepartmentName" HeaderText="Department" />
          <asp:TemplateField HeaderText="Actions">
            <ItemTemplate>
              <asp:Button
                ID="btnView"
                runat="server"
                Text="View"
                CommandName="View"
                CommandArgument='<%# Eval("EmployeeID") %>'
              />
              <asp:Button
                ID="btnEdit"
                runat="server"
                Text="Edit"
                CommandName="Edit"
                CommandArgument='<%# Eval("EmployeeID") %>'
              />
              <asp:Button
                ID="btnDelete"
                runat="server"
                Text="Delete"
                CommandName="Delete"
                CommandArgument='<%# Eval("EmployeeID") %>'
              />
            </ItemTemplate>
          </asp:TemplateField>
        </Columns>
      </asp:GridView>
    </div>
    <div>
      <asp:Label ID="result" runat="server"></asp:Label>
    </div>
  </main>
</asp:Content>
