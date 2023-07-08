-- Create Database
CREATE DATABASE db_lab2;

-- Use Database
USE db_lab2;

-- Create table emp with necessary columns
CREATE TABLE emp (
    empno INT PRIMARY KEY,
    ename VARCHAR(10),
    job VARCHAR(9),
    mgr INT NULL,
    hiredate DATETIME,
    sal NUMERIC(7, 2),
    comm NUMERIC(7, 2) NULL,
    dept INT
);

-- Insert values in the table
INSERT INTO emp
VALUES
(1, 'JOHNSON', 'ADMIN', 6, '12-17-1990', 18000, NULL, 4),
(2, 'HARDING', 'MANAGER', 9, '02-02-1998', 52000, 300, 3),
(3, 'TAFT', 'SALES I', 2, '01-02-1996', 25000, 500, 3),
(4, 'HOOVER', 'SALES I', 2, '04-02-1990', 27000, NULL, 3),
(5, 'LINCOLN', 'TECH', 6, '06-23-1994', 22500, 1400, 4),
(6, 'GARFIELD', 'MANAGER', 9, '05-01-1993', 54000, NULL, 4),
(7, 'POLK', 'TECH', 6, '09-22-1997', 25000, NULL, 4),
(8, 'GRANT', 'ENGINEER', 10, '03-30-1997', 32000, NULL, 2),
(9, 'JACKSON', 'CEO', NULL, '01-01-1990', 75000, NULL, 4),
(10, 'FILLMORE', 'MANAGER', 9, '08-09-1994', 56000, NULL, 2),
(11, 'ADAMS', 'ENGINEER', 10, '03-15-1996', 34000, NULL, 2),
(12, 'WASHINGTON', 'ADMIN', 6, '04-16-1998', 18000, NULL, 4),
(13, 'MONROE', 'ENGINEER', 10, '12-03-2000', 30000, NULL, 2),
(14, 'ROOSEVELT', 'CPA', 9, '10-12-1995', 35000, NULL, 1);

-----------------------------------------------------------------

-- Create table dept
CREATE TABLE dept (
    deptno INT NOT NULL,
    dname VARCHAR(14),
    loc VARCHAR(13)
);

-- Insert value into dept table
INSERT INTO dept
VALUES
(1, 'ACCOUNTING', 'ST LOUIS'),
(2, 'RESEARCH', 'NEW YORK'),
(3, 'SALES', 'ATLANTA'),
(4, 'OPERATIONS', 'SEATTLE');

-------------------------------------------------------------------------------------

-- Display all the tables
SELECT * FROM emp;
SELECT * FROM dept;

------------------------------------------------------------------------------------

-- Rename Table Name
-- exec sp_rename 'Old_Name','New_Name';

-- Rename Column name
exec sp_rename 'emp.mgr', 'manager';

exec sp_rename 'emp.dept', 'deptno';

-- Alter datatype
ALTER TABLE emp
ALTER COLUMN hiredate date;

-- add constraint to existing columns
ALTER TABLE emp 
ADD constraint pk PRIMARY KEY (empno);

ALTER TABLE emp 
ADD constraint uk UNIQUE (empno);

-- drop constraint from existing columns
ALTER TABLE emp
DROP uk;

-- add new column
ALTER TABLE emp 
ADD sn INT identity;

-- Identity is used for auto increment
-- drop column
ALTER TABLE emp 
DROP COLUMN sn;

-------------------------------------------------------------------------------------

-- update data
UPDATE emp SET comm = 0 WHERE comm is null;

UPDATE emp SET job = 'manager'
WHERE emp.deptno = 4;

-------------------------------------------------------------------------------------
-- Delete row
DELETE FROM emp WHERE empno = 1;

-- Delete multiple rows at once
-- This will delete empno 2,3 and 5
DELETE FROM emp WHERE empno in (2, 3, 5);

-------------------------------------------------------------------------------------
-- Retrival Queries--
-- Q1) Display the detail of all employees
SELECT * FROM emp;

-- Q2) Display the detail of department
SELECT * FROM dept;

-- Q3) Display the name and job for all employees
SELECT
    ename as Employee_Name,
    job as Designation
FROM emp;

-- Q4) Display the name, salary and commision of all emplyees
SELECT
    ename as Employee_Name,
    sal as Salary,
    comm as Commission
