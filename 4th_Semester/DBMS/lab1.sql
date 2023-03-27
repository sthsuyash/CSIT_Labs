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
INSERT INTO Department (dept_name) VALUES ('Finance');
INSERT INTO Department (dept_name) VALUES ('Human Resources');
INSERT INTO Department (dept_name) VALUES ('Marketing');
INSERT INTO Department (dept_name) VALUES ('Operations');

-- Insert into Designation table
INSERT INTO Designation (desig_name) VALUES ('Manager');
INSERT INTO Designation (desig_name) VALUES ('Project Leader');
INSERT INTO Designation (desig_name) VALUES ('Intern');
INSERT INTO Designation (desig_name) VALUES ('Software Developer');

-- Insert into Employee_type table
INSERT INTO Employee_type (emptype_name) VALUES ('Full-time');
INSERT INTO Employee_type (emptype_name) VALUES ('Part-time');
INSERT INTO Employee_type (emptype_name) VALUES ('Intern');
INSERT INTO Employee_type (emptype_name) VALUES ('Consultant');

-- Insert into Project table
INSERT INTO Project (proj_name, start_date, deadline) VALUES ('Project A', '2023-04-01', '2023-07-31');
INSERT INTO Project (proj_name, start_date, deadline) VALUES ('Project B', '2023-05-15', '2023-09-30');
INSERT INTO Project (proj_name, start_date, deadline) VALUES ('Project C', '2023-03-01', '2023-06-30');
INSERT INTO Project (proj_name, start_date, deadline) VALUES ('Project D', '2023-06-01', '2023-11-30');

-- Insert into Employee table
INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES ('John Doe', 'Kathmandu', '9841234567', 50000.00, 1, 1, 1, 1);

INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES ('Jane Smith', 'Bhaktapur', '9869876543', 70000.00, 2, 2, 1, 2);

INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES ('Bob Anderson', 'Lalitpur', '9812345678', 30000.00, 3, 4, 2, 1);

INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES ('Sarah Lee', 'Pokhara', '9801234567', 60000.00, 4, 3, 1, 3);

INSERT INTO Employee (emp_name, emp_address, emp_contact, emp_salary, dept_id, desig_id, emptype_id, proj_id) 
VALUES ('Tom Williams', 'Kathmandu', '9865432109', 90000.00, 1, 2, 1, 4);

-- 4. Find the record of employees whose salary is less than 40K
SELECT * FROM Employee WHERE emp_salary < 40000.00;

-- 5. Find the record of employees whose salary is between 30K to 80K
SELECT * FROM Employee WHERE emp_salary BETWEEN 30000.00 AND 80000.00;

-- 6. Find the record of employees whose salary is greater than 80K
SELECT * FROM Employee WHERE emp_salary > 80000.00;

-- 7. Find the record of employee whose address is out of Kathmandu Valley
SELECT * FROM Employee WHERE emp_address NOT IN ('Kathmandu', 'Lalitpur', 'Bhaktapur');

-- 8. Find the salary of employee whose designation is Manager
SELECT emp_salary FROM Employee WHERE desig_id = 1;

-- 9. Find the record of internship employees
SELECT * FROM Employee WHERE emptype_id = 3;

-- 10.Find the name of employees whose designation is project leader and salary is greater than 90K
SELECT emp_name FROM Employee WHERE desig_id = 2 AND emp_salary > 90000.00;

-- 11.Find the name of the employees whose address is Kathmandu or Bhaktapur
SELECT emp_name FROM Employee WHERE emp_address IN ('Kathmandu', 'Bhaktapur');

-- 12.List all the project name with corresponding employees name whose deadline is less than 7 days from today
SELECT p.proj_name, e.emp_name 
FROM Project p 
INNER JOIN Employee e 
ON p.proj_id = e.proj_id 
WHERE p.deadline < DATEADD(day, 7, GETDATE());
