var div = document.createElement('div');
div.id = 'menu';

var a1 = document.createElement('a');
a1.setAttribute('href','#');
a1.setAttribute('onclick',"f('green')");
a1.innerHTML = "Zielony";
var a2 = document.createElement('a');
a2.setAttribute('href','#');
a2.setAttribute('onclick',"f('brown')");
a2.innerHTML = "Brazowy";
var a3 = document.createElement('a');
a3.setAttribute('href','#');
a3.setAttribute('onclick',"f('yellow')");
a3.innerHTML = "Zolty";

function f(x) {document.getElementById("menu").style.borderColor =x;};

document.body.appendChild(div);

//document.getElementById('menu').appendChild(a1);
//document.getElementById('menu').appendChild(a2);
//document.getElementById('menu').appendChild(a3);




//a3.before(document.createElement('br'));
//a2.before(document.createElement('br'));