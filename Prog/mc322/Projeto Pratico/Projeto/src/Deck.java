import java.util.ArrayList;
import java.util.Random;

public class Deck {
	private ArrayList<Cartas> cartasNoDeck;
	public int tamanhoDeck;
	
	public Deck(Elemento elemento) {
		int i = 0;
		tamanhoDeck = 0;
		// inicializando o baralho
		this.cartasNoDeck = new ArrayList<Cartas>();
		if(elemento == Elemento.AGUA) {
			NomeMinion.MINI_BALEIA.buffElemento(NomeMinion.MINI_BALEIA);
			NomeMinion.PEIXE_ESPADA.buffElemento(NomeMinion.PEIXE_ESPADA);
		}
		if(elemento == Elemento.FOGO) {
			NomeMinion.VAGALUME.buffElemento(NomeMinion.VAGALUME);
			NomeMinion.VIRA_LATA_CARAMELO.buffElemento(NomeMinion.VIRA_LATA_CARAMELO);
		}
		if(elemento == Elemento.AR) {
			NomeMinion.ANDORINHA.buffElemento(NomeMinion.ANDORINHA);
			NomeMinion.CONDOR.buffElemento(NomeMinion.CONDOR);
		}
		if(elemento == Elemento.TERRA) {
			NomeMinion.TATUBOLA.buffElemento(NomeMinion.TATUBOLA);
			NomeMinion.RINOCERONTE.buffElemento(NomeMinion.RINOCERONTE);
		}
		for(i = 0; i < 5; i++) {
			if(i % 2 == 0) {
				this.cartasNoDeck.add(new Minion(NomeMinion.TATUBOLA));
				this.cartasNoDeck.add(new Minion(NomeMinion.CONDOR));
				this.cartasNoDeck.add(new Minion(NomeMinion.PEIXE_ESPADA));
				this.cartasNoDeck.add(new Minion(NomeMinion.VAGALUME));
				this.cartasNoDeck.add(new Minion(NomeMinion.RINOCERONTE));
				this.cartasNoDeck.add(new Minion(NomeMinion.ANDORINHA));
				this.cartasNoDeck.add(new Minion(NomeMinion.VIRA_LATA_CARAMELO));
				this.cartasNoDeck.add(new Minion(NomeMinion.MINI_BALEIA));
				tamanhoDeck += 8;
			}
			else {
				this.cartasNoDeck.add(new Magia(NomeMagia.CURA_JOGADOR));
				this.cartasNoDeck.add(new Magia(NomeMagia.BOLA_DE_FOGO));
				this.cartasNoDeck.add(new Magia(NomeMagia.CURA_MINION));
				this.cartasNoDeck.add(new Magia(NomeMagia.COMPRA_CARTA));
				this.cartasNoDeck.add(new Magia(NomeMagia.PROVOCADOR));
				this.cartasNoDeck.add(new Magia(NomeMagia.AUMENTA_ATAQUE));			
				tamanhoDeck += 6;
			}
		}
	}
	
	//Verificar se ta vazio antes de comecar
	public Cartas compraCarta() {
		Cartas card = cartasNoDeck.get(0);
		
		cartasNoDeck.remove(0);
		this.tamanhoDeck--;
		return card;
	}
	
	public void embaralha(){
		ArrayList<Cartas> novo = new ArrayList<Cartas>();
		int i, j, tamanho;
		int[] lista = new int[this.cartasNoDeck.size()];
		Random randomNumbers = new Random();
		
		
		for(int k=0; k < lista.length; k++) {
			lista[k] = randomNumbers.nextInt();
			if(lista[k]>=0) {
				continue;
			}
			else {
				lista[k] = -1 * lista[k];
			}
		}
		
		j=0;
		
		
		while(this.cartasNoDeck.size()>0) {
			tamanho = this.cartasNoDeck.size();
			if(tamanho > 1) {
				i = lista[j] % (tamanho-1);
			}
			else {
				i = 0;
			}
			novo.add(this.cartasNoDeck.get(i));
			this.cartasNoDeck.remove(i);
			j++;
		}
		this.cartasNoDeck = novo;
		return;
	}
	
	
	// Metódos sets e gets
	public ArrayList<Cartas> getCartasNoDeck() {
		return this.cartasNoDeck;
	}
	
	public void setCartasNoDeck(ArrayList<Cartas> cartasNoDeck) {
		this.cartasNoDeck = cartasNoDeck;
	}
	
	public int getTamanhoDeck() {
		return tamanhoDeck;
	}
	public void setTamanhoDeck(int tamanhoDeck) {
		this.tamanhoDeck = tamanhoDeck;
	}
	
	public String printDeck() {
		String out = "Deck:\n";
		for(int i = 0; i < tamanhoDeck; i++) {
			out += "\t" + this.cartasNoDeck.get(i) + "\n";
		}
		return out;
	}
}
