CREATE DATABASE active_database;

USE active_database;

-- Step 1:
CREATE TABLE main_table (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    active BOOLEAN DEFAULT TRUE
);

CREATE TABLE active_table (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    active BOOLEAN DEFAULT TRUE
);

-- Step 2: Define Trigger
DELIMITER //

CREATE TRIGGER update_active_flag 
AFTER UPDATE ON main_table
FOR EACH ROW
BEGIN
    IF OLD.active IS DISTINCT FROM NEW.active THEN
        UPDATE active_table
        SET active = NEW.active
        WHERE id = NEW.id;
    END IF;
END //

DELIMITER ;

-- Step 3: Insert Data and Update

-- Insert some data into the main_table
INSERT INTO main_table (name) VALUES ('Item 1'), ('Item 2');
-- Insert corresponding data into the active_table
INSERT INTO active_table (name) VALUES ('Item 1'), ('Item 2');

-- Update the active flag in main_table
UPDATE main_table SET active = FALSE WHERE id = 1;

-- Step 4: View Data
SELECT * FROM main_table;
SELECT * FROM active_table;

-- Step 5: Clean Up (Drop the tables)
DROP TABLE IF EXISTS main_table;
DROP TABLE IF EXISTS active_table;
