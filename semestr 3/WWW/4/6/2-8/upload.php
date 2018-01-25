<?php

$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
if(isset($_POST["submit"])) {
    $check = ($_FILES["fileToUpload"]["tmp_name"]);
    if($check !== false) {
        echo "File was uploaded correctly";
        $uploadOk = 1;
    } else {
        echo "Error while uploading";
    
        $uploadOk = 0;
    }
}

?>