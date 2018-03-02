<?php

$howmanywords = $_SERVER['argc'];
for($i = 1; $i< $howmanywords ; $i++){
    $word = $_SERVER['argv'][$i];

    if(strlen($word) % 2 == 1){
        for($j=1; $j <= strlen($word); $j+=2){
            $howmanyspaces = (strlen($word)- $j)/2;
            for($temp=0; $temp <= $howmanyspaces; $temp++){echo " ";};
            echo substr($word, $howmanyspaces, $j) . PHP_EOL;
        }

        for ($j= strlen($word)-2; $j>=0 ; $j-= 2){
            $howmanyspaces = (strlen($word)- $j)/2;
            for($temp=0; $temp <= $howmanyspaces; $temp++){echo " ";};
            echo substr($word, $howmanyspaces, $j) . PHP_EOL;
        }

    }

    else{
        for($j=0; $j <= strlen($word); $j+=2){
            $howmanyspaces = (strlen($word)- $j)/2;
            for($temp=0; $temp <= $howmanyspaces; $temp++){echo " ";};
            echo substr($word, $howmanyspaces, $j) . PHP_EOL;
        }

        for ($j= strlen($word)-2; $j>=0 ; $j-= 2){
            $howmanyspaces = (strlen($word)- $j)/2;
            for($temp=0; $temp <= $howmanyspaces; $temp++){echo " ";};
            echo substr($word, $howmanyspaces, $j) . PHP_EOL;
        }


    }
    echo PHP_EOL;
}
?>