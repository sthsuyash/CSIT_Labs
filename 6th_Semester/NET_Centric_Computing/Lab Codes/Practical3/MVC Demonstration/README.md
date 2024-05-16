# MVC demonstration

This is a simple project ot demonstrate model, view and controller by showing different action methods, views, models, accessing controllers, model and view.

## Steps to create MVC project

1. Create a new project in Visual Studio.
2. Select ASP.NET Core Web Application.
3. Select MVC template.
4. Click on Create.
5. Add a new controller.
6. Add a new model.
7. Add a new view.
8. Run the project.

## Controllers

Controllers are responsible for controlling the flow of the application execution. It responds to the user input and performs interactions on the data model objects. The controller receives input, optionally validates it and then passes the input to the model.

We can add a new controller by right clicking on the Controllers folder and selecting Add -> Controller.

## Models

Models are responsible for managing the data of the application. It responds to the request from the view and it also responds to instructions from the controller to update itself. Models are used to pass the data between controller and view. It can also have the logic to update the controller if its data changes.

We can add a new model by right clicking on the Models folder and selecting Add -> Class.

Example:

```c#
public class Student
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Email { get; set; }
    public string Address { get; set; }
}
```

## Views

Views are responsible for displaying the data provided by the controller in a particular format. It is the user interface of the application. It displays the data provided by the model in a particular format. It can be a web page, XML or any other format.

We can add a new view by right clicking on the Views folder and selecting Add -> View.

Every controller file has a corresponding view file in the Views folder and every view file has a corresponding controller file in the Controllers folder.

Example:

- Controller:

  ```c#
  public class HomeController : Controller
  {
      public IActionResult Index()
      {
          return View();
      }
  }
  ```

- View:

  ```html
  @{ ViewData["Title"] = "Home Page"; }

  <h1>@ViewData["Title"]</h1>
  <p>Welcome to the home page.</p>
  ```

Now, let's say we have another action method in the HomeController:

- About action method in HomeController:

```c#
public class HomeController : Controller
{
    public IActionResult About()
    {
        ViewData["Message"] = "Your application description page.";
        return View();
    }
}
```

We can add a new view for this action method by right clicking on the About action method and selecting Add View.

```html
@{ ViewData["Title"] = "About"; }

<h2>@ViewData["Title"]</h2>
<h3>@ViewData["Message"]</h3>
```