FROM emp;

-- Q5) Display name and total salary (salary+commission) of all the employees
SELECT
    ename as Employee_Name,
    sal + comm as Total_Salary
FROM emp;

-- Q6) Display the name and annual salary of all the emplyees
SELECT
    ename as Employee_Name,
    sal * 12 as Annual_Salary
FROM emp;

-- Q7) Display the name of all employees who are working in department number 4
SELECT ename as Employee_Name
FROM emp WHERE deptno = 4;

-- Q8) Display the name of all employees who is working as engineer and getting salary more than 30k
SELECT ename as Employee_Name
FROM emp WHERE job = 'engineer' AND sal > 30000;

-- Q9) Display employee number and name who are earnig commision
SELECT
    empno as Employee_No,
    ename as Employee_Name
FROM  emp WHERE comm != 0;

-- Q10) Display employee number and name who are not earnig commision
SELECT
    empno as Employee_No,
    ename as Employee_Name
FROM emp WHERE comm = 0;

--  Q11) Display the names of employees who are working as tech, manager, or sales I and drawing a salary of more than 30000.
SELECT ename as Employee_Name
FROM emp
WHERE
    job = 'tech'
    OR job = 'manager'
    OR job = 'sales I'
    AND sal > 30000;

-- Q12) display the name of employee who is working in company more than 25 years
SELECT ename as Employee_Name FROM emp 
WHERE DATEDIFF (YEAR, hiredate, GETDATE ()) > 25;

-- Q13) Display the list of employees who have joined the company before 30-JUN -92 Or after 31 - DEC -95.
SELECT ename as Employee_Name FROM emp
WHERE
    hiredate < '30-JUN-1992'
    OR hiredate > '31-DEC-1995';

-- Q14) Display the names of employees working in depart number 1 or 2 or 4 and employees working as Manager, Salesman, or engineer.
SELECT ename FROM emp
WHERE
    deptno IN (1, 2, 4)
    AND job IN ('manager', 'sales I', 'engineer');

-- Q15) Display the names of employees whose name starts with alphabet H.
SELECT ename FROM emp WHERE ename like 'H%';

-- Q16) Display the names of employees whose name ends with alphabet N.
SELECT ename FROM emp WHERE ename like '%N';

-- Q17) Display the names of employees whose names have second alphabet A in their names.
SELECT ename FROM emp WHERE ename like '_A%';

-- Q18 SELECT the names of the employee whose names are exactly five characters in length.
SELECT ename FROM emp
WHERE LEN(ename) = 5;

-- Q19) Display the total number of employees working for the company.
SELECT count(ename) as Total_Employees FROM EMP;

--OR
SELECT count(*) as Total_Employees FROM EMP;

-- Q20) Display the total salary begging paid to all employees.
SELECT sum(sal) as Total_Salary FROM emp;

-- Q21) Display the maximum salary FROM emp table.
SELECT max(sal) Max_Salary FROM emp;

-- Q22) Display the minimum salary FROM emp table.
SELECT min(sal) as Min_Salary FROM emp;

-- Q23) Display the average salary FROM emp table.
SELECT avg(sal) Average_Salary FROM emp;

-- Q24) Display the maximum salary being paid to the engineer.
SELECT max(sal) as Max_Salary_to_Engineer
FROM emp WHERE job = 'engineer';

-- Q25) Display the total salary drawn by manager working in depart number 4.
SELECT sum(sal) as Tot_Salary FROM emp
WHERE
    job = 'manager'
    AND deptno = 4;

-- Q26) Display the name and salary of highest earning employee
SELECT
    ename as Employee_Name,
    sal as Highest_Salary
FROM emp
WHERE sal = (SELECT max(sal) FROM emp);

-- Q27) Display the name and salary of lowest earnig employee
SELECT
    ename as Employee_Name,
    sal as Highest_Salary
FROM emp 
WHERE sal = (SELECT min(sal) FROM emp );

-- Q28 Display the name and salary of the employee in order of salary, i.e.,
-- the name of the employee earning the highest salary should salary appear first.
SELECT 
    ename as Name,
    sal as Salary
FROM emp
ORDER BY sal DESC;

