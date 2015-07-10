// TEORIA DOS NUMEROS:
//A função recebe um inteiro n e retorna um vector contendo todos os primos menores ou iguais a n;
vector<int> crivo (int n){

	//Vector com os primos;
	vector<int> primos;
	vector<int> result;

	//Ints;
	int P, T;

	//Etapa 1: Aloca espaço no vector de (n-1)/2 posições e inicializa com 1. 
	primos.resize ((n-1)/2, 1);

	P = 3;

	//Etapa 2:
	while (P*P < n){
		

		//Etapa 3: Se a posição (P-1)/2 == 0, incremente P += 2;
		while (primos[((P-1)/2)-1] == 0){
			P += 2;
		}

		//Etapa 4: Atribua P² = T.
		 //Etapa 4.1: Substituia o valor de T-1/2 no vetor por 0;
		 //Etapa 4.2: Incremente o valor de T += 2P;
		 //Etapa 4.3: Repita a etapa 4.1 ate que T > N;

		T = P*P;
		while (T < n){
			primos[((T-1)/2)-1] = 0;
			T += 2*P;
		}

		P += 2;

	}

	//Etapa 2.1: Escreva todos os primos 2j+1
	for (int cont=0; cont<primos.size(); cont++){
		if (primos[cont] == 1)
			result.push_back ((cont+1)*2+1);
	}

	return result;
}
