# Authentication and Authorization in ASP.NET

- Authentication is the process of verifying the identity of a user.
- Authorization is the process of verifying that the user has the necessary permissions to access the resources.
- We need to be Authenticated to access Authorization
- We can have cookies and session authentication.

In program.cs:

```c#
// to add cookie authentication
using Microsoft.AspNetCore.Authentication.Cookies; 

// adding authentication through cookie
builder.Services.AddAuthentication(CookieAuthenticationDefaults.AuthenticationScheme)
```
