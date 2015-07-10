// ax + by = t
// ax = 1 mod b
// Basta substituir t por 1;
int inv (int t, int a, int b){

	for (int i = 1; i <= b; i++){
		if ((a*i)%b == t) return i;
	}
}
