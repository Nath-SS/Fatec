package Exercicios;

import javax.swing.JOptionPane;

public class Exercicio4 {

	public void main(String[]args) {
		
		double produto = 0;
	
		for(int i = 1; i<=15; i +=2 ) {
			produto = produto*i;
		}
		
		JOptionPane.showMessageDialog(null, "O produto dos inteiros impares entre 1 e 15 é: " +produto);
	}
	
}
