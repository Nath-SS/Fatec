import java.util.Scanner;

public class Ex6 {
	
	public static void main(String[]args) {
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Informe uma frase: ");
		String frase = ler.nextLine();
		
		System.out.println("Deseja converter para letra maiuscula ou minuscula? (1/2)");
		int resultado = ler.nextInt();
		
		if(resultado == 1) {
			String maiusculo = frase.toUpperCase();
		}else if(resultado == 2) {
			String minusculo = frase.toLowerCase();
		}else {
			System.out.println("O número informado não corresponde a nenhuma opção");
		}
	}
}
