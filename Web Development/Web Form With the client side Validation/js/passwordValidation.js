
var err;
let retValue = true;
let form;
function validation(){
{
    let inputs = document.querySelectorAll('input');
    retValue = true;
    err = 0;
    form = document.forms["Main"]
    clearErrors();
    validatePassword();
    validateRePassword();
    validateStreet();
    validatePhoneNumber();
    validatePostalCode();
    if (err !== 0) {
        return false;   
    }
    // debugger;
    // var form = document.forms["Main"];
    // let pass = form.pass.value.trim();
    // let pass1 = form.pass1.value.trim();
    // let err = document.querySelector('#errors');
    // let disp_errors = 0;
    // if(pass.length < 8 && disp_errors < 8){
    //     err.innerHTML += "<p>* The Password's length must be more than 7</p>";
    //     form.pass.focus();
    //     disp_errors++;
    // }
    
    // let uppercase = 0;
    // let digit = 0;
    // for (let i = 0; i < pass.length; i++) {
    //     if (pass.charAt(i) >= "A" || pass.charAt(i) <= "Z") {
    //         uppercase++;
    //     }
    //     if (pass.charAt(i) >= "1" || pass.charAt(i) <= "9") {
    //         digit++;
    //     }
    // }
    // if ((uppercase === 0 || digit === 0) && disp_errors < 8) {
    //     disp_errors++;
    //     err.innerHTML += "<p>* The Password's must contain's atleast 1 digit and alteast 1 UPPER CASE letter</p>";
    // }
    // let passU = pass.toUpperCase();
    // let pass1U = pass1.toUpperCase();
    // if (passU !== pass1U && disp_errors < 8) {
    //     disp_errors++;
    //     err.innerHTML += "<p>* The Re-Password not matches the password</p>";
    // }
    // if((passU.charAt(i) > "A" || passU.charAt(i) < "Z") && disp_errors < 8){

    //     err.innerHTML += "<p> * The Password must start with an character </p>";
    //     disp_errors++;
    // }
}

}
function clearErrors(){
         let err = document.querySelector('#errors');
         err.innerHTML = "";
     }
function showError(message){
    if (err < 8) {
    let errMessage = document.querySelector('#errors');
         errMessage.innerHTML += "<p>" + message + "</p>";
         err++;
    }
}     
// let form;
// let pass;
// let err;
// let dis_errors = 0;
// window.onload = function(){
//     debugger;
//     form = document.forms["Main"];
//     err = document.querySelector('#errors');
//     clearErrors();
//     pass = form.pass;
//     // Writing eventlistener for password
//     pass.addEventListener("focusout", validatePassword)

// }

// function clearErrors(){
//     let err = document.querySelector('#errors');
//     err.innerHTML = "";
// }
// function validatePassword() {
//     clearErrors();
//     let value = form.pass.value.trim();
//     if (value[0].toUpperCase() < "A" || value[0].toUpperCase() > "Z") {
//         pass
//         err.innerHTML = "<p> THe password must start with a character</p>"
//         return false;
//     }
// }
function validatePassword() {
    var errors = document.querySelector("#errors");
    var digit = 0;
    var uppercase = 0;
    var elem = document.getElementById("pass");
    var inputValue = elem.value.trim();
    if (inputValue.length == 0 && err < 8) {      /* check the length */
       errors.innerHTML += "<p><mark>Password</mark><br />*The Password must Have Length Of 8 Character.</p>";
       err++;
    }    
    for (var i = 0; i < inputValue.length; i++) {
         // check all character are letters
         if (inputValue.charAt(i) >= "A" && inputValue.charAt(i) <= "Z" )  { uppercase++ }
         if (inputValue.charAt(i) >= "1" && inputValue.charAt(i) <= "9" )  { digit++ }
    }  // for
    if ((digit == 0 || uppercase == 0) && err < 8){
       errors.innerHTML += "<p><mark>Password</mark><br />* Password must have 1 digit and must have atleast 1 upper case character</p>";
       err++
    } /* else */
 }
 function validateRePassword(){
    var pass= document.getElementById("pass").value;
    var pass1= document.getElementById("pass1").value;
    if (pass !== pass1) {
        showError("<mark>Re-password</mark><br />* must match with the Password");
    }
 }

 function validateStreet(){
   let street = document.querySelector("#address").value;
   street = street.toUpperCase();
   for (let i = 0; i < street.length; i++) {
        if (street[i] < 65 || street[i] > 90) {
            showError(" <mark>Street</mark><br />* The Street name Must not contain the digit")
            return;
        }
   }
 }



 // Validation Phone Number
 function validatePhoneNumber() {

    // this can be done in a best way using pattern 
    // which is pattern = "(\(?\d{3}\)?[- ]?)?\d{3}-?\d{4}";
    // the best way
    var messageRules="<p> - Please enter a phone number with the format of ###-###-####.</p>";

    var str = form.tel.value;
    str = str.trim();

    var stringLength = str.length;

    if (stringLength == 0) { 
        showError("<mark>Phone Number</mark><br /> - The phone number field can not be left empty or just blank characters<br />" + messageRules);
    }  

    if (str.charAt(3) !== '-' || str.charAt(7) !== '-' || stringLength !== 12) {
        showError("<mark>Phone Number</mark><br />" + messageRules);
    }  
    else { 
        var i, flag = true, myArray = str.split('-');
        for (i = 0; i <3; i++) {
           if (parseInt(myArray[i]) != myArray[i]) {
              flag = false;
              break;
           }
        }
        
        if (!flag) {
           showError("<mark>Phone Number</mark><br /> - The phone number was in wrong format.<br />" + messageRules);
        }
    }
  }

  function validatePostalCode(){
    let postal = form.Code.value;
    var messageRules="- Please enter a Postal Code with the format of A1A1A1.";
    postal = postal.trim();
    let len = postal.length;
    if (len !== 6 || !ischar(postal[0]) || !isdigit(postal[1]) || !ischar(postal[2]) || !isdigit(postal[3]) || !ischar(postal[4]) || !isdigit(postal[5])) {
        showError("<mark>Postal-code</mark><br>" + messageRules);
    }
  }
  function ischar(char){
    char = char.toUpperCase();
    if (char < "A" || char > "Z") {
        return false;
    }
    return true;
  }

  function isdigit(dig){
    if (dig < "1" || dig > "9") {
        return false;
    }
    return true;
  }