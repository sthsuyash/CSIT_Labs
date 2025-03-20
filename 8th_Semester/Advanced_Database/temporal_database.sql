-- Create a new database.
CREATE DATABASE IF NOT EXISTS suyash_temporal_database;

-- Use the created database
USE suyash_temporal_database;

-- Create Table
CREATE TABLE ss_table (
    id INT AUTO_INCREMENT PRIMARY KEY,
    data VARCHAR(255),
    valid_from TIMESTAMP(6) GENERATED ALWAYS AS ROW START,
    valid_to TIMESTAMP(6) GENERATED ALWAYS AS ROW END,
    PERIOD FOR SYSTEM_TIME (valid_from, valid_to)
) WITH SYSTEM VERSIONING;

-- Insert data
INSERT INTO ss_table (data) VALUES ('Data 1');
INSERT INTO ss_table (data) VALUES ('Data 2');

-- Get data
SELECT * FROM ss_table;

-- Update data
UPDATE ss_table SET data = 'Updated Data' WHERE id = 1;

-- Delete data
DELETE FROM ss_table WHERE id = 2;

-- View historical data
SELECT * FROM ss_table FOR SYSTEM_TIME ALL;

-- Drop the database
DROP DATABASE IF EXISTS suyash_temporal_database;