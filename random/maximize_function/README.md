- #### geração inicial
é escolhido um valor inicial para [x, y]. Escolheu-se o conjunto de valores a seguir [[2, 2], [3, 7], [-7, -7], [0, 100], [20, -40]]

- #### custo
é definido como o valor de f(x, y)

- #### vizinhos
para dado estado x, y, os vizinhos são obtidos adicionando-se uma perturbação normal de média zero e desvio padrão 10

- #### hill climbing
a cada iteração, apenas pegamos um novo estado vizinho aleatório e se o custo desse estado for maior, atualizamos o estado senao continuamos no mesmo estado

- #### simualted annealing
muito semelhante ao hill climbing, a cada iteração, apenas pegamos um novo estado vizinho aleatório e se o custo desse estado for maior, atualizamos o estado. Caso contrário, atualizeremos o estado com probabilidade P, definida abaixo.

Probabilidade P = exp((custo novo - custo atual)/temperatura)

A temperatura é definida como 

fraction = step / maxsteps  
T = max(0.1, min(1, 1 - fraction)) 

onde maxsteps é definido como 20 000 e step é inicializado em 0 e incrementado em uma unidade a cada iteração. Nota-se que definindo a probabilidade relacionada à temperatura, vizinhos distantes nas primeiras iterações do algoritmo podem ser escolhidos mesmo que tenham um custo pior enquanto que conforme o algoritmo avança, ele tende a se aproxima e se mantém perto do mínimo global e não local

- #### seed
a distribuição das rainhas para dado n é feito com um random com seed de forma que tanto o hill climbing quanto o simulated annealing resolvem o mesmo problema, permitindo fazer uma comparação justa entre os algoritmos