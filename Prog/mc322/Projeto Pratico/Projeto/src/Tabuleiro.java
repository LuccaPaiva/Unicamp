import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.TimeUnit;


public class Tabuleiro {

	private final int maxCartas;
	private static int rodadas;
	private ArrayList<Cartas> campo;
	private final Elemento elemento;
	private ArrayList<Cartas> cemiterio;
	private Boss monstroAtual;
	private ArrayList<Boss> chefes;
	private ArrayList<Minion> minionsEmCampo;
	private int numeroDeMinions = 0;
	private int maxMinions = 5;
	private Deck deck;
	private Mao hand;
	private int manaTotal;
	private int tempo = 200000;
	//private int vidaJogador = 30;
	
	Boss chefe1 = new Boss(NomeMonstro.PRIMEIRO_MONSTRO);
	Boss chefe2 = new Boss(NomeMonstro.SEGUNDO_MONSTRO);
	Boss chefe3 = new Boss(NomeMonstro.TERCEIRO_MONSTRO);
	Boss chefe4 = new Boss(NomeMonstro.QUARTO_MONSTRO);
	
	
	
	// Método construtor
	public Tabuleiro() {
		maxCartas = 5;
		rodadas = 0;
		this.campo = new ArrayList<Cartas>();
		this.elemento = aleatorizarElemento();
		this.cemiterio = new ArrayList<Cartas>();
		this.chefes = new ArrayList<Boss>();
		this.minionsEmCampo = new ArrayList<Minion>();
		this.chefes.add(chefe4);					// Adicionando monstros no tabuleiro na ordem que eles vão aparecer no campo 
		this.chefes.add(chefe3);
		this.chefes.add(chefe2);
		this.chefes.add(chefe1);
		if(elemento == chefe1.getElemento()) {		// Verifica se o primeiro monstro é do mesmo elemento do campo
			chefe1.setAtaque(chefe1.getAtaque()+3);
		}
		this.monstroAtual = chefe1;					// Primeiro monstro vai para o campo
		this.monstroAtual.setLocal(Local.CAMPO);
		this.deck = new Deck(elemento);
		this.deck.embaralha();
		this.hand = new Mao(deck);
		this.hand.criaMao(this);
		this.manaTotal = 1;
		this.elementoBoss();
	}
	
	// Metódo para aumentar ataque do boss
		private void elementoBoss() {
			if(this.elemento == this.chefe2.getElemento()) {
				this.chefe2.setAtaque(this.chefe2.getAtaque() + 3);
			}
			else if(this.elemento == this.chefe3.getElemento()) {
				this.chefe3.setAtaque(this.chefe3.getAtaque() + 3);
			}
			else if(this.elemento == this.chefe4.getElemento()) {
				this.chefe4.setAtaque(this.chefe4.getAtaque() + 3);
			}
			else {
				return;
			}
		}
	
	// Metódos sets e gets
	public int getRodadas() {
		return rodadas;
	}
	
	public Elemento getElemento() {
		return this.elemento;
	}
	
	public ArrayList<Cartas> getCampo() {
		return this.campo;
	}
	
	public ArrayList<Cartas> getCemiterio() {
		return this.cemiterio;
	}
	
	public Boss getMonstoAtual() {
		return this.monstroAtual;
	}

	public ArrayList<Minion> getMinionsEmCampo() {
		return minionsEmCampo;
	}
	
	public Minion getMinion(int i) {
		return minionsEmCampo.get(i);
	}
	
	public Deck getDeck() {
		return this.deck;
	}
	
	public Mao getMao() {
		return this.hand;
	}
	
	public Mao getHand() {
		return this.hand;
	}
	
	public void start() {
		this.deck.embaralha();
		this.hand.criaMao(this);

	}
	
	public int getNumeroDeMinions() {
		return this.numeroDeMinions;
	}
	
// Metódo aleatorizar o elemento do campo
	public Elemento aleatorizarElemento() {
		int i;
		Random randomNumber = new Random();
		i = randomNumber.nextInt() % 4;
		
		switch(i) {
		case 0:
			return Elemento.AGUA;
		case 1:
			return Elemento.AR;
		case 2:
			return Elemento.TERRA;
		default:
			return Elemento.FOGO;
		}
	}
	

	// Metódo que verifica se o campo está cheio
	public boolean adicionarCarta() {
		if(this.campo.size() < this.maxCartas) {
			return true;
		}
		else {
			return false;
		}
	}

