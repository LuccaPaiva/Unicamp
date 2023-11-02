public enum NomeMagia {

	CURA_JOGADOR(Elemento.AGUA, 2, -1, 10, "Cura 10 pontos de vida do usuário"),
	BOLA_DE_FOGO(Elemento.FOGO, 2, -1, 5, "Causa 5 de dano ao Boss Atual"),
	CURA_MINION(Elemento.AGUA, 2, -1, 7, "Adiciona 7 pontos de vida de um minion"),
	PROVOCADOR(Elemento.TERRA, 1, -1, 0, "Deixa o minion alvo como alvo para o Boss"),
	COMPRA_CARTA(Elemento.AR, 2, -1, 3, "Compre 3 cartas novas"),
	AUMENTA_ATAQUE(Elemento.FOGO, 3, -1, 8, "Aumenta o ataque de um minion em 8");
	
	
	private final Elemento elemento;
	private final int custo;
	private final int tempo;
	private final int valor;
	private final String descricao;
	
	// Metódo construtor
	NomeMagia(Elemento elemento, int custo, int tempo, int valor, String descricao) {
		this.elemento = elemento;
		this.custo = custo;
		this.tempo = tempo;
		this.valor = valor;
		this.descricao = descricao;
	}
	
	// Metódos sets e gets
	public int getCusto() {
		return this.custo;
	}
	
	public int getTempo() {
		return this.tempo;
	}
	
	public int getValor() {
		return this.valor;
	}
	
	public Elemento getElemento() {
		return this.elemento;
	}
	
	public String getDescricao() {
		return this.descricao;
	}
}
