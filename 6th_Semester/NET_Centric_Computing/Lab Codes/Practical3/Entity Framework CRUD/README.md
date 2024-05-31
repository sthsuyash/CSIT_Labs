# Entity Framework Core

- Entity Framework Core is a lightweight, extensible, open source and cross-platform version of the popular Entity Framework data access technology.
- It can serve as an object-relational mapper (ORM), enabling .NET developers to work with a database using .NET objects.
- It eliminates the need for most of the data-access code that developers usually need to write.
- It supports LINQ queries, change tracking, updates, and schema migrations.
- It can be database-first, model-first or code-first.

## Steps to use Entity Framework Core in an ASP.NET Core application

1. First, create a new project in Visual Studio with the `ASP.NET Core Web Application (Model-View-Controller)` template.

2. Then, install the Entity Framework Core package using the NuGet Package Manager.

   - Right-click on the project in Solution Explorer and select Manage NuGet Packages.
   - Search for `Microsoft.EntityFrameworkCore` and install the package.
   - `Microsoft.EntityFrameworkCore.SqlServer` -> for SQL Server database provider.
   - `Microsoft.EntityFrameworkCore.Tools` -> for EF Core tools such as migrations.

3. Create a model class that represents a table in the database. Let's say we have a Officer table.

   ```c#
    public class Officer
    {
        public Guid Id { get; set; }
        public string Name { get; set; }
        public string Gender { get; set; }
        public string Phone { get; set; }
        public string Department { get; set; }
        public string Position { get; set; }
    }
   ```

4. Create a DbContext class that represents a session with the database. It is used to query and save instances of the model classes.

   ```c#
   namespace Entity_Framework_CRUD.Models
   {
       public class OfficerContext : DbContext
       {
           public OfficerContext(DbContextOptions<OfficerContext> options) : base(options) { }

           public DbSet<Officer> tbl_officer { get; set; } // This is the table name i.e tbl_officer,
           // We can name it anything we want, but it should be same as the table name in the database.
       }
   }

   ```

5. Register the DbContext in the `Program.cs` file.

   ```c#
   builder.Services.AddDbContext<OfficerContext>(options => {
      options.UseSqlServer(builder.Configuration.GetConnectionString("connectionString"));
   });
   ```

  6. In `appsettings.json` file, add the connection string for the database.

  ```csharp
  {
    "ConnectionStrings":{
    "connectionString": "Server=Servername; Database=DatabaseName; Trusted_Connection=True;"
    }
  }
  ```

7. Create a migration to generate the database schema.

   - Open the Package Manager Console.
   - Run the command `Add-Migration "Initial"` to create a migration.
   - Run the command `Update-Database` to apply the migration and create the database.

8. Use the DbContext in a controller to query and save data.

## CRUD Operations

- Create a new Controller for the model, i.e. `OfficerController`.

- Then, add the `DbContext` in the Controller using Dependency Injection.

  ```c#
  public class OfficerController : Controller
  {
      private readonly OfficerContext _context;
      public OfficerController(OfficerContext context)
      {
          _context = context;
      }
  }
  ```

### Read Operation (List)

For the Read operation, i.e Read a list, create `Index` action method to display the list of officers, which will be shown at the root URL and return the view.

- `Controller/OfficerController.cs`

```c#
public IActionResult Index()
{
   var officers = _context.tbl_officer.ToList();
   return View(officers);
}
```

- `Views/Officer/Index.cshtml`

```c#
@model List<Entity_Framework_Core.Models.Officer>
@{ViewData["Title"] = "Officers List";}

<h1>Officers List</h1>

<p><a asp-action="CreateOfficer">Create New Officer</a></p>

<table class="table">
    <thead>
        <tr>
            <th>Name</th>
            <th>Gender</th>
            <th>Phone</th>
            <th>Department</th>
            <th>Position</th>
            <th>Actions</th>
        </tr>
    </thead>
    <tbody>
        @foreach (var item in Model)
        {
            <tr>
                <td>@item.Name</td>
                <td>@item.Gender</td>
                <td>@item.Phone</td>
                <td>@item.Department</td>
                <td>@item.Position</td>
                <td>
                    <a href="Officer/UpdateOfficer/@item.Id">Edit</a> |
                    <a href="Officer/DeleteOfficer/@item.Id">Delete</a>
                </td>
            </tr>
        }
    </tbody>
</table>
```

### Create Operation

For the Create operation, create `CreateOfficer` action method to display the form to create a new officer. It must have a get and post method.

- `Controller/OfficerController.cs` => Get Method

```c#
[HttpGet]
public IActionResult CreateOfficer()
{
   return View();
}
```

This will return the view `CreateOfficer.cshtml` which will have a form to create a new officer.

- `Views/Officer/CreateOfficer.cshtml`

