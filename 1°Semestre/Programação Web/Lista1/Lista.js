function Exerc1(salario){
    //salario.getElementById()
    reajuste = parseFloat((salario*15)/100);
    salario = parseFloat(salario) + parseFloat(reajuste);
    alert("O seu salário com reajuste de 15% é igual a: " +salario); 
}

function Exerc2(graus){
    convertido = (9*graus+160)/5;
    alert("A temperatura convertida para Fahrenheit é: " +convertido +" °F");
}

function Exerc3(X, Y){
    var auxiliar;
    auxiliar = parseFloat(X);
    X = parseFloat(Y);
    Y = auxiliar;

    alert("O valor de X é: " +X +" e o valor de Y é: " +Y);
    
}

function Exerc4(comprimento, largura, altura){
    volume = comprimento*largura*altura;

    alert("O volume desse paralelepípedo é: " +volume);
}

function Exerc5(deposito){
    reajuste = parseFloat((deposito*1.3)/100);

    deposito = parseFloat(deposito) +  parseFloat(reajuste);

    alert("O valor após 1 mês de aplicação é: " +deposito);
}

function Exerc6(anoNascimento, anoAtual){
    idade = anoAtual - anoNascimento;

    idadeFuturo = idade + 17;

    alert("A idade atual é: " +idade + " e daqui 17 anos a idade será: " +idadeFuturo);
}

function Exerc7(horasTrabalhadas, valorHora, desconto, descendentes){
    salarioBruto = parseFloat(horasTrabalhadas) * parseFloat(valorHora);

    percentualDesconto = parseFloat((salarioBruto*desconto)/100);

    salarioLiquido = salarioBruto - percentualDesconto;

    acrescimoDescendente = parseFloat(descendentes) * 100;

    salarioFinal = salarioLiquido + acrescimoDescendente;

    alert("Seu salário será: " +salarioFinal);
}

function Exerc8(numero){
    divisaoPorDois = parseFloat(numero) / 2;
    divisaoPorTres = parseFloat(numero) / 3;
    divisaoPorQuatro = parseFloat(numero) / 4;
    divisaoPorCinco = parseFloat(numero) / 5;

    alert("O número " +numero+ " multiplicado por 2 é: " +divisaoPorDois+ ", multiplicado por 3 é: " +divisaoPorTres+ ", multiplicado por 4 é: " +divisaoPorQuatro+ ", multiplicado por 5 é: " +divisaoPorCinco)
}