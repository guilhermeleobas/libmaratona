// Fermat;
void fermat (long long int num, int &f1, int &f2){


	double y;
	long long int x = (long long int) sqrt(num);

	if (pow(x, 2) == num){
		f1 = 0;
		f2 = 0;
	}

	while (++x < (num+1)/2){


		y = sqrt( (pow(x, 2)) - num);
		if (y == (int)y){
			f1 = x+y;
			f2 = x-y;

		}
	}
}
