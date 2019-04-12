const button = document.querySelector('button');
const rot = document.getElementById('rot');


rxjs.fromEvent(button, 'click').subscribe(() => {
    let input = document.getElementById('input').value;
    let decode = document.getElementById('decode').checked;
    console.log(decode);
    let rot = document.getElementById('rot').value;
    console.log(rot);
    let rotation = decode ? 26 - rot : rot;
    let result = Module.ccall(
        'caesar',	// name of C function
        'string',	// return type
        ['string', 'number', 'number'],	// argument types
        [input, input.length, rotation]	// arguments
    );
    document.getElementById('output').innerHTML = result;
});