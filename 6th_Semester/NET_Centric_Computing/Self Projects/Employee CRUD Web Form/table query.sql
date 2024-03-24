-- create database EmployeeDB;
use EmployeeDB;

-- Departments Table
CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY IDENTITY(1,1),
    DepartmentName VARCHAR(100),
    Location VARCHAR(255)
);

-- Employees Table
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    DateOfBirth DATE,
    Gender CHAR(1),
    Email VARCHAR(100),
    PhoneNumber VARCHAR(10),
    Address VARCHAR(255),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

-- Department Managers Table
CREATE TABLE DepartmentManager (
    DepartmentID INT,
    ManagerID INT,
    PRIMARY KEY (DepartmentID),
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID),
    FOREIGN KEY (ManagerID) REFERENCES Employee(EmployeeID)
);

-- Roles/Positions Table
CREATE TABLE Role (
    RoleID INT PRIMARY KEY IDENTITY(1,1),
    RoleName VARCHAR(100),
    Salary DECIMAL(10, 2),
    JobDescription TEXT
);

-- Employee Roles/Positions Table
CREATE TABLE EmployeeRole (
    EmployeeRoleID INT PRIMARY KEY IDENTITY(1,1),
    EmployeeID INT,
    RoleID INT,
    StartDate DATE,
    EndDate DATE,
    FOREIGN KEY (EmployeeID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (RoleID) REFERENCES Role(RoleID)
);


-- Inserting data into Department table
INSERT INTO Department (DepartmentName, Location)
VALUES 
('Engineering', 'Kathmandu'),
('Marketing', 'Bhaktapur'),
('Finance', 'Kathmandu');

-- Inserting data into Employee table
INSERT INTO Employee (FirstName, LastName, DateOfBirth, Gender, Email, PhoneNumber, Address, DepartmentID)
VALUES
('John', 'Doe', '1990-05-15', 'M', 'john.doe@example.com', '1234567890', '123 Main St, City', 1),
('Jane', 'Smith', '1985-08-20', 'F', 'jane.smith@example.com', '9876543210', '456 Elm St, Town', 2),
('Michael', 'Johnson', '1982-10-10', 'M', 'michael.johnson@example.com', '5556667777', '789 Oak St, Village', 3);

-- Inserting data into DepartmentManager table
INSERT INTO DepartmentManager (DepartmentID, ManagerID)
VALUES
(1, 1), -- John Doe manages Engineering department
(2, 2); -- Jane Smith manages Marketing department

-- Inserting data into Role table
INSERT INTO Role (RoleName, Salary, JobDescription)
VALUES
('Software Engineer', 80000.00, 'Develop software applications'),
('Marketing Manager', 90000.00, 'Oversee marketing campaigns'),
('Financial Analyst', 85000.00, 'Analyze financial data');

-- Inserting data into EmployeeRole table
INSERT INTO EmployeeRole (EmployeeID, RoleID, StartDate, EndDate)
VALUES
(1, 1, '2020-01-01', NULL), -- John Doe is a Software Engineer since 2020
(2, 2, '2019-07-01', NULL), -- Jane Smith is a Marketing Manager since 2019
(3, 3, '2018-05-01', NULL); -- Michael Johnson is a Financial Analyst since 2018
