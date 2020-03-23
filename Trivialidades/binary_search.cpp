//Binary search in the answer
int ini = 0, fim = MAX - 1;
while(ini <= fim) {
	media = (ini + fim) / 2;

	if(testa(media, r)) {
		deu = media;
		fim = media - 1;
	} else {
		ini = media + 1;
	}
}
