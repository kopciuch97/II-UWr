
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Lista 6 - zadania 2-8</title>
    </head>
    <body>
        <!--Zadanie 2-->
        <h1>Zadanie2</h1>
        <ul>
        <?php
        //POST
         if(!empty($_POST)){
            foreach ($_POST as $key => $value) {
                echo "<li>$key : $value</li>";
            }     
        }       
   
        ?>
        </ul>
        
        
        <ul>
        <?php
        //GET
        if(!empty($_GET)){
            foreach ($_GET as $key => $value) {
                echo "<li>$key : $value</li>";
            }     
        }
        ?>
        </ul>
        
       
        <?php
        $_GET['get1'] = 'cosik';
        print_r($_REQUEST);
        ?>
        
        <br><br>
        <hr>
        <!-- ZADANIE 3 -->
        <h1>Zadanie 3</h1>        
        <form action="upload.php" method="post" enctype="multipart/form-data">
            Select image to upload:
            <input type="file" name="fileToUpload" id="fileToUpload">
            <input type="submit" value="Upload Image" name="submit">
        </form>
        <hr style="height: 3px;">
        <h1> Zadanie 4 </h1>
        <form action="form.php" method="POST">
            <label for="name">Imie:</label>
            <input type="text" name="name" id="name">
            <label for="surname">Nazwisko:</label>
            <input type="text" name ="surname" id="surname">
            <input type="submit">
        </form>

        
    </body>
</html>   

