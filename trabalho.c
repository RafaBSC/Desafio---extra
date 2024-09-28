#include <stdio.h>

int main() {
	float n1,n2,ppd, notas_alunos, n3_nota, menor_nota, nota_final;
	int exame_unificado, n3;
	
	printf("Digite a nota N1 (4.5): ");
	scanf("%f", &n1);
	
	printf("Digite a nota N2 (4.5): ");
	scanf("%f", &n2);
	
	printf("Digite a nota do PPD (1): ");
	scanf("%f", &ppd); //Nesses prints f, usei float porque s�o quest�es de notas, ent�o tem chance de dar n�meros quebrados, sendo assim um %f.
	
	if (n1 < 0 || n1 > 4.5 || n2 < 0 || n2 > 4.5 || ppd < 0 || ppd > 1) {
		printf("Erro!");
		return 3;
		// Aqui usei um || que seginifca 'OR', usei para simplificar o c�digo, ent�o se n1 for menor que 0 OU n1 for maior que 4.5 o c�digo ir� dar erro e assim por diante.
	}
	printf("O aluno fez o exame unificado? (0 para nao e 1 para sim). ");
	scanf("%d", &exame_unificado); //Nesse tipo de caso usei o INT, por conta que � somente 0 ou 1, ent�o s�o numeros inteiros, n�o precisaria do float.
	
	if (exame_unificado < 0 || exame_unificado > 1) {
		printf("Erro");
		return 3;
	}
	if (exame_unificado == 1) {
		printf("Digite a nota do exame unificado (1): ");
		scanf("%f", &notas_alunos);
		
		if (notas_alunos < 0 || notas_alunos > 1) {
			printf("Erro!");
			return 3;
		}
	}
	printf("O aluno realizou a N3? (0 para nao e 1 para sim). ");
	scanf("%d", &n3);
	
	if (n3 < 0 || n3 > 1) {
		printf("Erro!");
		return 3;
	}
	if (n3 == 1) {
		printf("Digite a nota da N3 (4.5): ");
		scanf("%f", &n3_nota);
		
		if (n3_nota < 0 || n3_nota > 4.5) {
			printf("Erro!");
			return 3;
			}
				
		menor_nota = (n1 < n2) ? n1 : n2; //Nesse caso usei um ? para simplificar o c�digo tamb�m. Esse ? seriviria basicamente como se fosse um 'IF' 'ELSE'.
		// J� os : � como se fosse um SEN�O, ent�o basicamente � quando a condi��o � falsa.
		
		if (n3_nota > menor_nota) {
			if(menor_nota == n1) {
				n1 = n3_nota;
			} else {
				n2 = n3_nota;
			}
		}
	}
	
	nota_final = n1 + n2 + ppd;
	
	if (exame_unificado == 1) {
        nota_final += notas_alunos; //Aqui � outra simplifica��o para n�o ficar repetindo nota_final 2 vezes, coloquei um += que faz a mesma fun��o desse caso: nota_final = nota_final + notas_alunos;
    }
    
    if (nota_final > 10 || nota_final < 0) {
    	printf("Erro!");
    	return 3;
	}
	
	printf("A sua nota final e: %.2f", nota_final);
	if (nota_final >= 7){
		printf("\nAprovado");
	} else {
		printf("\nReprovado");
	}
		
	return 0;
}
