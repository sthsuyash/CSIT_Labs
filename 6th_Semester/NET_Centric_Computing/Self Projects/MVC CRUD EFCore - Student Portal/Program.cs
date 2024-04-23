using Microsoft.EntityFrameworkCore;
using MVC_CRUD_EFCore___Student_Portal.Models;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddControllersWithViews();

// inject the StudentContext into application so that it can be used to connect to the database
// and can be accessed by the controllers later on to perform CRUD operations
builder.Services.AddDbContext<StudentContext>(options =>
options.UseSqlServer(builder.Configuration.GetConnectionString("cs")));

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Home/Error");
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
}

app.UseHttpsRedirection();
app.UseStaticFiles();

app.UseRouting();

app.UseAuthorization();

// by default, the app will look for a controller named HomeController
// and an action named Index
// the controller and action can be changed by modifying the URL
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Home}/{action=Index}/{id?}");

app.Run();
