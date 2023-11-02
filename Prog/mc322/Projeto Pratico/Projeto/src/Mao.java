import java.util.ArrayList;
import java.util.concurrent.TimeUnit;



public class Mao {
	
	private final static int maxCartas = 8; 	// Limite de carta na mão
	private int vida;		// Vida do usuário
	private int energia;	// Quantidade de custo por rodada que o usuário pode gastar 
	private ArrayList<Cartas> hand;
	private ArrayList<Magia> spells;
	private ArrayList<Minion> minions;
	private int numeroDeCartas = 0;
	private int numeroDeFeiticos = 0;
	private int numeroDeMinions = 0;
	
	public Mao(Deck deck) {
		this.vida = 10;
		this.energia = 1;
		this.hand = new ArrayList<Cartas>();
		this.spells = new ArrayList<Magia>();
		this.minions = new ArrayList<Minion>();
	}
	

	// Metódos gets e sets
	public int getVida() {
		return vida;
	}
	public void setVida(int vida) {
		if(vida > 100) {
			this.vida = 100;
		}
		else {
		this.vida = vida;
		}
	}
	
	public int getNumeroDeCartas() {
		return this.numeroDeCartas;
	}
	public void setNumeroDeCartas(int novo) {
		this.numeroDeCartas = novo;
	}

	public int getNumeroDeFeiticos() {
		return this.numeroDeFeiticos;
	}
	public void setNumeroDeFeiticos(int novo) {
		this.numeroDeFeiticos = novo;
	}

	public int getNumeroDeMinions() {
		return this.numeroDeMinions;
	}
	public void setNumeroDeMinions(int novo) {
		this.numeroDeMinions = novo;
	}

	public ArrayList<Cartas> getHand() {
		return hand;
	}

	public ArrayList<Magia> getSpells() {
		return spells;
	}

	public ArrayList<Minion> getMinions() {
		return minions;
	}
	
	public Magia getFeitico(int i) {
		return this.spells.get(i);
	}
	
	public Minion getMinion(int i) {
		return this.minions.get(i);
	}
	
	public int getEnergia() {
		return this.energia;
	}
	public void setEnergia(int energia) {
		this.energia = energia;
	}
	public void atualizaEnergia(int valor) {
		this.energia -= valor;
	}
	
	// Criando a mão
	
	public void criaMao(Tabuleiro tabuleiro) {
		int i;
		for(i = 0; i<5; i++) {
			this.compraCarta(tabuleiro);
		}
	}
		
	public boolean compraCarta(Tabuleiro tabuleiro) {
		//verificar se deck nao ta vazio
		if (tabuleiro.getDeck().getTamanhoDeck() > 0){
			if(this.numeroDeCartas < maxCartas) {		// Verifica se a mão está cheia		
				Cartas card = tabuleiro.getDeck().compraCarta();
				this.numeroDeCartas ++;
				if(card.getClass() == Minion.class) {			// Verifica se a carta é um minion
					minions.add((Minion)card);
					numeroDeMinions ++;
					hand.add(card);
					card.setLocal(Local.HAND);
					return true;
				}
				else if(card.getClass() == Magia.class) {		// Verifica se a carta é uma magia
					spells.add((Magia)card);
					numeroDeFeiticos ++;
					hand.add(card);
					card.setLocal(Local.HAND);
					return true;
				}
				else {											// Caso a carta não seja magia nem minion
					return false;
				}
			}
			else {
				System.out.println("A mão está cheia!\n");
				System.out.println("A primeira carta foi descartada!!!\n");
				tabuleiro.getDeck().getCartasNoDeck().remove(0);
				return false;
				/*
				this.hand.get(0).setLocal(Local.CEMITERIO);
				if(this.hand.get(0).getClass() == Minion.class) { // Altera status do minon
					numeroDeMinions--;
					numeroDeCartas--;
					this.hand.get(0).setPeso(false);
					this.minions.remove(0);
					this.hand.remove(0);
				}
				else if(this.hand.get(0).getClass() == Magia.class) { 	//Altera status da magia
					numeroDeFeiticos--;
					numeroDeCartas--;
					this.hand.get(0).setPeso(false);
					this.spells.remove(0);
					this.hand.remove(0);
				}*/
				//return compraCarta(tabuleiro);
			}
		}
		else {
			System.out.println("Não há mais cartas no baralho");
			return false;
		}
	}
	
