CREATE DATABASE office;

USE office;

-- DEPARTMENT Table
CREATE TABLE DEPARTMENT (
    Number INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(50) UNIQUE NOT NULL,
    Locations VARCHAR(255) NOT NULL
);

-- PROJECT Table
CREATE TABLE PROJECT (
    Number INT PRIMARY KEY AUTO_INCREMENT,
    Name VARCHAR(50) UNIQUE NOT NULL,
    Location VARCHAR(255) NOT NULL
);

-- EMPLOYEE Table
CREATE TABLE EMPLOYEE (
    Ssn CHAR(9) PRIMARY KEY,
    Fname VARCHAR(50) NOT NULL,
    Minit CHAR(1),
    Lname VARCHAR(50) NOT NULL,
    Bdate DATE NOT NULL,
    Address VARCHAR(255) NOT NULL,
    Salary DECIMAL(10,2) CHECK (Salary > 0),
    Sex CHAR(1) CHECK (Sex IN ('M', 'F')),
    Dno INT NOT NULL,  -- Foreign key for Department
    Super_ssn CHAR(9),  -- Foreign key for Supervision
    CONSTRAINT fk_emp_dept FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Number) ON DELETE CASCADE,
    CONSTRAINT fk_emp_supervisor FOREIGN KEY (Super_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE SET NULL,
    INDEX idx_emp_name (Lname, Fname) -- Index for faster searches
);

-- WORKS_FOR Relationship (Employee works for a Department)
CREATE TABLE WORKS_FOR (
    Ssn CHAR(9),
    Dno INT,
    Start_date DATE NOT NULL,
    Number_of_employees INT CHECK (Number_of_employees >= 0),
    PRIMARY KEY (Ssn, Dno),
    CONSTRAINT fk_worksfor_emp FOREIGN KEY (Ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE,
    CONSTRAINT fk_worksfor_dept FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Number) ON DELETE CASCADE
);

-- MANAGES Relationship (Employee manages a Department)
CREATE TABLE MANAGES (
    Ssn CHAR(9),
    Dno INT UNIQUE, -- One department can have only one manager
    Start_date DATE NOT NULL,
    PRIMARY KEY (Ssn, Dno),
    CONSTRAINT fk_manages_emp FOREIGN KEY (Ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE,
    CONSTRAINT fk_manages_dept FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Number) ON DELETE CASCADE
);

-- WORKS_ON Relationship (Employee works on a Project)
CREATE TABLE WORKS_ON (
    Ssn CHAR(9),
    Pno INT,
    Hours DECIMAL(5,2) CHECK (Hours >= 0),
    PRIMARY KEY (Ssn, Pno),
    CONSTRAINT fk_workson_emp FOREIGN KEY (Ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE,
    CONSTRAINT fk_workson_proj FOREIGN KEY (Pno) REFERENCES PROJECT(Number) ON DELETE CASCADE
);

-- CONTROLS Relationship (Department controls a Project)
CREATE TABLE CONTROLS (
    Dno INT,
    Pno INT,
    PRIMARY KEY (Dno, Pno),
    CONSTRAINT fk_controls_dept FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Number) ON DELETE CASCADE,
    CONSTRAINT fk_controls_proj FOREIGN KEY (Pno) REFERENCES PROJECT(Number) ON DELETE CASCADE
);

-- SUPERVISION Relationship (Self-referencing Employee Supervision)
CREATE TABLE SUPERVISION (
    Supervisor CHAR(9),
    Supervisee CHAR(9),
    PRIMARY KEY (Supervisor, Supervisee),
    CONSTRAINT fk_supervision_supervisor FOREIGN KEY (Supervisor) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE,
    CONSTRAINT fk_supervision_supervisee FOREIGN KEY (Supervisee) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE
);

-- DEPENDENT Table (Stores dependents of Employees)
CREATE TABLE DEPENDENT (
    Dependent_ID INT PRIMARY KEY AUTO_INCREMENT,
    Employee_Ssn CHAR(9) NOT NULL,
    Name VARCHAR(50) NOT NULL,
    Sex CHAR(1) CHECK (Sex IN ('M', 'F')),
    Birth_date DATE NOT NULL,
    Relationship VARCHAR(50) NOT NULL,
    CONSTRAINT fk_dependent_emp FOREIGN KEY (Employee_Ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE
);
