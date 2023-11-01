package Exercicios;

import javax.swing.JOptionPane;

public class Exercicio1 {
	
    public static void main(String[] args) {
        double valorProduto = 0;
        int codigoAumento = 0;
        String aux = "";

        try {
        	aux = JOptionPane.showInputDialog("Digite o valor do produto:");
            valorProduto = Double.parseDouble(aux);
            
            aux = JOptionPane.showInputDialog("Digite o código de aumento(1, 3, 4 ou 8:");
            codigoAumento = Integer.parseInt(aux);
            
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(null, "Valor ou código inválido!");
            System.exit(0);
        }

        double valorAumentado = valorProduto;

        switch (codigoAumento) {
            case 1:
                valorAumentado += valorProduto * 0.15;
                break;
            case 3:
                valorAumentado += valorProduto * 0.20;
                break;
            case 4:
                valorAumentado += valorProduto * 0.35;
                break;
            case 8:
            	valorAumentado += valorProduto * 0.40;
            	break;
            default:
                JOptionPane.showMessageDialog(null, "Código de aumento inválido!");
                System.exit(0);
        }

        JOptionPane.showMessageDialog(null, "Valor do produto antes do aumento: R$" + valorProduto
                + "\nValor do produto com aumento: R$" + valorAumentado);
    }
}
