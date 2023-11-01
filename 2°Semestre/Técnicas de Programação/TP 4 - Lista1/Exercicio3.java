package Exercicios;

import javax.swing.JOptionPane;

public class Exercicio3 {

	public void main(String[]args) {
	
		int soma = 0;
	
		for(int i = 1; i<=100; i++) {
			soma += i;
		}
		
		JOptionPane.showMessageDialog(null, "A soma dos cem primeiros números inteiros é: " +soma);
	}
}
