<!-- Write a function that takes two arguements array and search value -->
<!-- Your function should return "Yay, the value is in the array" if the search value is in the array, else it should return "Oh, no! Bad hit" -->

<?php
function search($array, $search_value){
    // if(in_array($search_value, $array)){
    //     return "Yay, the value is in the array";
    // }else{
    //     return "Oh, no! Bad hit";
    //
    foreach($array as $value){
        if($value === $search_value){
            return "Yay, the value is in the array";
        }
    }
    return "Oh, no! Bad hit";
}

$array = [1,2,3,4,5,6,7,8,9,10];

echo search($array, 10);
echo "<br>";
echo search($array, 11);
echo "<br>";
echo search($array, 'q');
?>

<?php
function searchKey($array, $search_value){
    // foreach($array as $key => $value){
    //     if($key === $search_value){
    //         return "Yay, the value is in the array";
    //     }
    // }
    // return "Oh, no! Bad hit";
    if (array_key_exists($search_value, $array)){
        return "Yay, the value is in the array";
    }
    else{
        return "Oh, no! Bad hit";
    }
}


$array = ['p'=>'pen', 'b'=>'book', 'c'=>'chair', 'd'=>'desk'];
echo "<br>";
echo searchKey($array, 'p');
echo "<br>";
echo "$array[c]"
?>