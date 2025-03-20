-- Database Operation

-- 1. Create database
CREATE DATABASE starter;

-- 2. Use created database
USE starter;

-- 3. Create Table.

-- a. Create table normally:
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Age INT,
    Department VARCHAR(50)
);

-- b. Create table using another table:
CREATE TABLE EmployeeBackup AS
SELECT * FROM Employees;

-- 4. Alter table

-- a. Add column:
ALTER TABLE Employees ADD Salary DECIMAL(10,2);

-- b. Drop column:
ALTER TABLE Employees DROP COLUMN Age;

-- c. Alter/Modify column:
ALTER TABLE EmployeeBackup MODIFY COLUMN Age SMALLINT;

-- 5. Constraints

-- a. NOT NULL
-- i. Apply NOT NULL While Creating Table
CREATE TABLE Departments (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(100) NOT NULL
);

-- ii. Apply NOT NULL Using ALTER TABLE
ALTER TABLE Employees MODIFY Name VARCHAR(100) NOT NULL;

-- b. UNIQUE

-- i. Unique Constraint While Creating Table
CREATE TABLE Projects (
    ProjectID INT UNIQUE,
    ProjectName VARCHAR(100)
);

-- ii. Add Unique Constraint Using ALTER TABLE
ALTER TABLE Employees ADD CONSTRAINT unique_name UNIQUE (Name);

-- iii. Drop a Unique Constraint
ALTER TABLE Employees DROP CONSTRAINT unique_name;

-- c. PRIMARY KEY
-- i. Primary Key Constraint
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    OrderDate DATE
);

-- ii. Primary Key on Multiple Columns
CREATE TABLE OrderDetails (
    OrderID INT,
    ProductID INT,
    Quantity INT,
    PRIMARY KEY (OrderID, ProductID)
);

-- iii. Add Primary Key on ALTER TABLE
ALTER TABLE Orders ADD PRIMARY KEY (OrderID);

-- iv. Drop a Primary Key Constraint
ALTER TABLE Orders DROP PRIMARY KEY;

-- d. FOREIGN KEY
-- i. Foreign Key Constraint
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    CustomerName VARCHAR(100)
);

CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT,
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)
);

-- ii. Add Foreign Key on ALTER TABLE
ALTER TABLE Orders ADD CONSTRAINT fk_customer FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID);

-- iii. Drop a Foreign Key Constraint
ALTER TABLE Orders DROP CONSTRAINT fk_customer;

-- e. DEFAULT Constraint
-- i. SQL DEFAULT Constraint
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100),
    Department VARCHAR(50) DEFAULT 'General'
);

-- ii. Add DEFAULT Using ALTER TABLE
ALTER TABLE Employees ALTER COLUMN Department SET DEFAULT 'HR';

-- iii. Drop a DEFAULT Constraint
ALTER TABLE Employees ALTER COLUMN Department DROP DEFAULT;

-- f.	CHECK Constraint: This is used to enforce rules on column values to ensure data integrity.
-- i.	SQL Check Constraint (While creating a Table):
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(100) NOT NULL,
    Age INT CHECK (Age >= 18),  -- Ensures Age is at least 18
    Salary DECIMAL(10,2) CHECK (Salary > 0)  -- Ensures Salary is a positive value
);

-- ii.	CHECK Constraint for Multiple Columns:
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    Quantity INT,
    Price DECIMAL(10,2),
    CHECK (Quantity > 0 AND Price > 0)
);

-- iii.	SQL Check on ALTER Table:
ALTER TABLE Employees ADD CONSTRAINT chk_age CHECK (Age >= 18);

-- iv.	Drop a CHECK Constraint:
ALTER TABLE Employees DROP CONSTRAINT chk_age;

-- 6. SQL Index

-- a. Create index
CREATE INDEX idx_employee_name ON Employees(Name);

-- b. Drop index
DROP INDEX idx_employee_name ON Employees;

-- 7. Auto Increment Field
CREATE TABLE Employees (
    EmployeeID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(100)
);

-- 8. Insert Query
INSERT INTO Employees (Name) VALUES ('Alice');

-- 9. Update Table
UPDATE Employees SET Name = 'Bob' WHERE EmployeeID = 1;
select * from Employees;

-- 10. SQL Delete
DELETE FROM Employees WHERE Name = 'Alice';

-- 11. SQL truncate table
TRUNCATE TABLE Employees;

-- 12. DROP table
DROP TABLE Employees;
