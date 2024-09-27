import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Pointcut;

@Aspect
public class VerificacaoSaldoAspect {

    // Define um ponto de corte para qualquer método sacar em qualquer subclasse de Conta
    @Pointcut("execution(* Conta.sacar(..))")
    public void saqueTentativa() {}

    // Antes de cada tentativa de saque, verifica o saldo e gera log se insuficiente
    @Before("saqueTentativa() && args(valor)")
    public void verificarSaldoAntes(double valor) {
        System.out.println("Verificando saldo para saque de: " + valor);
    }

    // Depois de cada saque, registra o saldo remanescente
    @After("saqueTentativa()")
    public void registrarSaldoRestante() {
        System.out.println("Verificação pós-saque: Saldo atualizado.");
    }
}
