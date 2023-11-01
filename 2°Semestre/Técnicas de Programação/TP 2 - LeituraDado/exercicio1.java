package exercicios;
import java.io.*;

public class exercicio1 {

	public static void main(String[]args) {
		String s = "";
		float base, altura, area;
		
		BufferedReader dado;
		
		try {
			System.out.println("base do triângulo:");
			dado=new BufferedReader(new InputStreamReader(System.in));
			s = dado.readLine();
			base = Float.parseFloat(s);
			
			System.out.println("altura do triângulo:");
			dado=new BufferedReader(new InputStreamReader(System.in));
			s = dado.readLine();
			altura = Float.parseFloat(s);
			
			area = (base*altura)/2;
			System.out.println("Área: " +area);
			
		}catch(IOException erro){
			System.out.println("Houve um erro na entrada de dados" +erro.toString());
		}catch(NumberFormatException erro) {
			System.out.println("Houve um erro na conversão, digite caracteres numéricos" +erro.toString());
		}
	}
}
