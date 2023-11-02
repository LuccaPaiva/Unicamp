public enum NomeMonstro {

	PRIMEIRO_MONSTRO(Elemento.TERRA, 3, 30, "Um monstro feito de rocha", 1),
	SEGUNDO_MONSTRO(Elemento.AGUA, 4, 35, "Uma fera aqu�tica que se cura", 4),
	TERCEIRO_MONSTRO(Elemento.AR, 6, 40, "Um monstro que imobiliza seus advers�rios", 1),
	QUARTO_MONSTRO(Elemento.FOGO, 7, 45, "Um chef�o que coloca todos em chamas", 2);
	
	private final Elemento elemento;
	private final int ataque;
	private final int vida;
	private final String descricao;
	private final int habilidade;
	
	// Met�do construtor
	NomeMonstro(Elemento elemento, int ataque, int vida, String descricao, int habilidade) {
		this.elemento = elemento;
		this.ataque = ataque;
		this.vida = vida;
		this.descricao = descricao;
		this.habilidade = habilidade;
	}
	
	// Met�dos gets e sets
	public Elemento getElemento() {
		return this.elemento;
	}
	
	public int getAtaque() {
		return this.ataque;
	}
	
	public int getVida() {
		return this.vida;
	}
	
	public String getDescricao() {
		return this.descricao;
	}
	
	public int getHabilidade() {
		return this.habilidade;
	}
}
