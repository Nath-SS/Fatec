import java.util.Scanner;

public class Ex2 {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Digite uma frase: ");
		String frase = ler.nextLine();
		String aux = "";
		
		for(int i = 0; i< frase.length(); i++) {
			aux = aux.concat(String.valueOf(frase.charAt(i)));
			System.out.println(aux);
		}
		for(int i = frase.length() - 1; i >= 0; i--) {
			aux = frase.substring(0, i);
			System.out.println(aux);
		}

	}

}
