function divisores(){
    var vetor = [];
    for(var i = 1; i<=1000; i++){
        if(i%7 == 0){
          vetor.push(i);
        }
    }
    alert("Esses números são divísiveis por 7: " +vetor);
}