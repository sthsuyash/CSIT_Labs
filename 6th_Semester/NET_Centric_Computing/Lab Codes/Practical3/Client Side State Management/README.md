# Client side state management in ASP.NET

Client side state management is a technique used to store the state of a web page in the client's browser. This technique is used to maintain the state of a web page across postbacks.

In ASP.NET, there are several ways to manage the state of a web page on the client side. Some of the common ways are:

- **Cookies**: Cookies are small pieces of data that are stored on the client's browser. They can be used to store information about the user, such as their preferences or login information.
- **Query Strings**: Query strings are used to pass information between pages in a web application. They are appended to the URL of a page and can be read by the server-side code.
- **Hidden Fields**: Hidden fields are used to store information on a web page that is not visible to the user. They are rendered as HTML input elements with the `type="hidden"` attribute.

  Example of hidden field:

  ```html
  <input asp-for="userid" type="hidden" />
  ```

  Here, `userid` is the name of the hidden field and the value is stored in the `value` attribute.

## Cookies

Cookies store data in the user's browser. Browsers send cookies to the server with each request, allowing the server to identify the user and maintain their state across multiple requests, so their size must be kept to minimum. Cookies can be set to expire after a certain period of time or when the browser is closed.

Users can easily tamper or delete a cookie, so we should not store sensitive information in cookies.

We often use cookies to personalize the content for a known user especially when we identify a user without identification. For example, we can store the user's name in a cookie so that we can display a personalized greeting message when the user visits the site, or a color theme preference.

Example of cookie:

```text
Name: username
Value: John
Expiry: 2022-12-31
```

Here, `username` is the name of the cookie, `John` is the value, and `2022-12-31` is the expiry date.

### Reading Cookies

```csharp
// using IHttpContextAccessor
string cookieValueFromContext = httpContextAccessor.HttpContext.Request.Cookies["username"];
```

OR

```csharp
// read cookie from request object
string cookie = Request.Cookies["username"];
```

### Writing Cookies

```csharp
public void SetCookie(string key, string value, int? expireTime)
{
    // create cookie options
    CookieOptions option = new CookieOptions();
    if (expireTime.hasValue)
    {
        option.Expires = DateTime.Now.AddMinutes(expireTime.Value);
    }
    else
    {
        // if no expiry time is specified, set the cookie to expire in 1 minute
        option.Expires = DateTime.Now.AddMinutes(1);
    }
    Response.Cookies.Append(key, value, option);
    return RedirectToAction("Index");
}
```

### Removing Cookies

```csharp
public void DeleteCookie(string key)
{
    Response.Cookies.Delete(key);
    return RedirectToAction("Index");
}
```

## Query Strings

Query strings are used to pass information between pages in a web application. We can pass limited amount of data from one request to another by adding it to query string of new request. This is useful for capturing the state in a persistent manner and allows the sharing of links with the embedded state.

We should never use query strings for sensitive information as they are visible to the user and can be easily tampered with.

**Note**: In addition to unintended sharing, including data in query strings will make our application to Cross-Site Forgery(CSRF) attacks, which can trick users into visiting malicious sites while authenticated. Attackers can then steal user data or take malicious actions on behalf of the user.

Example in URL: `http://www.example.com/page.aspx?name=John&age=25`

Here, `name=John&age=25` is the query string, where `name` and `age` are the keys and `John` and `25` are the values.

### Accessing Query Strings

```csharp
public String GetQueryString(string name, int age)
{
    return "Name: " + name + ", Age: " + age;
}
```

OR, passing data to Razor view using ViewBag:

```csharp
public IActionResult Index(string name, int age)
{
    ViewBag.Name = name;
    ViewBag.Age = age;
    return View();
}
```

```html
<p>Name: @ViewBag.Name</p>
<p>Age: @ViewBag.Age</p>
```

## Hidden Fields

Hidden fields are used to store information on a web page that is not visible to the user. They are rendered as HTML input elements with the `type="hidden"` attribute.

We can save data in hidden form fields and send back in the next request. Sometimes we require some data to be stored on the client side without displaying it in the page. Later when the user takes action, we will need that data to be passed on the server side. In such cases, we can use hidden fields.

- Index controller action method:

```csharp
public IActionResult Index()
{
    ViewBag.Id = 1;
    ViewBag.Name = "John";
    return View();
}
```

```csharp
[HttpPost]
public IActionResult Index(int Id, string Name)
{
    ViewBag.Id = Id;
    ViewBag.Name = Name;
    Console.WriteLine("Id: " + Id + ", Name: " + Name); // even if hidden field is not visible, we can access it
    return View();
}
```

- The razor view:

```html
<p>Hidden Field: @ViewBag.Id</p>

<form asp-action="Index" method="post">
  <input type="hidden" id="Id" name="Id" value="@ViewBag.Id" />
  <label for="Name">Name:</label>
  <input type="text" id="Name" name="Name" value="@ViewBag.Name" />
  <button type="submit">Submit</button>
</form>
```
