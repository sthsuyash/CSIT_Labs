# User Registration Console App

Write a console program (ADO.net) to create a table `tbl_registration` that have fields:

```sql
id int primary key,
username varchar,
password varchar,
repassword varchar,
gender varchar,
course varchar,
country varchar
```

After this perform the following operation:

- Insert any 5 data into tbl_registration. All the required input should be taken from user
- Display all the record of database table
- Update the name and course of a person to data given by user according to id given by user
- Delete the record of person whose id is given by user
- Display all the record of person who are male and also from country Nepal

## Steps to Setup

- First, create a database named `UserRegistrationPractical` or anything you want in SQL Server.
- Change the connectionString in `Registration.cs` file according to your SQL Server.
- Run the program.
