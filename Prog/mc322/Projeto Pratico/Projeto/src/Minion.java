public class Minion extends Cartas{
	
	private int ataque;
	private int vida;
	private final NomeMinion nome;
	
	// Método construtor
	Minion(NomeMinion novo) {
		super(novo.getElemento(), novo.getCusto(), novo.getDescricao(), Local.DECK);
		this.ataque = novo.getAtaque();
		this.vida = novo.getVida();
		this.nome = novo;
	}

	// Metódos sets e gets
	public int getAtaque() {
		return this.ataque;
	}
	public void setAtaque(int ataque) {
		this.ataque = ataque;
	}
	
	public int getVida() {
		return this.vida;
	}
	public void setVida(int vida) {
		this.vida = vida;
	}
	
	public NomeMinion getNome() {
		return this.nome;
	}
	
	
	
	// Metódo toString
	public String toString() {
		String out = "";
		out += "----------"+this.nome+ "----------\n";
		out += "| Vida: " + this.vida + " |";
		out += "| Ataque: " + this.ataque + " |";
		out += super.toString() + " |\n";
		return out;
	}
	
	public int dano(int damage, int statusPos) {
		if(damage >= vida) {
			return -1;
		}
		vida = vida - damage;
		this.setStatus(true);
		return 0;
	}
}