<?php
function calculateAverage($numbers)
{
    return array_sum($numbers) / count($numbers);
}

$testArray = [5, 10, 15];
echo calculateAverage($testArray);
?>