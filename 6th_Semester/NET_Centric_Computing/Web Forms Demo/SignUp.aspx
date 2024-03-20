<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="SignUp.aspx.cs" Inherits="Web_Forms_Demo.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>SignUp form</title>
</head>
<body>
    <form id="signupForm" runat="server">
        <!-- Username text field -->
        <div>
            <asp:Label ID="usernameLabel" Text="Username" runat="server"></asp:Label>
            <asp:TextBox ID="username" runat="server"></asp:TextBox>
        </div>

        <!-- Password text field -->
        <div>
            <asp:Label ID="passwordLabel" Text="Password" runat="server"></asp:Label>
            <asp:TextBox ID="password" runat="server"></asp:TextBox>
        </div>

        <!-- Confirm Password text field -->
        <div>
            <asp:Label ID="confirmPasswordLabel" Text="Confirm Password" runat="server">
                <asp:TextBox ID="confirmPassword" runat="server"></asp:TextBox>
            </asp:Label>
        </div>

        <!-- Gender radio button field -->
        <div>
            <asp:Label ID="genderLabel" Text="Gender" runat="server"></asp:Label>
            <div>
                <asp:RadioButton ID="male" runat="server" Text="Male" GroupName="Gender" />
                <asp:RadioButton ID="female" runat="server" Text="Female" GroupName="Gender" />
            </div>
        </div>

        <!-- Courses checkbox field -->
        <div>
            <asp:Label ID="courses" Text="Courses" runat="server"></asp:Label>
            <asp:CheckBox ID="c" Text="C" runat="server" />
            <asp:CheckBox ID="cpp" Text="C++" runat="server" />
            <asp:CheckBox ID="java" Text="Java" runat="server" />
        </div>

        <!-- Country dropdown field -->
        <div>
            <asp:Label ID="countryLabel" Text="Country" runat="server"></asp:Label>
            <asp:DropDownList ID="country" runat="server">
                <asp:ListItem Value="">Select your country</asp:ListItem>
                <asp:ListItem>Nepal</asp:ListItem>
                <asp:ListItem>India</asp:ListItem>
                <asp:ListItem>USA</asp:ListItem>
                <asp:ListItem>UK</asp:ListItem>
            </asp:DropDownList>
        </div>

        <!-- Submit button -->
        <div>
            <asp:Button ID="submit" Text="Submit" runat="server" OnClick="SignUp" />
        </div>

        <!-- Result content -->
        <div>
            <asp:TextBox ID="result" runat="server"></asp:TextBox>
        </div>
    </form>
</body>
</html>
