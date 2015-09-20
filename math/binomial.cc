long long binomial (int n, int r, int mod){
  vector< vector<long long> > C(n+1,vector<long long> (r+1,0));
 
  for (int i=0; i<=n; i++){
    for (int k=0; k<=r && k<=i; k++)
      if (k==0 || k==i)
        C[i][k] = 1;
      else
        C[i][k] = (C[i-1][k-1] + C[i-1][k])%mod;
    }
  return C[n][r];
}

