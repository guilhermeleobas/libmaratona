//Calcula o algoritmo estendido de euclides. Para isso ele recebe dois numeros {a, b} e retorna um pair com o {alfa, beta}.
pair<int, int> Estendido_euclides (int a, int b){
    int x[3];
    int y[3];
    
    int quociente;
    int resto;

    int cont = 1;
    
    pair<int, int> num;

    //Inicialização de valores;
    x[0] = 1;
    x[1] = 0;

    y[0] = 0;
    y[1] = 1;

    //Calculo de Xn e Yn;
    while (b != 0){
        quociente = a/b;
        resto = a%b;

        a = b;
        b = resto;

        //x[cont+1] = x[cont-1] - quociente*x[cont];
        //y[cont+1] = y[cont-1] - quociente*y[cont];

        x[2] = x[0] - quociente*x[1];
        y[2] = y[0] - quociente*y[1];

        x[0] = x[1];
        x[1] = x[2];

        y[0] = y[1];
        y[1] = y[2];

        cont++;     

    }
    
    num = make_pair (x[0], y[0]);

    return num;
}
