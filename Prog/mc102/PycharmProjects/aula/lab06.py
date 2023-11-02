#Lucca paiva 240229

esp = int(input())
cap = 1
rest = esp
while cap!= 0:
    cap = int(input())
    rest -= cap
    if rest >= 0 and cap > 0:
        print(f'Seja bem-vindo! Capacidade restante: {rest}')
    elif rest < 0 and cap > 0:
        print(f'Veiculo muito grande! Capacidade restante: {rest + cap}')
        rest += cap
    elif cap < 0:
        print(f'Volte sempre! Capacidade restante: {rest}')