-- Create Database named Prime_College 
create database Prime_College;
use Prime_College;

-- create a table name Student with necessary columns.
create table Student(
    id int identity(1,1) primary key,
    -- use identity(1,1) for sql server, auto_increment for mysql
    name varchar(50) not null,
    address varchar(100) not null,
    contact varchar(20) unique,
    stream varchar(50) not null,
    result decimal(10,2)
);

insert into Student values 
('Ram', 'Kathmandu', '9841984198', 'CSIT', 78.5),
('Shyam', 'Lalitpur', '9841984188', 'BIM', 68.5),
('Hari', 'Bhaktapur', '9841984178', 'BBA', 58.5),
('Gita', 'Pokhara', '9841984168', 'CSIT', 88.5),
('Sita', 'Kathmandu', '9841984158', 'CSIT', 98.5);

-- Perform the follow queries with above table 
-- a.	Display name of all students who is not from Kathmandu 
select name from Student where address <> 'Kathmandu';
-- b.	Display the details of students whose stream is CSIT
select * from Student where stream = 'CSIT';
-- c.	Delete the data of student whose id is 5
delete from Student where id = 5;
-- d.	Update the name of student whose id is 2
update Student set name = 'Dhyan' where id = 2;
-- e.	Display the name and result of students who are pass in first division and above 
select name, result from Student where result >= 60;

-- Create a view of above table which will display the name, stream and result percentage of students.
create view Student_view as select name, stream, result from Student;

-----------------------------------------------------------------------------------------------------------------

-- Create Database named Company
create database Company;
use Company;
-- create a table name Employee with necessary columns. 
create table Employee(
    id int identity(1,1) primary key,
    name varchar(50) not null,
    address varchar(100) not null,
    contact varchar(20) unique,
    salary int,
    department varchar(50) not null
);

insert into Employee values 
('Ram', 'Kathmandu', '9841984198', 20000, 'IT'),
('Shyam', 'Lalitpur', '9841984198', 30000, 'HR'),
('Hari', 'Bhaktapur', '9841984198', 40000, 'IT'),
('Gita', 'Pokhara', '9841984198', 50000, 'HR'),
('Sita', 'Kathmandu', '9841984198', 60000, 'IT');

-- Perform the follow queries with above table 
-- a.	Display name of all employees who is not working in HR department 
select name from Employee where department <> 'HR';
-- b.	Display the name and salary of employees whose salary is greater than 20k
select name, salary from Employee where salary > 20000;
-- c.	Display the total salary of employees paid by company at once.  
select sum(salary) from Employee;
-- d.	Update the salary of employees as 30k who are getting currently 20k 
update Employee set salary = 30000 where salary = 20000;
-- e.	Display the details of employees who are form Kathmandu.
select * from Employee where address = 'Kathmandu';

-- Create a view of above table which will display the name, salary and department of employees.
create view Employee_view as select name, salary, department from Employee;