package Exercicios;

import java.util.Scanner;

public class Exercicio5 {
	
    public static void main(String[] args) {
        
    	Scanner ler = new Scanner(System.in);
        System.out.print("Digite o primeiro número: ");
        int num1 = ler.nextInt();
        System.out.print("Digite o segundo número: ");
        int num2 = ler.nextInt();

        if (num1 <= num2) {
            for (int i = num1; i <= num2; i++) {
                System.out.print(i + " ");
                try {
                    Thread.sleep(1000); // pausa por 1 segundo
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        } else {
            for (int i = num1; i >= num2; i--) {
                System.out.print(i + " ");
                try {
                    Thread.sleep(1000); // pausa por 1 segundo
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
