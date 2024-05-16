# HTML Tag Helpers

- Tag Helpers in ASP.NET Core allow server-side code to participate in creating and rendering HTML elements in Razor files.
- They provide a more HTML-friendly development experience and reduce the explicit transitions between HTML and C# in Razor views.

_Note_: The source code for this practical can be found **[here](../MVC%20Demonstration/Views/Home/Index.cshtml)**.

## What are Tag Helpers?

- Tag Helpers enable to create and manipulate HTML elements using server-side code.
- They are authored in C# and target HTML elements based on element name, attribute name or parent tag.
- Unlike HTML Helpers, Tag Helpers don’t replace them; they complement each other.
- Tag Helpers are not supported in Razor components.

## What Tag Helpers Provide

- **HTML-Friendly Markup:**
  Razor markup with Tag Helpers looks like standard HTML, making it accessible to front-end designers familiar with HTML/CSS/JavaScript.
- **Rich IntelliSense:**
  Developers, even those experienced with Razor C# syntax, find Tag Helpers more productive than writing C# Razor markup.
- **Robust, Reliable, and Maintainable Code:**
  Tag Helpers can handle tasks like appending version numbers to image names automatically.

- Example:

  Let’s say we want to create a form with an input field for a user’s name.
  In the Razor view, we can use the InputTagHelper as follows:
  HTML

  ```html
  <form method="post">
    <label asp-for="UserName">Enter your name:</label>
    <input asp-for="UserName" />
    <button type="submit">Submit</button>
  </form>
  ```

  This code will render the following HTML:

  ```html
  <form method="post">
    <label for="UserName">Enter your name:</label>
    <input type="text" id="UserName" name="UserName" />
    <button type="submit">Submit</button>
  </form>
  ```

  In the associated C# model:

  ```C#
  public class MyModel
  {
      public string UserName { get; set; }
  }
  ```

- The `asp-for` attribute extracts the model property name (UserName) into the rendered HTML.
- Tag Helpers enhance the development experience by bridging the gap between server-side code and HTML, making the code more maintainable and efficient.

- If we want the type of input to be email, i can do this:

  ```html
  <input asp-for="email" type="email" />
  ```

  So, this will render the following HTML:

  ```html
  <input type="email" id="email" name="email" />
  ```
