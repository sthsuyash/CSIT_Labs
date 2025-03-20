-- Step 1: Create Database and Tables
CREATE DATABASE IF NOT EXISTS suyash_deductive_database;

USE suyash_deductive_database;

-- Create the tables with a composite unique key on (ancestor, descendant)
CREATE TABLE IF NOT EXISTS parents (
    parent VARCHAR(255),
    child VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS ancestors (
    ancestor VARCHAR(255),
    descendant VARCHAR(255),
    UNIQUE KEY unique_ancestor_descendant (ancestor, descendant)  -- Add composite unique key
);

-- Step 2: Insert data
INSERT INTO parents (parent, child) VALUES
    ('John', 'Alice'),
    ('Alice', 'Bob'),
    ('Bob', 'Charlie');

-- View the data
SELECT * FROM parents;

-- Step 3: Stored Procedure
DELIMITER &&

CREATE PROCEDURE populate_ancestors()
BEGIN
    DECLARE rows_inserted INT DEFAULT 0;

    -- Step 1: Clear the ancestors table
    TRUNCATE TABLE ancestors;

    -- Step 2: Insert direct parent-child relationships
    INSERT INTO ancestors (ancestor, descendant)
    SELECT parent, child FROM parents;

    SET rows_inserted = ROW_COUNT(); -- Track rows inserted

    -- Step 3: Iteratively insert indirect ancestors
    label: REPEAT
        -- Insert new ancestor-descendant relationships by joining existing ancestors with parents
        INSERT INTO ancestors (ancestor, descendant)
        SELECT a.ancestor, p.child
        FROM ancestors a
        JOIN parents p ON a.descendant = p.parent
        ON DUPLICATE KEY UPDATE ancestor = a.ancestor; -- Specify only the ancestor column

        SET rows_inserted = ROW_COUNT(); -- Get number of rows inserted

    UNTIL rows_inserted = 0 -- Stop when no new rows are inserted
    END REPEAT label;

END&&

DELIMITER ;

-- Call the procedure
CALL populate_ancestors();

SELECT * FROM ancestors;
