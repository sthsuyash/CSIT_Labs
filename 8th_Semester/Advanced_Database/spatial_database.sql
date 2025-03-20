-- Step 1: Verify Spatial Extensions
SHOW VARIABLES LIKE 'have_%';

-- Step 2: Create the Database and Table
CREATE DATABASE IF NOT EXISTS spatial_database;
USE spatial_database;
CREATE TABLE locations (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    coordinates POINT
);

-- Step 3: Insert Spatial Data (POINT type stores latitude and longitude values)
INSERT INTO locations (name, coordinates) VALUES
    ('Location A', POINT(1.2345, 2.3456)),
    ('Location B', POINT(3.4567, 4.5678)),
    ('Location C', POINT(5.6789, 6.7890)
);

SELECT name 
FROM locations 
WHERE ST_DISTANCE(coordinates, POINT(1.0, 2.0)) < 1.0;