-- Q29) Display the name of the employee along with their annual salary (sal * 12).
-- The name of the employee earning the highest annual salary should appear first.
SELECT 
    ename as Name,
    sal * 12 as Annual_Salary
FROM emp
ORDER BY sal DESC;

-- Q30) Display name, salary, hra (House rent allowance), pf (Provident Fund),
-- da (Dearness Allowance), total salary for each employee.
-- The output should be in the order of total salary;
-- hra 15% of salary, da 10%of salary, pf 5%salary,
-- and total salary will be (salary+hra+da-pf).
SELECT 
    ename AS Name,
    sal AS Salary,
    sal / 100 * 15 AS hra,
    sal / 100 * 5 AS pf,
    sal / 100 * 10 AS da,
    sal + sal / 100 * 15 + sal / 100 * 10 - sal / 100 * 5 AS Total_Sal
FROM emp;

-- Q31) Display depart name and the total number of employees working in each department
SELECT
    dept.dname AS Department,
    count(ename) AS No_of_Employees
FROM emp
INNER JOIN dept ON emp.deptno = dept.deptno
GROUP BY dept.dname;

-------------------------------------------------------------------------

------ Join Queries -----
-- Create table Country and state
CREATE TABLE country (
    c_id int constraint cid_pk primary key identity,
    c_name varchar(20)
);

CREATE TABLE state (
    s_id int constraint sid_pk primary key identity,
    s_name varchar(20),
    c_id int references country (c_id)
);

INSERT INTO country (c_name)
VALUES 
('Nepal'), ('India'), ('China'), ('Bhutan'), ('Srilanka'), ('Pakistan')

INSERT INTO state (s_name, c_id)
VALUES 
('Bagmati', 1), ('Lumbini', 1), ('Karnali', 1), ('UP', 2), ('Bihar', 2), 
('Guangdong', 3), ('Toronto', null), ('Sydney', null), ('Kolkatta', null)

SELECT * FROM country;

SELECT * FROM state;

---------------------------------------------------------------------------------------

-----------------------Inner Join--------------------------
-- Q1) Display the name of the country and corresponding states
SELECT
    c.c_name as Country,
    s.s_name as State
FROM country c
INNER JOIN state s ON c.c_id = s.c_id;

-- OR we can use join instead of inner join
SELECT
    c.c_name as Country,
    s.s_name as State
FROM country c
JOIN state s ON c.c_id = s.c_id;

-- Q2) Display the name of country and their state whose id is 1
SELECT
    c.c_name as Country,
    s.s_name as State
FROM country c
JOIN state s ON c.c_id = s.c_id
WHERE c.c_id = 1;

--------------- Left and right join ------------------

-- Q1) Display all the country and their states. Also display the country name which doesn't have states
SELECT 
    c.c_name AS Country, 
    s.s_name AS State
FROM country c 
LEFT JOIN state s ON c.c_id=s.c_id;

-- Q2) Display all the state and their countries. Also display the states name which doesn't have country
SELECT
    c.c_name AS Country,
    s.s_name AS State
FROM country c
RIGHT JOIN state s ON c.c_id = s.c_id;

-----------------Outer Join----------------------
-- Q1) Display all the name of country and states
SELECT
    c.c_name AS Country,
    s.s_name AS State
FROM country c
FULL OUTER JOIN state s ON c.c_id = s.c_id;

-----------------------------------------------------------------

------------------- Views ---------------
-- Q1) Create a view as employee_detail of table emp
CREATE VIEW employee_detail AS
SELECT ename, job, sal, comm FROM emp;

-- Display the data of views
SELECT * FROM employee_detail;

-- Q1) Display name and salary from the view
SELECT ename, sal FROM employee_detail;

-- Q2) Display total earning of each employee
SELECT
    ename AS Name,
    sal + comm AS Total_Earning
FROM employee_detail;

-- Q3) Display the total salary paid to manager
SELECT sum(sal) AS Total_Amount 
FROM employee_detail WHERE job = 'manager';

------------- Update View -------------------
-- Change the view properties
CREATE OR ALTER VIEW employee_detail AS
SELECT
    ename AS Name,
    job AS Position,
    sal + comm AS Total_Salary
FROM emp;

SELECT * FROM employee_detail;

------------ Drop View -------------
DROP view employee_detail;

SELECT * FROM employee_detail;