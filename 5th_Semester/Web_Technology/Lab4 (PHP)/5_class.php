<?php
class Book
{
    public $title;
    public $author;
}

$book1 = new Book();
$book1->title = "The Great Gatsby";
$book1->author = "F. Scott Fitzgerald";

echo $book1->title . " by " . $book1->author;
?>