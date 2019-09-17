- #### modelo 
nunca teremos duas rainhas na mesma linha ou mesma coluna

- #### geração inicial
shuffle 1-n para linhas, shuffle 1-n para colunas e pegar indice a indice para gerar as posicoes

- #### custo
dado que nenhuma rainha está na mesma linha ou coluna que outra, é suficiente contar quantas rainhas se atacam nas diagonais

- #### vizinhos
para a geração de um novo estado, dado que existe necessariamente uma rainha em cada linha ou coluna, é suficiente fazer o swap de linhas ou colunas para um dado par de rainhas
