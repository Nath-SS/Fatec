package Exercicios;

import javax.swing.JOptionPane;

public class Exercicio2 {
	
    public static void main(String[] args) {
        int num1, num2, num3;
        String aux;
        
       
        aux = JOptionPane.showInputDialog("Digite o primeiro número:");
        num1 = Integer.parseInt(aux);
        
        aux = JOptionPane.showInputDialog("Digite o segundo número:");
        num2 = Integer.parseInt(aux);
        
        aux = JOptionPane.showInputDialog("Digite o terceiro número:");
        num3 = Integer.parseInt(aux);
        

        int maior = num1;
        if (num2 >= maior) {
            maior = num2;
        }
        if (num3 >= maior) {
            maior = num3;
        }
        
        // Mostra o resultado em uma caixa de diálogo
        JOptionPane.showMessageDialog(null, "O maior número é: " + maior);
    }
}
