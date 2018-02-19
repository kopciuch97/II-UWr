window.onload = function load(){
	document.getElementById('form').onsubmit = checkForm;
	document.getElementById('mail').onblur= mailCheck;
	document.getElementById('nr').onblur= nrCheck;
	document.getElementById('pesel').onblur= peselCheck;
	document.getElementById('date').onblur= dateCheck;
} 

function checkForm(){
  var error = false;
  if (!peselCheck()){
    error = true;
  }
  if (!mailCheck()){
    error = true;
  }
  if (!dateCheck()){
    error = true;
  }
  if (!nrCheck()){
    error = true;
  }
  alert('Bledne dane');
  if (error){
    return false;
  }
	alert('Dane wyslane');
    return true;
}

function peselCheck() {
	var pesel=document.getElementById('pesel');
  var regex = /[0-9]{11}/;
  if (regex.test(pesel.value) == false) {
    pesel.style.border = "1px solid #FF0000";
    return false;
  }
  pesel.style.border = "1px solid #00E600";
}
        
function dateCheck(){
  var date=document.getElementById('date');
  var regex= /^\d{4}\-(0?[1-9]|1[012])\-(0?[1-9]|[12][0-9]|3[01])$/; //
  if(regex.test(date.value) == false){
    date.style.border = "1px solid #FF0000";
    return false;
  }
  date.style.border = "1px solid #00E600";
}
        
function mailCheck() {
	var mail=document.getElementById('mail');
  var regex = /^[0-9a-zA-Z_.-]+@[0-9a-zA-Z.-]+\.[a-zA-Z]{2,3}$/;
  if(regex.test(mail.value) == false){
    mail.style.border = "1px solid #FF0000";
    return false;
  }
  mail.style.border = "1px solid #00E600";
}
function nrCheck(nr) {
	var nr=document.getElementById('nr');
  var regex = /[0-9]{26}/;
  if(regex.test(nr.value) == false){
    nr.style.border = "1px solid #FF0000";
    return false;
  }
  nr.style.border = "1px solid #00E600";
}