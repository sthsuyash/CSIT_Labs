-- Create User
CREATE USER 'suyash'@'localhost' IDENTIFIED BY 'password';

-- View all users
SELECT User, Host FROM mysql.user;

-- Grant all privileges on all databases and tables
GRANT ALL PRIVILEGES ON *.* TO 'suyash'@'localhost';

-- Grant specific privilege on a table
GRANT CREATE ON office.EMPLOYEE TO 'suyash'@'localhost';

-- View permissions for the user
SHOW GRANTS FOR 'suyash'@'localhost';

-- Connect to User
-- First exit from the dbms, then in the command prompt:
-- mysql -u username -p: then type password

-- Remove permission
REVOKE CREATE ON *.* FROM 'suyash'@'localhost';

-- Check grants again
SHOW GRANTS FOR 'suyash'@'localhost';

-- Drop User
DROP USER 'suyash'@'localhost';

-- Check the users again
SELECT User, Host FROM mysql.user;