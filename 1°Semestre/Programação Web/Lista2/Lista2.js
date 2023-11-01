function Exerc1(valor1, valor2){

    if(valor1 > valor2) {
        resultado = parseInt(valor1 - valor2);
        alert("A diferença é: "+resultado);
    } else if( valor2 > valor1) {
        resultado = parseInt(valor2 - valor1);
        alert("A diferença é: "+resultado);
    } else {
        resultado = parseInt(valor2 - valor1);
        alert("A diferença é: "+resultado);
    }


}


function Exerc2(valorA, valorB, valorC, valorD){
    switch(valorA < valorB && valorB < valorC){
        case true:
            if(valorD <= valorA){
                alert("Ordem crescente: "+valorD+", " + valorA+", " + valorB+", " + valorC);
            }
            else if( (valorD > valorA) && (valorD <= valorB)){
                alert("Ordem crescente: "+valorA+", " + valorD+", " + valorB+", " + valorC);
            } 
            else if( (valorD > valorB) && (valorD <= valorC)){
                alert("Ordem crescente: "+valorA+", " + valorB+", " + valorD+", " + valorC);
            } 
            else{
                alert("Ordem crescente: "+valorA+", " + valorB+", " + valorC+", " + valorD);
            }
            break;
        case false:
            alert("Do valor A ao valor C não está em ordem crescente.")
            break;
    }
}



function Exerc3(codigo, salario){
    switch (codigo){

        case '1':
            percentual = parseFloat((salario*50)/100);
            novoSalario = parseFloat(salario)+parseFloat(percentual);
            alert("Seu cargo é Escrituário e seu novo salário é: "+novoSalario);
            break;

        case '2':
            percentual = parseFloat((salario*35)/100);
            novoSalario = parseFloat(salario)+parseFloat(percentual);
            alert("Seu cargo é Secretário e seu novo salário é: "+novoSalario);
            break;

        case '3':
            percentual = parseFloat((salario*20)/100);
            novoSalario = parseFloat(salario)+parseFloat(percentual);
            alert("Seu cargo é Caixa e seu novo salário é: "+novoSalario);
            break;

        case '4':
            percentual = parseFloat((salario*10)/100);
            novoSalario = parseFloat(salario)+parseFloat(percentual);
            alert("Seu cargo é Gerente e seu novo salário é: "+novoSalario);
            break;

        default:
            alert("Codigo errado, não há cargo");
            break;
        
    }

}

function Exerc4(nota1, nota2, nota3, nota4, nota5){
    media = (parseFloat(nota1)+parseFloat(nota2)+parseFloat(nota3)+parseFloat(nota4)+parseFloat(nota5))/5;

    if(media >= 6){
        alert("Sua média foi: "+media +". Você está aprovado!");
    }else{
        alert("Sua média foi: "+media +". Você foi reprovado.");
    }
}

function Exerc5(opcao){
    switch (opcao){

        case '1':
            alert("Cadastrar");
            break;

        case '2':
            alert("Alterar");
            break;

        case '3':
            alert("Excluir");
            break;

        case '4':
            alert("Pesquisar");
            break;

        default:
            alert("Opção não existente");
            break;
        
    }

}