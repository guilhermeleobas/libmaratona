#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
#include <bitset>

using namespace std;

#define ll long long

ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve (ll upperbound){
	
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	for (ll i = 2; i <= _sieve_size; i++){
		if (!bs[i]) continue;

		for (ll j = i; j <= _sieve_size; j += i)
			bs[j] = 0;

		primes.push_back ((int)i);
	}
}

void print (){
	
	for (int i=0; i<primes.size(); i++)
		cout << primes[i] << ' ';
	cout << endl;
}

int main(){

	sieve (10000010);
	//print ();
	cout << primes.size() << endl;
	
	return 0;
}
