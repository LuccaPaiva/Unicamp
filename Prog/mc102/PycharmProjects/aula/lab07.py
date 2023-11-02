pvryu = pvken = 50
soma = golpe = combo = golpeantigo = rounds = golpeantigo = 0
seriest = True
danosofrido = golpe = comboantigo = 1
lutador = morto = False
mudanca = False

while True:
    golpe = int(input())
    if golpe == None:
        break
    if golpe * golpeantigo < 0:

        '''if morto:
            if rounds == 0:
                print('empatou')
            elif rounds > 0:
                print('Ken venceu')
            else:
                print('Ryu venceu')
        '''
        if danosofrido:
            pvken -= combo
            print(f'Ken: {pvken + combo} - {combo} = {pvken}')
        else:
            pvryu -= combo
            print(f'Ryu: {pvryu + combo} - {combo} = {pvryu}')
    #verificar se alguem morreu
    if pvken <= 0:
        rounds += 1
        morto = True
        pvryu = pvken = 50
        combo = 0
    if pvryu <= 0:
        rounds -= 1
        pvryu = pvken = 50
        combo = 0

    #Ken leva golpe ---> True
    if golpe > 0:
        if golpeantigo > 0:
            combo += golpe
        else:
            combo = golpe
            mudaca = True
        danosofrido = True
    #Ryu leva golpe ---> False
    if golpe < 0:
        if golpeantigo < 0:
            combo -= golpe
        else:
            combo = -golpe
            mudanca = True
        danosofrido = False
    golpeantigo = golpe
print('hhey')
