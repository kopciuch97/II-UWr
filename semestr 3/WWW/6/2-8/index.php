
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Lista 6 - zadania 2-8</title>
    </head>
    <body>
        <!--Zadanie 2-->
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
        //POST
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
        <?php
        echo "<pre>";
        echo var_dump($_FILES['file']);
        echo '</pre>'
        ?>
        <hr>
        <br><br>
        
        <?php 
        if(!empty($_SERVER)){
            foreach ($_SERVER as $key => $value) {
                echo "<li>$key : $value</li>";
            }     
        }
        ?>
        <hr style="height: 3px;">
        <!--Zadanie 2-->

        
    </body>
</html>   

