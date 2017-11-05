window.onload = function load(){
    function f(x) {
        document.getElementById("menu").style.borderColor = x;
    }
    
    document.getElementById("content").innerHTML+='<div id="menu"></div>';
    document.getElementById("menu").style.border='2px solid blue';    
    document.getElementById("menu").innerHTML+='<a href="#" onclick="f(`red`)">Czerwony</a><br>';
    document.getElementById("menu").innerHTML+='<a href="#" onclick="f(`brown`)">Brazowy</a><br>';
    document.getElementById("menu").innerHTML+='<a href="#" onclick="f(`black`)">Czarny</a><br>';
}

