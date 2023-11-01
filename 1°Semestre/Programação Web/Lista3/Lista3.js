
function Exerc1(inicio, final){

    var resultado = 0;

    for(var i = parseInt(inicio) + 1; i<final; i++){
        resultado = i*i;
        alert(resultado);
    }

}

function Exerc2(){

    var resultado = 0;

    for(var i = 0; i <= 500; i += 2){
        resultado += i;  

    }
    alert("A soma dos números pares entre 1 e 500 é: " +resultado );  
}

function Exerc3(){
    var resultado = 0;
    var i = 0;

    while(i<=500){
        resultado += i;
        i+= 2;
    }
    alert("A soma dos números pares entre 1 e 500 é: " +resultado );
    
}

function Exerc4(fatorial){

    var numero = fatorial;

    for(var i = fatorial-1; i >= 1; i--){
        fatorial = fatorial*i;
        console.log(fatorial); 
    }

    alert("O fatorial do numero indicado, " +numero +", é: " +fatorial);


}

function Exerc5(fatorial){

    var numero = fatorial;
    var i = fatorial-1;

    do{
        fatorial = fatorial*i;
        console.log(fatorial);
        i--;

    }while(i >=1);

    alert("O fatorial do numero indicado, " +numero +", é: " +fatorial);


}