import java.util.Scanner;

public class Ex1 {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Digite uma frase: ");
		String frase = ler.nextLine();
		String invertida = "";
		
		for (int i = frase.length() - 1; i>=0; i-- ) {
			invertida = invertida.concat(String.valueOf(frase.charAt(i)));
		}
		System.out.println("Frase invertida: " +invertida);
	}

}