	public int ataqueMinion(Minion mini) {
		int dano = mini.getAtaque();
		int vida = this.monstroAtual.getVida();
		int escudo = this.monstroAtual.getEscudoAtual();
		if(mini.getStatus()) {
			mini.setStatus(false);
			if(escudo >= dano) {
				this.monstroAtual.setEscudo(escudo - dano);
				System.out.println(dano + " de dano no escudo causado por " + mini.getNome() +"\n");
				return 0;
			}
			else if(vida + escudo - dano <= 0) {
				this.monstroAtual.setVida(0);
				System.out.println(">>>>>>>>>>>>>>>>> BOSS  MORTO <<<<<<<<<<<<<<<<\n");
				return -1;
			}
			this.monstroAtual.setEscudo(escudo - dano);
			this.monstroAtual.setVida(vida + escudo - dano);
			if(escudo > 0) {
				System.out.println("Escudo do boss zerado");
			}
			System.out.println(dano + " de dano causado por " + mini.getNome() +"\n");
			System.out.println("Vida atual do chefe " + (vida + escudo - dano) + "\n");
			return vida - dano;
		}
		System.out.println("Minion" + mini.getNome() + " nao pode atacar\n");
		return 0;
	}
	
	public int ataqueChefe(Boss chefe) {
		int dano = this.monstroAtual.getAtaque();
		if(chefe == chefe1) {
			if (this.numeroDeMinions > 0) {
				Minion mini = this.minionsEmCampo.get(0);
				int stat = mini.dano(dano, 1);
				if(stat == -1) {//minion morreu
					System.out.println("Minions " + mini.getNome() + " morto\n");
					this.minionMorreu(mini);
				}
				else {
					try {
						System.out.println("Minions " + mini.getNome() + " sofreu " + dano + " de dano");
						TimeUnit.MICROSECONDS.sleep(tempo);
						System.out.println("Vida Atual de " + mini.getNome() + ": " + mini.getVida());
						TimeUnit.MICROSECONDS.sleep(tempo);
					}
					catch (InterruptedException e) {
				        System.err.format("IOException: %s%n", e);
				        return 1;
				    }
					
				}
				return 1;
			}
			else {
				try {
					int aux = this.danoJogador(dano);
					System.out.println("Jogador sofreu " + dano + " de dano\n");
					TimeUnit.MICROSECONDS.sleep(tempo);
					System.out.println("Vida atual do Jogador: " + this.hand.getVida());
					TimeUnit.MICROSECONDS.sleep(tempo);
					return aux;
				}
				catch (InterruptedException e) {
			        System.err.format("IOException: %s%n", e);
			        return -1;
			    }

			}
		}
		else if(chefe == chefe2) {
			if (this.numeroDeMinions > 0) {
				Minion mini = this.minionsEmCampo.get(0);
				int stat = mini.dano(dano, 1);
				if(stat == -1) {//minion morreu
					this.minionMorreu(minionsEmCampo.get(0));
					this.monstroAtual.setVida(this.monstroAtual.getVida() + 5);
					System.out.println("Minions " + mini.getNome() + " morto\n");
					System.out.println("Chefe 2 recuperou 5 de vida\n");
					System.out.println("Vida Atual do Boss: " + this.monstroAtual.getVida() + "\n");
				}
				else {
					System.out.println("Minions " + mini.getNome() + " sofreu " + dano + " de dano\n");
					System.out.println("Vida Atual: " + mini.getVida() + "\n");
				}
				return 1;
			}
			else {
				int aux = this.danoJogador(dano);
				System.out.println("Jogador sofreu " + dano + " de dano\n");
				System.out.println("Vida atual do Jogador: " + this.hand.getVida());
				return aux;

			}
		}
		else if(chefe == chefe3) {
			if (this.numeroDeMinions > 0) {
				Minion mini = this.minionsEmCampo.get(0);
				int stat = mini.dano(dano, -1);
				mini.setStatus(false);
				if(stat == -1) {//minion morreu
					this.minionMorreu(minionsEmCampo.get(0));
					System.out.println("Minions " + mini.getNome() + " morto\n");
				}
				else {
					System.out.println("Minions " + mini.getNome() + " sofreu " + dano + " de dano\n");
					System.out.println("Vida Atual: " + mini.getVida() + "\n");
				}
				return 1;
			}
			else {
				int aux = this.danoJogador(dano);
				System.out.println("Jogador sofreu " + dano + " de dano\n");
				System.out.println("Vida atual do Jogador: " + this.hand.getVida());
				return aux;

			}
		}
		else {
			if (this.numeroDeMinions > 0) {
				for(int i = 0; i < this.numeroDeMinions; i++) {
					Minion mini = this.minionsEmCampo.get(i);
					int stat = this.minionsEmCampo.get(i).dano(dano, 1);
					if(stat == -1) {//minion morreu
						this.minionMorreu(minionsEmCampo.get(0));
						System.out.println("Minions " + mini.getNome() + " morto\n");
					}
					else {
						System.out.println("Minions " + mini.getNome() + " sofreu " + dano + " de dano\n");
						System.out.println("Vida Atual: " + mini.getVida() + "\n");
					}
				}
				return 1;
			}
			else {
				int aux = this.danoJogador(dano);
				System.out.println("Jogador sofreu " + dano + " de dano\n");
				System.out.println("Vida atual do Jogador: " + this.hand.getVida());
				return aux;

			}
		}
		
		
	}
	
