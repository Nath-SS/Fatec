import java.util.Scanner;

public class Ex5 {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Informe um numero para ter seu fatorial: ");
		int n = ler.nextInt();
		int fatorial = n;
		
		for(int i = n-1; i != 0; i-- ) {
			fatorial =+ fatorial*i;
		}
		System.out.println(fatorial);

	}

}
