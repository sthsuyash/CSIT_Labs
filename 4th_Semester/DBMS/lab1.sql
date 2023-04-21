-- 1. Create a database with your name eg. DBRam
CREATE DATABASE DBSuyash;
USE DBSuyash;

-- 2. Create following table with necessary constraints
-- a. Department table with attributes dept_id(pk, identity), dept_name (not null)
CREATE TABLE Department (
  dept_id INT AUTO_INCREMENT PRIMARY KEY,
  dept_name VARCHAR(50) NOT NULL
);

-- b. Designation table with attributes desig_id (pk, identity), desig_name (not null)
CREATE TABLE Designation (
  desig_id INT AUTO_INCREMENT PRIMARY KEY,
  desig_name VARCHAR(50) NOT NULL
);

-- c. Employee_type table with attributes emptype_id(pk, identity), emptype_name (not null)
CREATE TABLE Employee_type (
  emptype_id INT AUTO_INCREMENT PRIMARY KEY,
  emptype_name VARCHAR(50) NOT NULL
);

-- d. Project table with attributes proj_id(pk, identity), porj_name (not null), start_date, deadline
CREATE TABLE Project (
  proj_id INT AUTO_INCREMENT PRIMARY KEY,
  proj_name VARCHAR(50) NOT NULL,
  start_date DATE,
  deadline DATE
);

-- e. Employee table with attributes emp_id (pk, identity), emp_name (not null), 
-- emp_address (not null), emp_contact (unique), emp_salary,
-- dept_id (fk), desig_id (fk), emptype_id (fk), proj_id(fk)
CREATE TABLE Employee (
  emp_id INT AUTO_INCREMENT PRIMARY KEY,
  emp_name VARCHAR(50) NOT NULL,
  emp_address VARCHAR(100) NOT NULL,
  emp_contact VARCHAR(20) UNIQUE,
  emp_salary DECIMAL(10, 2),
  dept_id INT,
  desig_id INT,
  emptype_id INT,
  proj_id INT,
  FOREIGN KEY (dept_id) REFERENCES Department(dept_id),
  FOREIGN KEY (desig_id) REFERENCES Designation(desig_id),
  FOREIGN KEY (emptype_id) REFERENCES Employee_type(emptype_id),
  FOREIGN KEY (proj_id) REFERENCES Project(proj_id)
);

-- 3. Insert the record on all the tables you just created with appropriate values.

-- Insert into Department table
INSERT INTO Department (dept_name) VALUES 
('Finance'),
('Human Resources'),
('Marketing'),
('Operations');

-- Insert into Designation table
INSERT INTO Designation(desig_name) VALUES
('Manager'),
('Project Leader'),
('Intern'),
('Software Developer');

-- Insert into Employee_type table
INSERT INTO Employee_type(emptype_name) VALUES
('Full-time'),
('Part-time'),
('Intern'),
('Consultant');

-- Insert into Project table
INSERT INTO Project(proj_name, start_date, deadline) VALUES
('Project A', '2023-02-01', '2023-03-31'),
('Project B', '2023-05-15', '2023-09-30'),
('Project C', '2023-03-01', '2023-06-30'),
('Project D', '2023-06-01', '2023-11-30');

-- Insert into Employee table
INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES 
('John Doe', 'Kathmandu', '9841234567', 50000, 1, 1, 1, 1),
('Jane Smith', 'Bhaktapur', '9869876543', 70000, 2, 2, 1, 2),
('Bob Anderson', 'Lalitpur', '9812345678', 30000, 3, 4, 2, 1),
('Sarah Lee', 'Pokhara', '9801234567', 60000, 4, 3, 1, 3),
('Tom Williams', 'Kathmandu', '9865432109', 90000, 1, 2, 1, 4),
('Dion Spinige','Kathmandu', '9891248118', 860000, 1, 1, 1, 2),
('Valeda Marcinkus','Bhaktapur', '9873536218',100000, 2, 2, 2, 1),
('Philipa Runnett','Pokhara', '9848464792',70000, 3, 3, 3, 4),
('Rosalie Hinksen','Kathmandu', '9892210247',160000, 4, 4, 4, 1),
('Celina Thominga','Kathmandu', '9855986212',120000, 3, 2, 1, 4),
('Godart Cordet','Pokhara', '9815936785', 50000, 4, 1, 2, 3),
('Baryram Goode','Bhaktapur', '9863945484', 40000, 2, 3, 1, 1),
('Ilene Krimmer','Lalitpur', '9854831821', 30000, 1, 2, 1, 2),
('Brook Scholz','Kathmandu', '9852526014', 20000, 3, 3, 3, 3),
('Blakeley Pearsey','Kathmandu', '9809356529', 100000, 4, 2, 1, 2),
('Theadora Arsmith','Bhaktapur', '9811847429', 260000, 3, 1, 2, 2),
('Micky Rawlison','Lalitpur', '9806558122', 160000, 4, 2, 2, 1),
('Matilda Steers','Kathmandu', '9892940963', 50000, 3, 2, 1, 1),
('Cybill Swinglehurst','Pokhara', '9899780955', 120000, 2, 2, 4, 1),
('Susan Habercham','Kathmandu', '9825790310', 340000, 3, 2, 1, 1),
('Violante Daverin','Kathmandu', '9893947531', 30000,  2, 1, 1, 2),
('Cordell Bourgour','Pokhara', '9864580688', 80000, 3, 3, 4, 3),
('Loralyn Orton', 'Bhaktapur','9826316580', 99000,  4, 4, 4, 4),
('Richy Tweedle','Lalitpur', '9893505619', 450000, 1, 1, 2, 4),
('Danita Doget','Bhaktapur', '9844729755', 100000, 3, 2, 4, 1);