	public int atualizaBoss() {
		if(this.monstroAtual == chefe1) {
			chefe1.setLocal(Local.CEMITERIO);
			chefe2.setLocal(Local.CAMPO);
			this.monstroAtual = chefe2;
			this.monstroAtual.setNum(2);
			return 2;
		}
		else if(this.monstroAtual == chefe2) {
			chefe2.setLocal(Local.CEMITERIO);
			chefe3.setLocal(Local.CAMPO);
			this.monstroAtual = chefe3;
			this.monstroAtual.setNum(3);
			return 3;
		}
		else if(this.monstroAtual == chefe3) {
			chefe3.setLocal(Local.CEMITERIO);
			chefe4.setLocal(Local.CAMPO);
			this.monstroAtual = chefe4;
			this.monstroAtual.setNum(4);
			return 4;
		}
		return 0;
		
	}
	
	public void atualizaRodada() {
		rodadas++;
		if(this.monstroAtual == chefe1) {
			this.monstroAtual.atualizaEscudo();
		}
		if(this.manaTotal < 3) {
			this.manaTotal ++;
		}
		this.getHand().setEnergia(this.manaTotal);
		this.hand.compraCarta(this);
		
		int i;
		for(i=0; i < this.minionsEmCampo.size(); i++) {	// Deixa que os minions recem chegados no campo possam atacar na próxima rodada 
			if( (this.monstroAtual == chefe3) && (i==0)) {
				this.minionsEmCampo.get(i).setStatus(false);
			}
			else {
				this.minionsEmCampo.get(i).setStatus(true);
			}
		}
	}
	
	public int jogarMinion(Minion mini) {
		if(mini.getCusto() > this.getHand().getEnergia()) {
			return -1;//nao deu pra jogar
		}
		if(this.numeroDeMinions < this.maxMinions) {
			this.numeroDeMinions ++;
			/*if(this.elemento == mini.getElemento()) {
				mini.setAtaque(mini.getAtaque() + 3);
			}*/
			this.hand.jogaCarta(mini, this);
			if(mini.getNome() == NomeMinion.RINOCERONTE) {
				this.campo.add(0, mini);
				this.minionsEmCampo.add(0, mini);
			}
			else {
				this.minionsEmCampo.add(mini);
				this.campo.add(mini);
			}
			System.out.println("Minion " + mini.getNome() + " adicionado ao campo de batalha!!");
			return 1;
		}
		else {
			System.out.println("Campo cheio");
			return -2;
		}
	}
	
	public void minionMorreu(Minion mini) {
		this.minionsEmCampo.remove(mini);
		this.campo.remove(mini);
		this.numeroDeMinions --;
	}
	
	public int danoJogador(int dano){
		int aux = this.hand.danoJogador(dano);
		if(aux == -1) {
			System.out.println("GAME OVER\n\n");
			return -1;
		}
		return 1;
	}
	
