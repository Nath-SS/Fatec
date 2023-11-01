import java.util.Scanner;

public class Ex4 {

    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        System.out.print("Digite o inteiro de 4 dígitos: ");
        String inteiro = ler.next();
        
        if (inteiro.length() != 4) {
            System.out.println("Por favor, digite um número de 4 dígitos.");
            return;
        }
        System.out.println("Você deseja criptografar ou descriptografar o número? (1 ou 2)");
        int resposta = ler.nextInt();
        
        if(resposta == 1) {
        	criptografar(inteiro);
        }else if(resposta == 2) {
        	descriptografar(inteiro);
        }else {
        	System.out.println("O valor informado não corresponde a nenhuma das alternativas.");
        }


    }

	public static void criptografar(String inteiro) {
		int primeiro = Character.getNumericValue(inteiro.charAt(0));
        int segundo = Character.getNumericValue(inteiro.charAt(1));
        int terceiro = Character.getNumericValue(inteiro.charAt(2));
        int quarto = Character.getNumericValue(inteiro.charAt(3));

        int auxiliar = primeiro+1;
        primeiro = terceiro+1;
        terceiro = auxiliar;

        auxiliar = segundo+1;
        segundo = quarto+1;
        quarto = auxiliar;

        String criptografado = "" + primeiro + segundo + terceiro + quarto;
        
        System.out.println("Número criptografado: " + criptografado);
		
	}
	
	public static void descriptografar(String inteiro) {
		int primeiro = Character.getNumericValue(inteiro.charAt(0));
        int segundo = Character.getNumericValue(inteiro.charAt(1));
        int terceiro = Character.getNumericValue(inteiro.charAt(2));
        int quarto = Character.getNumericValue(inteiro.charAt(3));

        int auxiliar = terceiro-1;
        terceiro = primeiro-1;
        primeiro = auxiliar;

        auxiliar = quarto-1;
        quarto = segundo-1;
        segundo = auxiliar;

        String descriptografado = "" + primeiro + segundo + terceiro + quarto;
        
        System.out.println("Número descriptografado: " + descriptografado);
	}
}

