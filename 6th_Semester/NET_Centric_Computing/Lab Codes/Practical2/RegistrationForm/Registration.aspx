<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Registration.aspx.cs" Inherits="RegistrationForm.Registration" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Registration Form</title>
</head>
<body>
    <form id="registrationForm" runat="server">
        <!-- Username -->
        <div>
            <asp:Label ID="usernameLabel" runat="server" Text="Username"></asp:Label>
            <asp:TextBox ID="username" runat="server"></asp:TextBox>
        </div>

        <!-- Password -->
        <div>
            <asp:Label ID="passwordLabel" runat="server" Text="Password"></asp:Label>
            <asp:TextBox ID="password" runat="server" TextMode="Password"></asp:TextBox>
        </div>

        <!-- Re-password -->
        <div>
            <asp:Label ID="rePasswordLabel" runat="server" Text="Re-Password"></asp:Label>
            <asp:TextBox ID="rePassword" runat="server" TextMode="Password"></asp:TextBox>
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
