
<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Lista 6 - zadania 2-8</title>
          <script>
        window.onload = function(){   
        
             function listCookies() {
                var theCookies = document.cookie.split(';');
                var aString = '';
                for (var i = 1 ; i <= theCookies.length; i++) {
                    aString += i + ' ' + theCookies[i-1] + "\n";
                }
                return aString;
              }
        var ciastka = document.getElementById("ciastka");
        ciastka.textContent = listCookies();
    
    }
    
       
        
        </script>
    </head>
    <body>
        <?php
        setcookie("TestCookie1", 'test1');
        setcookie("TestCookie2", 'test2');
        setcookie("TestCookie3", 'test3', NULL, NULL, NULL, NULL, TRUE)
?>
        
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
            Select file to upload:
            <input type="file" name="fileToUpload" id="fileToUpload">
            <input type="submit" value="Upload File" name="submit">
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
        <hr style="height: 3px;">
        <h1>Zadanie 7 </h1>
        <?php
        foreach ($_COOKIE as $key=>$val)
          {
            echo $key.' is '.$val."<br>\n";
          }
        ?>
        
        <!-- oSession.oRequest["Cookie"] = (oSession.oRequest["Cookie"] + ";YourCookieName=YourCookieValue");  ctrl+R ; go to OnBeforeRequest-->
        <hr style="height: 3px;">
        <h1>Zadanie 8</h1>
        <span id="ciastka"></span>
        
        <hr style="height: 3px;">

        
        

        
    </body>
</html>   

