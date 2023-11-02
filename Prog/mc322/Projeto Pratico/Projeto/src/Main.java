/*
 * Grupo 19
 * Lucca Ferreira Paiva  240229
 * Lucas Saviti da Silva 172967
 * 
 */

import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.util.ArrayList;


public class Main {
	
	public static void main(String[] args) {
		//BOSS
		int acao;
		Minion mini;
		Scanner scanner = new Scanner(System.in);
		Tabuleiro tabuleiro = new Tabuleiro();
		
		//System.out.println(tabuleiro.getMonstoAtual());
		Boss chefe;
		
		int derrotado = 1;
		int nChefe = 4;
		ArrayList<NomeMagia> baseDeMagia = new ArrayList<NomeMagia>();
		baseDeMagia.add(NomeMagia.AUMENTA_ATAQUE);
		baseDeMagia.add(NomeMagia.PROVOCADOR);
		baseDeMagia.add(NomeMagia.CURA_MINION);
		int fim = 1;
		Magia feitico;
		chefe = tabuleiro.getMonstoAtual();
		chefe.atualizaEscudo();
		if(true) {
			try {
				System.out.println("\n\t\tBem Vindo a CORACAO DE PEDRA\n");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Neste epico jogo a sua missao é derrotar 4 chefoes, cada um com suas habilidades unicas");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("E funcionara da seguinte forma: voce enfrentara um chefao por vez, sendo que para derrotalos basta reduzir a vida deles a 0");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Se a sua vida chegar a 0 voce que perde\n");
				TimeUnit.MICROSECONDS.sleep(1000000);
				
				System.out.println("Na sua mao voce tera cartas, e no inicio de cada turno voce recebe uma nova");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Existem dois tipos de cartas, os minions e os feiticos");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Os minions tem atributos de ataque e vida, e eles ficam no tabuleiro ate que suas vidas cheguem a 0, quando morrem");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Ja os feiticos tem acoes imediatas\n");
				TimeUnit.MICROSECONDS.sleep(1000000);
				
				System.out.println("Voce comecara com 1 de energia no primeiro turno");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("No segundo turno tera 2  de energia");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("A partir do terceiro turno, voce tera sempre 3 de energia");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Cada carta tem um custo de energia, que é descontado da sua energia do turno");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Mas em todo turno a sua energia volta cheia\n");
				TimeUnit.MICROSECONDS.sleep(1000000);
				
				System.out.println("Alem disso, em cada partida que voce jogar, o tabuleiro tera um elemento");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("E os minions desse elemento receberao um bonus de ataque\n");
				TimeUnit.MICROSECONDS.sleep(500000);
				
