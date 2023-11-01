package Exercicios;
import javax.swing.*;


public class Exercicio {

	public static void main(String[]args) {
		
		String aux="";
		double peso, altura, imc;
		
		try {
			aux = JOptionPane.showInputDialog("Digite o seu peso");
			peso = Float.parseFloat(aux);
			
			aux = JOptionPane.showInputDialog("Digite sua altura");
			altura = Float.parseFloat(aux);
			
			imc = peso/(altura*altura);
			
			if(imc < 18.5) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Peso abaixo do normal");
				
			}else if(imc >= 18.5 && imc < 25.0) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Peso normal");
			
			}else if(imc >= 25.0 && imc < 30.0) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Pré obesidade");
			
			}else if(imc >= 30.0 && imc < 35.0) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Obesidade classe I");
	
			}else if(imc >= 35.0 && imc < 40.0) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Obesidade classe II");
				
			}else if (imc >= 40.0) {
				JOptionPane.showMessageDialog(null,"IMC: "+imc + "-Obesidade classe III");
			}
			
		}catch(NumberFormatException erro) {
			JOptionPane.showMessageDialog(null, "Houve um erro na conversão. Digite apenas números" +erro.toString());
		}
		System.exit(0);
	}
}
