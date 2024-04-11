INTRODUÇÃO 
    A computação gráfica é essencial em muitas áreas, desde jogos até design gráfico. Este projeto explora a criação de uma aplicação interativa em Python usando Tkinter. Implementamos ferramentas de desenho, como retas, círculos e polígonos, permitindo ao usuário interagir com o canvas para criar formas personalizadas.

    Além disso, incluímos transformações geométricas 2D, como translação, rotação, escala e reflexões, usando valores definidos pelo usuário para modificar as formas desenhadas. Implementamos algoritmos eficientes de rasterização, como Bresenham para desenhar retas e círculos.

    Também abordamos o recorte de regiões com os algoritmos Cohen-Sutherland e Liang-Barsky, garantindo que apenas partes visíveis das formas sejam renderizadas. Com uma interface intuitiva e educativa, este projeto oferece uma experiência prática e flexível para explorar conceitos fundamentais de computação gráfica.

ESTRUTURA
    Canvas: Área de desenho principal, onde as formas são renderizadas.

    Botões de Ferramentas: Permite ao usuário selecionar a ferramenta de desenho atual, como Reta, Círculo ou Polígono.

    Campos de Entrada: Para inserir parâmetros de transformações geométricas, como deslocamento (dx, dy), ângulo de rotação e fatores de escala (escala X, escala Y).

    Opções de Reflexão: Checkboxes para selecionar opções de reflexão nos eixos X, Y ou XY.

    Botões de Transformação: Botões para aplicar translação, rotação, escala e reflexão às formas desenhadas.

    Interatividade com o Canvas: O usuário pode interagir com o canvas clicando para desenhar formas ou definir pontos de polígono.

FUNCIONALIDADES
    Desenho de Formas: Permite ao usuário desenhar retas, círculos e polígonos no canvas.

    Transformações Geométricas:

    Translação: Move as formas selecionadas na direção especificada.
    Rotação: Rotaciona as formas em torno de seu centro de massa.
    Escala: Aumenta ou reduz o tamanho das formas.
    Reflexão: Reflete as formas em relação aos eixos X, Y ou XY.
    Bresenham para Linhas: Implementação do algoritmo de Bresenham para desenhar linhas de forma eficiente.

    Recorte de Regiões:

    Cohen-Sutherland: Realiza o recorte de retângulos com o algoritmo de Cohen-Sutherland.
    Liang-Barsky: Realiza o recorte de linhas usando a equação paramétrica de Liang-Barsky.

COMO USAR 
    Antes de saber como usar a interface, é preciso ter o python instalado em sua máquina

    Desenho de Formas:
    Clique nos botões "Reta", "Círculo" ou "Polígono".
    Para desenhar uma forma, clique no canvas para definir os pontos necessários.

    Transformações Geométricas:
    Insira os valores desejados nos campos de entrada para "dx", "dy" (Translação), "Ângulo de Rotação" (Rotação), "Fator de Escala X" e "Fator de Escala Y" (Escala).
    Marque as opções de reflexão desejadas.
    Clique nos botões "Translação", "Rotação", "Escala" ou "Reflexão" para aplicar as transformações nas formas desenhadas.
   
    Bresenham para Linhas:
    Selecione o botão "Reta" e clique no canvas para definir os pontos inicial e final da linha.
    
    Recorte de Regiões:
    Não há interação direta com o usuário. Os algoritmos de recorte são aplicados automaticamente quando utilizados.
    
    Limpeza e Reinício:
    Use a opção do seu ambiente gráfico para fechar a aplicação e limpar o canvas.

MUDANÇAS FEITAS APÓS A APRESENTAÇÃO
- Circunferência funcionando da maneira adequada 
- Recorte com falhas 
