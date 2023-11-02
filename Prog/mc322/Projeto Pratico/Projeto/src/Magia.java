public class Magia extends Cartas {
	
	private final int valor;			// Quantidade do efeito da carta
	private final NomeMagia nome;
	private boolean status; 				// Se true indica que a carta pode fazer uma ação
	
	// Metódo construtor
	public Magia(NomeMagia novo) {
		super(novo.getElemento(), novo.getCusto(), novo.getDescricao(), Local.DECK); 
		this.valor = novo.getValor();
		this.nome = novo;
		this.status= true;
	}
	
	// Metódos sets e gets
	public int getValor() {
		return this.valor;
	}
	
	public NomeMagia getNome() {
		return this.nome;
	}
	
	public boolean getStatus() {
		return this.status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
	
	// Metódo toString
		public String toString() {
			String out = "";
			out += "-~-~-~-~-~"+this.nome+ "~-~-~-~-~-\n";
			out += "| Valor: " + this.valor + " |";
			out +=  super.toString()+"\n";
			return out;
		}
}