	public int jogaCarta(Cartas card, Tabuleiro tabuleiro) {	
			if( (card.getCusto() <=  this.energia) && (tabuleiro.adicionarCarta()) ) { //Verifica se há energia para a carta e se o campo não está cheio
				if(card.getClass() == Minion.class) {	
					minions.remove((Minion)card); 		// Remove o minion da lista presenta na mão 
					numeroDeMinions --;					// Diminui o numero de minions 
					card.setLocal(Local.CAMPO);			// Altera local da carta
					numeroDeCartas --;
					hand.remove(card);
					this.energia = this.energia - card.getCusto();
					card.setStatus(false);
					//System.out.println("-----Olha ai----");
					return 1;
				}
				else if(card.getClass() == Magia.class) {
					spells.remove((Magia)card);
					numeroDeFeiticos --;
					card.setLocal(Local.CEMITERIO);	
					numeroDeCartas --;
					this.energia = this.energia - card.getCusto();
					card.setStatus(false);
					hand.remove(card);
					return 1;
				}
				else {			// Quando a carta não é magia e nem monstro
					return -1;
				}
			}
			else {		// Quando não tem espaço para carta
				return -1;
			}
		}
		
	public int danoJogador(int dano){
		this.vida -= dano;
		if(vida > 0) {
			return vida;
		}
		else {
			return -1;
		}
	}
	
	public void printMinions() {
		try {

	        String out;
	        out = "************ Minions na Mao *** " + this.numeroDeMinions + " *********";
	        System.out.println(out);
	        for(int i = 0; i < this.numeroDeMinions ; i++) {
				System.out.println("Minion " + i + " " + this.minions.get(i));
		        TimeUnit.MICROSECONDS.sleep(500000);
			}
	    } catch (InterruptedException e) {
	        System.err.format("IOException: %s%n", e);
	    }
	}

	public void printFeiticos() {
		try {

	        String out;
	        out = "************ Feiticos na Mao *** " + this.numeroDeFeiticos + " *********";
	        System.out.println(out);
	        for(int i = 0; i < this.numeroDeFeiticos ; i++) {
				System.out.println("Feitico " + i + " " + this.spells.get(i));
		        TimeUnit.MICROSECONDS.sleep(500000);
			}
	    } catch (InterruptedException e) {
	        System.err.format("IOException: %s%n", e);
	    }
	}
	
	// Método toString
	public String toString() {
		String out = "";
		out += "~~~~~~~~~~~~~~ Status do jogador ~~~~~~~~~~~~\n";
		out += "\t Vida: "+this.vida+ "   Energia: "+this.energia+ "\n\n";
		out += "************ Cartas na mão ************\n";
		for(int i = 0; i < numeroDeCartas ; i++) {
			out += this.hand.get(i)+ "\n";
		}
		return out;
	}
	
	public void imprime() {
		try {
			int tempo = 500000/2;
	        // delay 5 seconds
	        //TimeUnit.SECONDS.sleep(5);
	        //System.out.println("End...");
	        String out = "************ Cartas na mão *** " + this.numeroDeCartas + " *********";
	        System.out.println(out);
	        for(int i = 0; i < numeroDeCartas ; i++) {
				System.out.println("Carta: "+i+"    "+this.hand.get(i));
		        TimeUnit.MICROSECONDS.sleep(tempo);
			}
	    } catch (InterruptedException e) {
	        System.err.format("IOException: %s%n", e);
	    }
	}
	
	public void imprimeStatus() {
		try {
			int tempo = 500000/2;
	        String out = "~~~~~~~~~~~~~~ Status do jogador ~~~~~~~~~~~~";
	        
	        System.out.println(out);
	        TimeUnit.MICROSECONDS.sleep(tempo);
	        
	        out = "\t Vida: "+this.vida+ "   Energia: "+this.energia+ "\n";
	        System.out.println(out);
	    } catch (InterruptedException e) {
	        System.err.format("IOException: %s%n", e);
	    }
	}
	
}