	public int efeitoMagia(Magia card, int alvo) {
		if(this.hand.getEnergia() < card.getCusto()) {
			System.out.println("Energia Insuficiente para esta carta");
			return 0;
		}
		if(card.getNome() == NomeMagia.CURA_JOGADOR) {
			this.getHand().setVida( this.hand.getVida() + NomeMagia.CURA_JOGADOR.getValor() ); // Atualiza vida do usuário
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);
			return 0;
		}
		else if(card.getNome() == NomeMagia.BOLA_DE_FOGO) {
			int dano = card.getValor();
			int vida = this.monstroAtual.getVida();
			int escudo = this.monstroAtual.getEscudoAtual();
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);			
			if(escudo >= dano) {
				this.monstroAtual.setEscudo(escudo - dano);
				System.out.println(dano + " de dano no escudo causado pela BOLA DE FOGO");
				return 0;
			}
			else if(vida + escudo - dano <= 0) {
				this.monstroAtual.setVida(0);
				System.out.println(">>>>>>>>>>>>>>>>> BOSS  MORTO <<<<<<<<<<<<<<<<\n");
				return -1;
			}
			this.monstroAtual.setEscudo(escudo - dano);
			this.monstroAtual.setVida(vida + escudo - dano);
			if(escudo > 0) {
				System.out.println("Escudo do boss zerado");
			}
			System.out.println(dano + " de dano causado pela BOLA DE FOGO");
			System.out.println("Vida atual do chefe " + (vida + escudo - dano) + "\n");
			return vida - dano;
		}
		else if(card.getNome() == NomeMagia.CURA_MINION) {
			//verificar qaul minion curar
			if(this.numeroDeMinions == 0) {
				System.out.println("Nao ha minions em campo para serem curados");
				return 0;
			}
			if(alvo >= this.getMinionsEmCampo().size()) {			// Condição para cancelar ação
				System.out.println("Inserir um opcao valida\n");
				return 0;
			}
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);
			Minion mini = this.minionsEmCampo.get(alvo);
			mini.setVida(mini.getVida() + card.getValor());
			System.out.println("Minion " + mini.getNome() + " foi restaurado em 7 de vida");
			
			return 0;
		}
		else if(card.getNome() == NomeMagia.COMPRA_CARTA) {
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);
			for(int j = 0;j < card.getValor(); j++) {
				this.hand.compraCarta(this);
			}
		}
		else if(card.getNome() == NomeMagia.PROVOCADOR) {
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);
			Minion mini = this.minionsEmCampo.get(alvo);
			this.minionsEmCampo.remove(alvo);
			this.minionsEmCampo.add(0, mini);
			hand.imprime();
		}
		else if(card.getNome() == NomeMagia.AUMENTA_ATAQUE) {
			//verificar qaul minion curar
			if(this.numeroDeMinions == 0) {
				System.out.println("Nao ha minions em campo para serem curados");
				return 0;
			}
			if(alvo >= this.getMinionsEmCampo().size()) {			// Condição para cancelar ação
				System.out.println("Inserir um opcao valida\n");
				return 0;
			}
			this.hand.jogaCarta(card, this);
			this.cemiterio.add(card);
			card.setLocal(Local.CEMITERIO);
			card.setStatus(false);
			Minion mini = this.minionsEmCampo.get(alvo);
			mini.setAtaque(mini.getAtaque() + card.getValor());;
			System.out.println("O ataque do minion " + mini.getNome() + " é de " + mini.getAtaque());
			return 0;
		}
		return 0;
	}
	
	public String minionsEmCampo() {
		String out = "MINIONS EM CAMPO\n";
		for(int i = 0; i < minionsEmCampo.size(); i++) {
			out += "Minions " + i + " : " + this.minionsEmCampo.get(i).getNome() + "";
			if(this.minionsEmCampo.get(i).getStatus()) {
				out += "\t - Pode atacar\n";
			}
			else {
				out += "\t - NAO pode atacar\n";
			}
			out+= "\tAtaque: " + this.minionsEmCampo.get(i).getAtaque() + "\n";
			out+= "\tVida: " + this.minionsEmCampo.get(i).getVida() + "\n";
			
		}
		return out;
	}
	
	public void printMinions() {
		try {
	        String out;        
	        out = "************ Minions no Tabuleiro ************";
	        System.out.println(out);
	        Minion mini;
	        for(int i = 0; i < this.numeroDeMinions ; i++) {
	        	mini = this.minionsEmCampo.get(i);
				System.out.println("Minion " + i + " " + mini.getNome() + "\n\t -Ataque: " + mini.getAtaque() + "\n\t -Vida: " + mini.getVida());
				if(mini.getStatus()) {
					System.out.println("\t -Pode atacar na rodada");
				}
				else {
					System.out.println("\t -NAO pode atacar na rodada");
				}
				TimeUnit.MICROSECONDS.sleep(tempo);
			}
	    } catch (InterruptedException e) {
	        System.err.format("IOException: %s%n", e);
	    }
	}
	
	public String printRound() {
		String out = "\t O elemento do CAMPO é " + this.elemento + "!\n";
		out += "\t\tROUND " + rodadas + "\n";
		if(this.numeroDeMinions > 0) {
			out += this.minionsEmCampo();
		}
		return out;
	}
}
