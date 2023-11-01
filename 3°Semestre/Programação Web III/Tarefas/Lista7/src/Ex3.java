import java.util.Scanner;

public class Ex3 {

	public static void main(String[] args) {
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Digite a data: (dd/mm/aaaa)");
		String data = ler.nextLine();
		
		String dia = data.substring(0, 2);
		System.out.println("Dia: " +dia);
		
		String mes = data.substring(3, 5);
		System.out.println("Mes: " +mes);
		
		String ano = data.substring(6, 10);
		System.out.println("Ano: " +ano);

	}

}