-- 4. Find the record of employees whose salary is less than 40K
SELECT
emp_name as Name,
emp_address as Address,
emp_contact as Contact,
emp_salary as Salary,
dept_name as Department,
desig_name as Designation,
emptype_name Job,
proj_name as Project 
FROM Employee
INNER JOIN Department ON Employee.dept_id = Department.dept_id
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
INNER JOIN Employee_type ON Employee.emptype_id = Employee_type.emptype_id
INNER JOIN Project ON Employee.proj_id = Project.proj_id
WHERE emp_salary < 40000 
ORDER BY Name;

-- 5. Find the record of employees whose salary is between 30K to 80K
SELECT
emp_name as Name,
emp_address as Address,
emp_contact as Contact,
emp_salary as Salary,
dept_name as Department,
desig_name as Designation,
emptype_name Job,
proj_name as Project 
FROM Employee
INNER JOIN Department ON Employee.dept_id = Department.dept_id
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
INNER JOIN Employee_type ON Employee.emptype_id = Employee_type.emptype_id
INNER JOIN Project ON Employee.proj_id = Project.proj_id
WHERE emp_salary BETWEEN 30000 AND 80000 
ORDER BY salary;

-- 6. Find the record of employees whose salary is greater than 80K
SELECT
emp_name as Name,
emp_address as Address,
emp_contact as Contact,
emp_salary as Salary,
dept_name as Department,
desig_name as Designation,
emptype_name Job,
proj_name as Project 
FROM Employee
INNER JOIN Department ON Employee.dept_id = Department.dept_id
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
INNER JOIN Employee_type ON Employee.emptype_id = Employee_type.emptype_id
INNER JOIN Project ON Employee.proj_id = Project.proj_id
WHERE emp_salary > 80000 ORDER BY Name;

-- 7. Find the record of employee whose address is out of Kathmandu Valley
SELECT
emp_name as Name,
emp_address as Address,
emp_contact as Contact,
emp_salary as Salary,
dept_name as Department,
desig_name as Designation,
emptype_name Job,
proj_name as Project 
FROM Employee
INNER JOIN Department ON Employee.dept_id = Department.dept_id
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
INNER JOIN Employee_type ON Employee.emptype_id = Employee_type.emptype_id
INNER JOIN Project ON Employee.proj_id = Project.proj_id
WHERE emp_address NOT IN ('Kathmandu', 'Lalitpur', 'Bhaktapur')
ORDER BY Name;

-- 8. Find the salary of employee whose designation is Manager
SELECT
emp_name as Name,
emp_salary as Salary
FROM Employee
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
WHERE Employee.desig_id = 1
ORDER BY Salary;

-- 9. Find the record of internship employees
SELECT
emp_name as Name,
emp_address as Address,
emp_contact as Contact,
emp_salary as Salary,
dept_name as Department,
desig_name as Designation,
emptype_name Job,
proj_name as Project 
FROM Employee
INNER JOIN Department ON Employee.dept_id = Department.dept_id
INNER JOIN Designation ON Employee.desig_id = Designation.desig_id
INNER JOIN Employee_type ON Employee.emptype_id = Employee_type.emptype_id
INNER JOIN Project ON Employee.proj_id = Project.proj_id
WHERE Employee_type.emptype_id = 3
ORDER BY Name; 

-- 10.Find the name of employees whose designation is project leader and salary is greater than 90K
SELECT emp_name as Name 
FROM Employee 
WHERE desig_id = 2 AND emp_salary > 90000;

-- 11.Find the name of the employees whose address is Kathmandu or Bhaktapur
SELECT emp_name as Name FROM Employee WHERE emp_address IN ('Kathmandu', 'Bhaktapur');

-- 12.List all the project name with corresponding employees name whose deadline is less than 7 days from today
SELECT
proj_name as Project,
emp_name as Name
FROM Project
JOIN Employee ON Project.proj_id = Employee.proj_id
WHERE deadline < DATE_ADD(CURDATE(), INTERVAL 7 DAY);