```c#
@model Entity_Framework_CRUD.Models.Officer

@{ViewData["Title"] = "Create Officer";}

<h1>Create Officer</h1>

<h4>Officer</h4>
<hr />
<div>
    <div>
        <form asp-action="CreateOfficer">
            <div >
                <label asp-for="Name"></label>
                <input asp-for="Name" />
            </div>
            <div >
                <label asp-for="Gender"></label>
                <input asp-for="Gender" />
            </div>
            <div >
                <label asp-for="Phone"></label>
                <input asp-for="Phone" />
            </div>
            <div >
                <label asp-for="Department"></label>
                <input asp-for="Department" />
            </div>
            <div >
                <label asp-for="Position"></label>
                <input asp-for="Position" />
            </div>
            <div >
                <input type="submit" value="Create" />
            </div>
        </form>
    </div>
</div>

<div>
    <a asp-action="Index">Back to List</a>
</div>
```

Then, we need to create a post method to save the data to the database.

- `Controller/OfficerController.cs` => Post Method

```c#
[HttpPost]
public IActionResult CreateOfficer(Officer o)
{
   var officer = new Officer(){
      Id = Guid.NewGuid(),
      Name = o.Name,
      Gender = o.Gender,
      Department = o.Department,
      Phone = o.Phone,
      Position = o.Position
   };

   _context.tbl_officer.Add(officer);
   _context.SaveChanges();
   return RedirectToAction("Index");
}
```

This will save the data to the database and redirect to the Index page.

### Read Operation (Single Record)

For the Read operation, i.e Read a single record, create `GetOfficer` action method to display the details of a single officer. We need to pass the id of the officer to get the details.

- `Controller/OfficerController.cs` => Get Method

```c#
[HttpGet]
public IActionResult GetOfficer(Guid id)
{
   var officer = _context.tbl_officer.Find(id);
   if (officer == null){ return RedirectToAction("Index"); }
   return View(officer);
}
```

This will return the view `GetOfficer.cshtml` which will display the details of the officer.

- `Views/Officer/GetOfficer.cshtml`

```c#
@model Entity_Framework_CRUD.Models.Officer;

@{ViewData["Title"] = "Officer Details";}
<h1>Officer Details</h1>

<div>
   <h4>Officer</h4>
   <hr />
   <table class="table">
      <tr>
         <th>Name</th>
         <th>Gender</th>
         <th>Phone</th>
         <th>Department</th>
         <th>Position</th>
      </tr>
      <tr>
         <td>@Model.Name</td>
         <td>@Model.Gender</td>
         <td>@Model.Phone</td>
         <td>@Model.Department</td>
         <td>@Model.Position</td>
      </tr>
   </table>
</div>

<div>
   <a asp-action="Index">Back to List</a>
</div>
```

### Update Operation

For the Update operation, create UpdateOfficer action method to display the form to update an officer. It must have a get and post method.

- `Controller/OfficerController.cs` => Get Method

```c#
[HttpGet]
public IActionResult UpdateOfficer(Guid id)
{
   var officer = _context.tbl_officer.FindFirstOrDefault(o => o.Id == id);
   if (officer == null){ return RedirectToAction("Index"); }
   return View(officer);
}
```

This will return the view `UpdateOfficer.cshtml` which will have a form to update an officer.

- `Views/Officer/UpdateOfficer.cshtml`

```c#
@model Entity_Framework_CRUD.Models.Officer

@{ViewData["Title"] = "Update Officer";}

<h1>Update Officer</h1>

<h4>Officer</h4>
<hr />
<div>
   <form asp-action="UpdateOfficer">
       <input type="hidden" asp-for="Id" />
       <div >
           <label asp-for="Name"></label>
           <input asp-for="Name" />
       </div>
       <div>
          <label asp-for="Gender"></label>
          <input asp-for="Gender" />
       </div>
       <div>
          <label asp-for="Department"></label>
          <input asp-for="Department" />
       </div>
       <div>
          <label asp-for="Phone"></label>
          <input asp-for="Phone" />
       </div>
       <div>
          <label asp-for="Position"></label>
          <input asp-for="Position" />
       </div>
       <div>
          <input type="submit" value="Save">
       </div>
    </form>
</div>

<div><a asp-action="Index">Back to List</div>
```

Then, we need to create a post method to update the data in the database.

- `Controller/OfficerController.cs` => Post Method

```c#
[HttpPost]
public IActionResult UpdateOfficer(Guid id)
{
   var officer = _context.tbl_officer.Find(o.Id);
   if (officer != null){
      officer.Name = o.Name;
      officer.Gender = o.Gender;
      officer.Department = o.Department;
      officer.Phone = o.Phone;
      officer.Position = o.Position;
      _context.SaveChanges();
   }
   return RedirectToAction("Index");
}
```

This will update the data in the database and redirect to the Index page.

### Delete Operation

For the Delete operation, create `DeleteOfficer` action method to delete an officer. We need to pass the id of the officer to delete.
We can just create a post method for this operation as we are not displaying any form.

- `Controller/OfficerController.cs` => Post Method

```c#
[HttpPost]
public IActionResult DeleteOfficer(Guid id)
{
   var officer = _context.tbl_officer.FindFirstOrDefault(o => o.Id == id);
   if (officer != null){
      _context.tbl_officer.Remove(officer);
      _context.SaveChanges();
   }
   return RedirectToAction("Index");
}
```
