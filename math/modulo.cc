//A função irá retornar um inteiro P = (a^e)%n;
int modulo (int a, int e, int n){
	int A;
	int E;
	int P;

	//ETAPA 1: Atribuição de valores;
	A = a;
	E = e;
	P = 1;

	//ETAPA 2: Enquanto E for diferente de 0;
	while (E != 0){
	
        //ETAPA 3: Verifica se E é impar;
        if (E%2 != 0){
			P = (A*P)%n;
			E = (E-1)/2;
		}
		//ETAPA 4: Verifica se E é par;
		else {
			E = E/2;
		}

		//ETAPA 5: Incremento do A;
		A = (A*A)%n;

    }
    
	return P;
}
