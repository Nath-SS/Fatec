package exercicios;
import java.util.Scanner;

public class exercicio2 {
    private double saldo;

    public exercicio2() {
        saldo = 0.0;
    }

    public void depositar(double valor) {
        saldo += valor;
    }

    public void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
        } else {
            System.out.println("Saldo insuficiente.");
        }
    }

    public double getSaldo() {
        return saldo;
    }

    public static void main(String[] args) {
        Scanner ler = new Scanner(System.in);

        exercicio2 conta = new exercicio2();

        System.out.println("Abertura de conta bancária.");
        System.out.println("Saldo inicial: R$ 0,00");

        System.out.print("Digite o valor a ser depositado: R$ ");
        double valorDeposito = ler.nextDouble();
        conta.depositar(valorDeposito);
        System.out.printf("Depósito realizado com sucesso. Saldo atual: R$ %.2f\n", conta.getSaldo());

        System.out.print("Digite o valor a ser sacado: R$ ");
        double valorSaque = ler.nextDouble();
        conta.sacar(valorSaque);
        System.out.printf("Saque realizado com sucesso. Saldo final: R$ %.2f\n", conta.getSaldo());
    }
}
