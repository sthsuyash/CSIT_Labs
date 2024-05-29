# Server Side State Management in ASP.NET

Server-side state management is a technique used to store information about the state of a web page on the server. This information can be accessed and modified by the server-side code, allowing the web application to maintain the state of the page across multiple requests.

HTTP is a stateless protocol. So, HTTP requests are independent messages that don't retain user's values or app states.

State can be managed in the application using server approaches as:

- **Session state**: Session state is used to store information about the user's session on the server. This information is associated with a unique session ID that is sent to the client in a cookie or as part of the URL. Session state can be used to store user-specific information, such as shopping cart items or user preferences.

- **TempData**: TempData is a dictionary object that is used to store data between requests. TempData is used to pass data from one action method to another action method in the same controller or in a different controller. TempData is useful when you want to pass data between actions but don't want to persist the data in the session.

- **HttpContext**: The HttpContext object is used to store information about the current HTTP request and response. The HttpContext object provides access to the request and response objects, as well as other information about the current request, such as the user's IP address and browser type.

## Session State

Session state is an ASP.NET Core mechanism to store user data while the user browses the application. It uses a store maintained by the application to persist data across requests from a client. We should store critical application data in the user's database and we should cache it in a session only as a performance optimization, if required.

ASP.NET Core maintains the session by providing a cookie to the client that contains a session ID. The browser sends back the cookie to the application in each request. The application uses the session ID to fetch the session data.

### Important things to consider while working with Session state

- A session cookie is specific to the browser session.
- When a browser session ends, it deletes the session cookie.
- If the application receives a cookie for an expired session, it creates a new session that uses the same session cookie.
- An application doesnot retain empty session data.
- The application retains a session for a limited time after the last request. The app either sets the session timeout or uses the default value of 20 minutes.
- Session state is ideal for storing user data that are specific to a particular session but doesnot require permanent storage across sessions.
- An application deletes the data stored in session either when we call ISession.Clear or when the session expires.
- There is no default mechanism to inform the application that a client has closed the browser or deleted the session cookie or it is expired.

### Creating Session State using MVC

1. First, we need to configure the `Program.cs` file to use the session state.

   ```csharp
    builder.Services.AddSession();

    // other configurations
    app.UseSession();
   ```

2. Then, let's add a controller for the session state.

   ```csharp
   public class SessionController : Controller
    {
        public IActionResult Index(string Name)
        {
            HttpContext.Session.SetString("Name", Name);
            return View();
        }

        public IActionResult Get()
        {
            string name = HttpContext.Session.GetString("Name");
            ViewBag.Name = name; // Add the name to the ViewBag
            return View();
        }
    }
   ```

3. Finally, let's create the views for the controller.

   - Index.cshtml

     ```html
     <form asp-action="Index" method="post">
       <input type="text" name="Name" />
       <input type="submit" value="Submit" />
     </form>
     ```

   - Get.cshtml

     ```html
     <h1>Welcome, @ViewBag.Name</h1>
     ```

## TempData

- TempData is a dictionary object that is used to store data until it is read.
- It is used to pass data from one action method to another action method in the same controller or in a different controller.
- We can use Keep() and Peek() methods to examine the data without deletion.
- TempData is useful when we require the data for more than a single request.
- We can access them from controllers and views.
- TempData is implemented by TempData providers using either cookies or session state.

### Creating TempData using MVC

1. First, let's add a controller for TempData, for one-time storage.

   ```csharp
    public IActionResult Index()
    {
        TempData["Name"] = "John Doe";
        return View();
    }
   ```

   In this code, we are storing the name "John Doe" in TempData.

   ```csharp
   public IActionResult Second()
   {
       string name = TempData["Name"] ?? null; // Get the name from TempData or null
       ViewBag.Name = name; // Add the name to the ViewBag
       return View();
   }
   ```

   Then, in the second action method, we are retrieving the name from TempData and storing it in the ViewBag.

   ```csharp
   public IActionResult Third()
   {
       string name = TempData["Name"] ?? null;
       ViewBag.Name = name;
       return View();
   }
   ```

   Here, we are retrieving the name from TempData in the third action method. But, since TempData is a one-time storage, the name will be deleted after it is read in the second action method.

2. For persistent storage, we can use the `Keep()` method or `Peek()` method.

- TempData.Keep()/TempData.Keep(string key): Marks the specified key in TempData to be retained for another request. If the key is not specified, all keys are retained.
- TempData.Peek(string key): Returns the value associated with the specified key in TempData without marking the key for deletion.

  - Using `Keep()` method

    ```csharp
    public IActionResult Second()
    {
        string name = TempData["Name"] ?? null;
        TempData.Keep("Name"); // Keep the name in TempData
        ViewBag.Name = name;
        return View();
    }
    ```

    - Using `Peek()` method

    ```csharp
    public IActionResult Third()
    {
        string name = TempData.Peek("Name") ?? null;
        ViewBag.Name = name;
        return View();
    }
    ```

## HttpContext

- A HttpContext object holds information about the current HTTP request and response.
- It provides access to the request and response objects, as well as other information about the current request, such as the user's IP address and browser type.
- The important point is, whenever we make a new HTTP request or response then the HttpContext object is created.
- Each time it is created, it creates a server current state of a HTTP request and response.
- It can hold information like Request, Response, Server, Session, Item, Cache, User's information like authentication and authorization and much more.
- As the request is created in each HTTP request, it ends too after the finish of each HTTP request or response.

### Creating HttpContext

1. Adding `Session State` using HttpContext

   ```csharp
    public IActionResult Index()
    {
        HttpContext.Session.SetString("Name", "John Doe");
        return View();
    }
   ```

   In this code, we are storing the name "John Doe" in the session.

   ```csharp
   public IActionResult Get()
   {
       string name = HttpContext.Session.GetString("Name");
       ViewBag.Name = name; // Add the name to the ViewBag
       return View();
   }
   ```

2. Access the current URL using HttpContext.

   ```csharp
   protected void Page_Load(object sender, EventArgs e)
    {
        string url = HttpContext.Current.Request.Url.ToString();
        Response.Write("The current URL is: " + url);
    }
   ```

3. Access the user's IP address using HttpContext

   ```csharp
   protected void Page_Load(object sender, EventArgs e)
    {
        string ip = HttpContext.Current.Request.UserHostAddress;
        Response.Write("Your IP Address is: " + ip);
    }
   ```
