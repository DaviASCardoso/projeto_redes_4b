# Painel de Disponibilidade de Dispositivos de Rede

Programa em C que monitora até 10 dispositivos de rede. Ele mostra quais estão
ativos, calcula a disponibilidade da rede e dispara um alerta quando há falhas.

## Estrutura do projeto

```
projeto_redes_4b/
├── src/
│   └── projeto_redes_4b.c   # código-fonte do programa
├── Makefile
├── .gitignore
└── README.md
```

## Como o código funciona

### 1. Quantidade de dispositivos

```c
do {
    printf("Quantos dispositivos (1 a 10)? ");
    scanf("%i", &n);
    if (n < 1 || n > 10) {
        printf("Valor invalido!\n");
    }
} while (n < 1 || n > 10);
```

Primeiro o usuário informa quantos dispositivos serão monitorados, de 1 a 10.
O `do-while` repete a pergunta até o valor ser válido. Essa validação também
protege o vetor `estado`, que tem 10 posições: aceitar um número maior faria o
programa escrever fora dos limites do vetor.

### 2. Leitura dos estados

```c
for (i = 0; i < n; i++) {
    do {
        printf("Estado do dispositivo %i (1=ativo, 0=inativo): ", i + 1);
        scanf("%i", &estado[i]);
        if (estado[i] != 0 && estado[i] != 1) {
            printf("Digite apenas 0 ou 1\n");
        }
    } while (estado[i] != 0 && estado[i] != 1);
}
```

Para cada dispositivo, o usuário digita `1` (ativo) ou `0` (inativo), e o valor
fica guardado no vetor `estado`. O `do-while` dentro do `for` valida cada
entrada: qualquer valor diferente de 0 ou 1 é rejeitado e a pergunta se repete
para o mesmo dispositivo.

### 3. Exibição dos estados

```c
for (i = 0; i < n; i++) {
    if (estado[i] == 1) {
        printf("Dispositivo %i: ATIVO\n", i + 1);
    } else {
        printf("Dispositivo %i: INATIVO\n", i + 1);
    }
}
```

O programa percorre o vetor e mostra cada dispositivo como ATIVO ou INATIVO.
Como os índices do vetor começam em 0, é usado `i + 1` para que a numeração
exibida ao usuário comece em 1.

### 4. Contagem e percentual de disponibilidade

```c
for (i = 0; i < n; i++) {
    if (estado[i] == 1) {
        ativos = ativos + 1;
    } else {
        inativos = inativos + 1;
    }
}

percentual = ativos * 100.0 / n;
```

Outro laço percorre o vetor e incrementa os contadores `ativos` e `inativos`.
A disponibilidade é calculada como ativos × 100 ÷ n. O uso de `100.0` (e não
`100`) é importante: ele força a operação a ser feita com números decimais. Com
`100` inteiro, a divisão seria inteira e o resultado seria truncado (por
exemplo, 2 de 3 ativos daria 66 em vez de 66.7).

### 5. Painel e alerta

```c
printf("Ativos: %i\n", ativos);
printf("Inativos: %i\n", inativos);
printf("Disponibilidade: %.1f%%\n", percentual);

if (inativos >= 2) {
    printf("ALERTA: 2 ou mais dispositivos indisponiveis\n");
} else {
    printf("Situacao normal\n");
}
```

Por fim, o painel mostra os totais e a disponibilidade com uma casa decimal
(`%.1f`; o `%%` imprime o símbolo de porcentagem). Se dois ou mais dispositivos
estiverem inativos, o programa exibe um alerta. Caso contrário, mostra
"Situacao normal".

## Exemplo de execução

```
Quantos dispositivos (1 a 10)? 4
Estado do dispositivo 1 (1=ativo, 0=inativo): 1
Estado do dispositivo 2 (1=ativo, 0=inativo): 0
Estado do dispositivo 3 (1=ativo, 0=inativo): 1
Estado do dispositivo 4 (1=ativo, 0=inativo): 0

--- ESTADOS ---
Dispositivo 1: ATIVO
Dispositivo 2: INATIVO
Dispositivo 3: ATIVO
Dispositivo 4: INATIVO

--- PAINEL ---
Ativos: 2
Inativos: 2
Disponibilidade: 50.0%
ALERTA: 2 ou mais dispositivos indisponiveis
```

## Resumo

O programa valida as entradas do usuário, guarda os estados em um vetor, conta
os dispositivos ativos e inativos, calcula a disponibilidade e gera um alerta
automático quando há falhas. É um monitoramento de rede simples e funcional.

## Autores

- Davi Cardoso
- Henrique Francisco
