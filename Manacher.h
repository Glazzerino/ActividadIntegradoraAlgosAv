class Manacher 
{
static std::string manacher(string text)
{
  string T = "";
	int n = text.length();

	for (int i=0; i < n; i++)
    {
		T += "|";
		T += text[i];
	}

	T += "|";
    n = T.length();
    vector<int> L(n);
	L[0] = 0;
	L[1] = 1;
	int maxLong = 0, maxCentro = 0;
	bool exp;

	for (int c = 1, li = 0, ri = 2; ri < n; ri++)
    {
		li = c - (ri - c);
		exp = false;

		if (c - maxLong <= ri && ri >= c + maxLong){
			if (L[li] < (c + L[c] - ri)){
				L[ri] = L[li];
			}

			else if(L[li] == (c + L[c]) - ri && (c + L[c]) == 2 * n)
            {
				L[ri] = L[li];
			}

			else if(L[li] == (c + L[c]) - ri && (c + L[c]) < 2 * n)
            {
				L[ri] = L[li];
				exp = true;
			}

			else if(L[li] > (c + L[c]) - ri && (c + L[c]) < 2 * n)
            {
				L[ri] = (c+L[c]) - ri;
				exp = true;
			}
		}

		else
        {
			L[ri] = 0;
			exp = true;
		}

		if (exp)
        {
			while((ri + L[ri] < n) && (ri - L[ri] > 0) && (T[ri - L[ri] - 1] == T[ri + L[ri] + 1]))
            {
				L[ri]++;
			}
		}

		c = ri;
		if (L[ri] > maxLong)
        {
            maxLong = L[ri];
            maxCentro = ri;
        }
	}

	int inicio = (maxCentro - maxLong) / 2;
	string salida = "";

	for (int i = inicio; i < (inicio + maxLong); i++)
    {
		salida += text[i];
	}

	return salida;
}
};