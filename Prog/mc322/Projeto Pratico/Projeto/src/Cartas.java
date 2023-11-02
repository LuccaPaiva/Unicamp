public class Cartas {
	
	// Vari�veis do objeto
	private final Elemento tipo;		// Atributo que espec�fica qual elemento a carta pertence.
	private final int custo; 			// Valor necess�rio para invocar a carta.
	private final String descricao;
	private Local local;				// Localiza��o atual da carta no jogo.
	private boolean status;
	
	// Met�do construtor
	public Cartas(Elemento tipo, int custo, String descricao, Local local) {
		this.tipo = tipo;
		this.custo = custo;
		this.descricao = descricao;
		this.local = local;
		this.status = true;
	}
	
	// Met�dos sets e gets
	public Elemento getElemento() {
		return this.tipo;
	}
	
	public int getCusto() {
		return this.custo;
	}
	
	public String getDescricao() {
		return this.descricao;
	}
	
	public void setLocal(Local local) {
		this.local = local;
	}
	public Local getLocal() {
		return this.local;
	}
	
	public boolean getStatus() {
		return this.status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
	
	// Met�do toString
	public String toString() {
		String out = "";
		out += "| Tipo: " + this.tipo + "|";
		out += "| Custo: " + this.custo + "|";
		out += "| Descri��o: " + this.descricao + "|";
		out += "| Status: " + this.status + "|";
		out += "| Local: " + this.local + "|";
		return out;
	}
	
}
