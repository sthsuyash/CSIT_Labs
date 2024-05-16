# Razor Syntax

- Razor is a markup syntax for embedding .NET-based code into webpages.
- It consists of Razor markup, C# and HTML.
- Razor files have the .cshtml extension.
- Razor syntax is used in ASP.NET Core MVC views.
- Razor syntax is used to create dynamic content in views, ie. server-side code in views.

_Note_: The source code for this practical can be found **[here](../MVC%20Demonstration/Views/Home/Index.cshtml)**.

## Rendering HTML

- The default Razor language is HTML.
- HTML markup in .cshtml Razor files is rendered by the server unchanged.
- For example:

  ```html
  <p>@Username</p>
  ```

- To escape an @ symbol in Razor markup, use a second @ symbol:

  ```html
  <p>@@Username</p>
  ```

## Implicit Razor Expressions

- Implicit expressions start with @ followed by C# code.
- Examples:

  ```html
  <p>@DateTime.Now</p>
  <p>@DateTime.IsLeapYear(2016)</p>
  ```

- Avoid spaces within implicit expressions (except for the await keyword).

## Tag Helpers

- Tag Helpers resemble HTML tags and encapsulate server-side logic.
- Example using the LabelTagHelper:

  ```html
  <label asp-for="UserName">User Name:</label> <input asp-for="UserName" />
  ```
