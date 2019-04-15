const button = document.querySelector('button');
document.getElementById('key_div').style.visibility = "hidden";


rxjs.fromEvent(button, 'click').subscribe(() => {
    let input = document.getElementById('input').value.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
    let cipher = document.getElementById('cipher').value;
    let decode = document.getElementById('decode').checked;
    let rot = document.getElementById('rot').value;
    let key = document.getElementById('key').value;
    console.log(input);

    let rotation = decode ? 26 - rot : rot;
    let name = (cipher != 'vigenere') ? cipher :  decode ? 'vigenere_decoder' : 'vigenere_encoder';
    let types, args;
    if (cipher == 'vigenere') {
      types = ['string', 'string'];
      args = [input.toUpperCase(), key.toUpperCase()];
    }
    if (cipher == 'caesar') {
      types = ['string', 'number', 'number'] ;
      args = [input, input.length, rotation];
    }
    if (cipher == 'morse_encode') {
      types = ['string'] ;
      args = [input];
    }
    let result = Module.ccall(
        name,	// name of C function
        'string',	// return type
        types,	// argument types
        args	// arguments
    );
    document.getElementById('output').innerHTML = result;
});

rxjs.fromEvent(cipher, 'click').subscribe(() => {
    let code = document.getElementById('cipher').value;
    if (code == 'vigenere') {
      document.getElementById('key_div').style.visibility = "visible";
      document.getElementById('rot_div').style.visibility = "hidden";
      document.getElementById('decode_div').style.visibility = "visible";
    }
    if (code == 'caesar') {
      document.getElementById('rot_div').style.visibility = "visible";
      document.getElementById('key_div').style.visibility = "hidden";
      document.getElementById('decode_div').style.visibility = "visible";
    }
    if (code == 'morse_encode') {
      document.getElementById('rot_div').style.visibility = "hidden";
      document.getElementById('key_div').style.visibility = "hidden";
      document.getElementById('decode_div').style.visibility = "hidden";
      document.getElementById('encode').checked = "true";
    }
});
