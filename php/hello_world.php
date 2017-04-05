<?php
    echo "hello world!<br/>";
    
    $name = 'have a look here!';
    echo "$name";
    echo "<br/>";
    
    $youtube = 'youtube';
    echo 'it is a link to ' . $youtube;
    echo "<br/>";
    
    printf('<a href="https://www.youtube.com">%s</a>', $youtube);
    echo "<br/>";
    
    $a = [1, 2, 3, 4];
    
    for($i=0; $i<4; $i++){
       echo $a[$i]; 
       echo "<br/>";
    }
    
    
?>