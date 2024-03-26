<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Operation.aspx.cs" Inherits="NumberOperationsWebApp.Operation" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="operationsForm" runat="server">
        <!-- first number -->
        <div>
            <asp:Label ID="firstNumberLabel" Text="Enter first number" runat="server"></asp:Label>
            <asp:TextBox ID="firstNumber" runat="server"></asp:TextBox>
        </div>

        <!-- second number -->
        <div>
            <asp:Label ID="secondNumberLabel" Text="Enter second number" runat="server"></asp:Label>
            <asp:TextBox ID="secondNumber" runat="server"></asp:TextBox>
        </div>

        <!-- output -->
        <div>
            <asp:TextBox ID="output" runat="server"></asp:TextBox>
        </div>

        <!-- buttons -->
        <div>
            <asp:Button ID="addButton" Text="Add" runat="server" OnClick="addButton_Click" />
            <asp:Button ID="subtractButton" Text="Subtract" runat="server" OnClick="subtractButton_Click" />
            <asp:Button ID="primeButton" Text="Find Prime" runat="server" OnClick="primeButton_Click" />
        </div>

    </form>
</body>
</html>
