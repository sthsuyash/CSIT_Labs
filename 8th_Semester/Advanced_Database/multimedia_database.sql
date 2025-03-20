-- Step 1: Create Database and Tables

CREATE DATABASE IF NOT EXISTS multimedia_database;
USE multimedia_database;

CREATE TABLE IF NOT EXISTS images (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    image_data LONGBLOB
);

CREATE TABLE IF NOT EXISTS audio (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    audio_data LONGBLOB
);

CREATE TABLE IF NOT EXISTS videos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    video_data LONGBLOB
);

-- Step 2: Insert media files

-- 1. Insert an image
INSERT INTO images (name, image_data) VALUES ('Photo 1', LOAD_FILE('/Path/to/photo'));

-- Insert an audio file
INSERT INTO audio (name, audio_data) VALUES ('Audio 1', LOAD_FILE('/Path/to/audio'));

-- Insert a video file
INSERT INTO videos (name, video_data) VALUES ('Video 1', LOAD_FILE('/Path/to/video'));

Step 3: Retrieve media files
-- Retrieve an image
SELECT image_data FROM images WHERE id = 1;

-- Retrieve an audio file
SELECT audio_data FROM audio WHERE id = 1;

-- Retrieve a video file
SELECT video_data FROM videos WHERE id = 1;

