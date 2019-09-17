- #### modelo 
nunca teremos duas rainhas na mesma linha ou mesma coluna

- #### geração inicial
shuffle 1-n para linhas, shuffle 1-n para colunas e pegar indice a indice para gerar as posicoes. Assim a configuração inicial não terá duas rainhas na mesma linha ou coluna;

- #### custo
dado que nenhuma rainha está na mesma linha ou coluna que outra, é suficiente contar quantas rainhas se atacam nas diagonais. Note que se duas rainhas estao na mesma coluna, entao o custo incrementa em 2 (rainha 1 ataca a rainha 2 e a rainha 2 ataca a rainha 1)

- #### vizinhos
para a geração de um novo estado, dado que existe necessariamente apenas uma rainha em cada linha ou coluna, é suficiente fazer o swap de linhas ou colunas para um dado par de rainhas


- #### hill climbing
a cada iteração, apenas pegamos um novo estado vizinho aleatório e se o custo desse estado for menor, atualizamos o estado senao continuamos no mesmo estado

- #### simualted annealing
muito semelhante ao hill climbing, a cada iteração, apenas pegamos um novo estado vizinho aleatório e se o custo desse estado for menor, atualizamos o estado. Caso contrário, atualizeremos o estado com probabilidade P, definida abaixo.

Probabilidade P = exp((custo atual - custo novo)/temperatura)

A temperatura é definida como 

fraction = step / maxsteps  
T = max(0.1, min(1, 1 - fraction)) 

onde maxsteps é definido como 20 000 e step é inicializado em 0 e incrementado em uma unidade a cada iteração. Nota-se que definindo a probabilidade relacionada à temperatura, vizinhos distantes nas primeiras iterações do algoritmo podem ser escolhidos mesmo que tenham um custo pior enquanto que conforme o algoritmo avança, ele tende a se aproxima e se mantém perto do mínimo global e não local
