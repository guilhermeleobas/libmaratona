// MDC
//Recebe dois inteiros {a, b} e retorna o mdc(a, b);
long long int mdc (long long int numerador, long long int denominador){
	
	long long int resto=-1;
	long long int quociente=-1;
	
	while (resto != 0){
		//Quociente;
		quociente = numerador/denominador;
		
		//Resto;
		resto = numerador%denominador;
		
		//Reatribuição;
		numerador = denominador;
		
		//Garante que a atribuição do resto não será zero;
		if (resto != 0) {
			denominador = resto;
		}
	}
	
	return denominador;
}

long long int mmc (long long int numerador, long long int denominador){
	return (numerador*denominador)/mdc(numerador, denominador);
}
