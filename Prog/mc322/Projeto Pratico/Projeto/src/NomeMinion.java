public enum NomeMinion {
	
	TATUBOLA(Elemento.TERRA, 1, "Um ser rolante", 4, 8),
	PEIXE_ESPADA(Elemento.AGUA , 1, "Peixe narigudo", 6, 6),
	VAGALUME(Elemento.FOGO, 1, "Animal Brilhante", 8, 4),
	CONDOR(Elemento.AR, 1, "Passaro Voador", 7, 5),
	RINOCERONTE(Elemento.TERRA, 3, "Torna-se o alvo do chefe", 9, 15),
	ANDORINHA(Elemento.AR, 2, "Essa andorinha faz verão", 15, 1),
	MINI_BALEIA(Elemento.AGUA, 2, "Uma baleia bem amigável", 7, 10),
	VIRA_LATA_CARAMELO(Elemento.FOGO, 3, "Deveria ter ido para nota de 200 reais", 4, 20);
	
	
	private final Elemento elemento;
	private final int custo;
	private final String descricao;
	private int ataque;
	private final int vida;
	
	// Metódo construtor
	NomeMinion(Elemento elemento, int custo, String descricao, int ataque, int vida) {
		this.elemento = elemento;
		this.custo = custo;
		this.descricao = descricao;
		this.ataque = ataque;
		this.vida = vida;
	}
	
	// Metódos sets e gets
	public Elemento getElemento() {
		return this.elemento;
	}
	
	public int getCusto() {
		return this.custo;
	}
	
	public String getDescricao() {
		return this.descricao;
	}
	
	public int getAtaque() {
		return this.ataque;
	}
	
	public int getVida() {
		return this.vida;
	}
	
	public void buffElemento(NomeMinion mini) {
		mini.ataque += 3;
	}
}
