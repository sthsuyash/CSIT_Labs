<?php
$filename = "example.txt";

// Read content from file
$content = file_get_contents($filename);

// Modify content
$newContent = str_replace("old_text", "new_text", $content);

// Write updated content back to file
file_put_contents($filename, $newContent);

echo "File updated successfully";
?>