				System.out.println("Ha 4 habilidades basicas para voce usar:");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("1 - Jogar um minion no tabuleiro");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tCada minion tem um custo de energia, se voce tiver o custo do minion em energia voce pode jogar ele no tabuleiro");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tMinions nao podem atacar no turno em que sao jogados");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("2 - Atacar com um minion");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tOs minions no tabuleiro podem atacar o chefao, causando o seu dano de ataque ao Boss");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tOs minions so podem atacar um vez por turno");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("3 - Jogar feitico");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tDe forma parecida com os minions, os feiticos tambem tem um custo em energia");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tOs feiticos tem acao imediata, e cada um tem um efeito unico");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tEm alguns feiticos é preciso identificar o alvo");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("4 - Passar");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("\tQuando ja tiver atacado com todos os minions, e nao tiver mais energia, voce pode passar a sua vez\n");
				TimeUnit.MICROSECONDS.sleep(1000000);
			}
			catch (InterruptedException e) {
		        System.err.format("IOException: %s%n", e);
		    }
		}
		
		while(nChefe != 0 && fim != -1) {
			//acao jogador
			//System.out.println(tabuleiro.getDeck().printDeck());
			try {
				System.out.println("-------------------------------------------------------------------------------------\n");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println(tabuleiro.printRound());
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println(tabuleiro.getMonstoAtual());
				TimeUnit.MICROSECONDS.sleep(500000);
				tabuleiro.getMao().imprimeStatus();
				TimeUnit.MICROSECONDS.sleep(500000);
				tabuleiro.getMao().imprime();
				TimeUnit.MICROSECONDS.sleep(500000);

			}
			catch (InterruptedException e) {
		        System.err.format("IOException: %s%n", e);
		    }
			
			while(true) {
				//escolher acao
				try {
					System.out.println("Ha " + tabuleiro.getMao().getEnergia() + " de energia disponivel\n");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("Qual a sua proxima acao:");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t1 - Atacar com Minion");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t2 - Jogar Minion");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t3 - Jogar Feitico");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t4 - Passar");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t5 - Ver Mao");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t6 - Ver Monstro Atual");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t7 - Ver Campo Atual");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t8 - Ver Status do Jogador");
					TimeUnit.MICROSECONDS.sleep(50000);
					System.out.println("\t10 - Rendicao");
					acao = scanner.nextInt();
				}
				catch (InterruptedException e) {
			        System.err.format("IOException: %s%n", e);
			        acao = 4;
			    }
				if(acao == 1) {
					if(tabuleiro.getMinionsEmCampo().size()<1) {		// Verifica se há minions no campo
						System.out.println("Não há minions no campo!\n");
						continue;
					}
					else {
						//listar minions do tabuleiro
						tabuleiro.printMinions();
						//perguntar qual minion vai atacar
						System.out.println("Com qual deseja atacar?");
						int i = scanner.nextInt();
						if(i == -1 || i >= tabuleiro.getMinionsEmCampo().size()) {			// Condição para cancelar ação
							System.out.println("Inserir um opcao valida\n");
							continue;
						}
						else {
							mini = tabuleiro.getMinion(i);
							//perguntar qual o alvo do ataque
							//tirar vida do boss
							derrotado = tabuleiro.ataqueMinion(mini);
							if(derrotado == -1 && nChefe == 4) {
								fim = 0;
								break;
							}
						}
					}
				}
				else if(acao == 2) {
					if(tabuleiro.getMao().getNumeroDeMinions() < 1) {
						System.out.println("Não há minions na mão!\n");
						continue;
					}
					else {						
						//listar minions da mao
						tabuleiro.getMao().printMinions();
						//perguntar qual desses minions vai jogar
						System.out.println("Qual minion deseja jogar?");
						int i = scanner.nextInt();
					
						//adcionar ao tabuleiro
						if(i == -1) {		// Caso queira cancelar a ação
							continue;
						}
						// Caso o numero esteja fora do range das cartas na mão
						else if(i >= tabuleiro.getMao().getMinions().size()) {
							System.out.println("Carta não encontrada\n");
							continue;
						}
						else {
							mini = tabuleiro.getMao().getMinion(i);
							int erro = tabuleiro.jogarMinion(mini);	
							if(erro == -1){
								System.out.println("Energia Insuficiente");
							}
						}
					}
				}
				else if(acao == 3) {
					// Verifica se a magias na mão
					if(tabuleiro.getMao().getNumeroDeFeiticos()<1) {		
						System.out.println("Não há magias na ma mão\n");
						continue;
					}
					else {
						//listar feiticos da mao
						tabuleiro.getHand().printFeiticos();
						//perguntar qual feitico usar
						System.out.println("Qual feitico quer usar?\n");
						int i = scanner.nextInt();
						if(i == -1) {
							continue;
						}
						else if(i >= tabuleiro.getHand().getNumeroDeFeiticos()) {
							System.out.println("Esta carta é inválida\n");
							continue;
						}
						else {
							feitico = tabuleiro.getMao().getFeitico(i);
							int alvo = 0;
							if(baseDeMagia.contains(feitico.getNome())) {
								if(tabuleiro.getNumeroDeMinions() < 0) {
									System.out.println("Nao ha minions no tabuleiro");
									continue;
								}
								else {
									tabuleiro.printMinions();
									System.out.println("Qual minion sera o alvo?");
									alvo = scanner.nextInt();
								}
							}
							derrotado = tabuleiro.efeitoMagia(feitico, alvo);
							if(derrotado == -1 && nChefe == 4) {
								fim = 0;
								break;
							}
							//realizar acoes do feitico
						}
					}
				}
				else if(acao == 4) {
					System.out.println("Voce passou a sua vez" + "\n");
					break; //FIM acao jogador
				}
				else if(acao == 5) {
					//System.out.println(tabuleiro.getMao());
					tabuleiro.getMao().imprime();
				}
				else if(acao == 6) {
					System.out.println(tabuleiro.getMonstoAtual());
				}
				else if(acao == 7) {
					if(tabuleiro.getCampo().size() == 0) {
						System.out.println("O seu lado do campo está vazio, cuidado!!!\n");
					}
					else {
						tabuleiro.printMinions();
					}
				}
				else if(acao == 8) {
					tabuleiro.getMao().imprimeStatus();
				}
				else if(acao == 10) {
					fim = -1;
					break;
				}
				
				//verificar vida do boss se <= 0 --> boss derrotado
				if(derrotado == -1) {
					System.out.println("\n\n\nPARABÉNS O BOSS FOI DERROTADO!!!\n\n\n\n");
					nChefe = tabuleiro.atualizaBoss();
					derrotado = 1;
					if(nChefe != 0) {
						System.out.println("Se prepare para  o novo chefe!!!!");
						System.out.println(tabuleiro.getMonstoAtual());
						chefe = tabuleiro.getMonstoAtual();
					}
				}
			}
			//ataque do chefe
			if(fim == -1) {
				break;
			}
			else {
				try {
					TimeUnit.MICROSECONDS.sleep(500000);
					System.out.println("--------------------------------------------------------------\n******************* Turno do Boss ****************\n");
					TimeUnit.MICROSECONDS.sleep(500000);
					fim = tabuleiro.ataqueChefe(chefe);
					//atualiza rodada
					//tabuleiro.atualizaRodada(); 
					//reseta escudo do chefe se precisar e almenta rodada
					TimeUnit.MICROSECONDS.sleep(500000);
					tabuleiro.atualizaRodada();
					TimeUnit.MICROSECONDS.sleep(500000);
				}
				catch (InterruptedException e) {
			        System.err.format("IOException: %s%n", e);
			    }
			}
			if(fim == -1) {
				break;
			}
		}
		scanner.close();
		if(fim == -1) {
			try {
				System.out.println("Voce perdeu!");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Que pena :(");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Quem sabe da proxima vez voce consiga");
			}
			catch (InterruptedException e) {
		        System.err.format("IOException: %s%n", e);
		    }
		}
		else if(nChefe == 0 && fim == 0){
			try {
				System.out.println("Parabens!!!!!!!!!!!!!!");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Voce Venceu");
				TimeUnit.MICROSECONDS.sleep(500000);
				System.out.println("Todos os chefoes foram derrotados, bom trabalho");
			}
			catch (InterruptedException e) {
		        System.err.format("IOException: %s%n", e);
		    }
		}
	}
}
