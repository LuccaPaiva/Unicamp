public class Boss {
	
	private final Elemento elemento;
	private int ataque;
	private int vida;
	private final String descricao;
	private Local local;
	private int escudoMax = 5;
	private int escudoAtual;
	private int num = 1;

	
	// Metódo construtor
	public Boss(NomeMonstro novo) {
		this.elemento = novo.getElemento();
		this.ataque = novo.getAtaque();
		this.vida = novo.getVida();
		this.descricao = novo.getDescricao();
		this.local = Local.ESPERA;
	}

	// Metódos sets e gets
	public Elemento getElemento() {
		return this.elemento;
	}
	
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
	
	public String getDescricao() {
		return this.descricao;
	}
	
	public Local getLocal() {
		return this.local;
	}
	public void setLocal(Local local) {
		this.local = local;
	}
	
	public int getEscudoAtual() {
		return this.escudoAtual;
	}
	public void setEscudo(int escudoNovo) {
		if(escudoNovo <= 0) {
			this.escudoAtual = 0;
		}
		else {
			this.escudoAtual = escudoNovo;
	
		}
	}
	
	public void setNum(int i) {
		this.num = i;
	}
	
	public void atualizaEscudo() {
		this.escudoAtual = this.escudoMax;
	}
	// Metódo toString
		public String toString() {
			String out = "";
			out += ">>>>>>>>>>>> Boss atual <<< " + this.num + " <<<<<<<<<<\n";
			out += "---------- "+this.descricao+ " ----------\n";
			out += "| Elemento: " + this.elemento + "|";
			out += "| Ataque: " + this.ataque + "|";
			out += "| Vida: " + this.vida + "|";
			out += "| Escudo: " + this.escudoAtual + "|";
			out += "| Local: " + this.local + "|\n";
			return out;
		}
}
