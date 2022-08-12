var i = 0;
var txt1 = "HI, I'M"
var txt2 = 'HARSHIL PATEL'; /* The text */
var speed = 200; /* The speed/duration of the effect in milliseconds */

function typeWriter1() {
    if (i < txt1.length) {
      document.getElementById("first-part-of-name").innerHTML += txt1.charAt(i);
      i++;
      setTimeout(typeWriter1, speed);
    }
    else{
        i = 0;
        typeWriter2();
    }
  }

function typeWriter2() {
    
  if (i < txt2.length) {
    document.getElementById("typing-effect").innerHTML += txt2.charAt(i);
    i++;
    setTimeout(typeWriter2, speed);
  }
}

function validation(){
  if(validateTel()) {
    return true;
  } 
  return false;
  
}


function validateTel(){
  let tel = document.querySelector('#tel');
  let tel_value = tel.value;
  if (tel_value.length != 14 || tel_value[0] != '(' || tel_value[4] != ')' || tel_value[5] != ' ' || tel_value[9] != ' ') {
    tel.setCustomValidity("The Length of the Number Be 14 in '(###) ### ####' Format");
    tel.classList.add('border-red');
    return false;
  }
  else{
    tel.setCustomValidity("");
    tel.classList.remove('border-red');
    return true;
  }

}
function myFunction(){
  var x = document.getElementById("ham-main");
  if (x.style.display === "flex") {
    x.style.display = "none";
  } else {
    x.style.display = "flex";
  }
}