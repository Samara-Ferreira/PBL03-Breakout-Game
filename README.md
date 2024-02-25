<h1 align="center"> Breakout game</h1>

<div align="justify"> 
<div id="sobre-o-projeto"> 
<h2> Sobre o Projeto</h2>

Atualmente, a Apple é uma das maiores empresas de desenvolvimento e inovação tecnológica, com suas produções conhecidas de dispositivos móveis e computadores pessoais. Dois dos seus principais fundadores foram Steve Jobs e Wozniak, um inventor e um engenheiro que moldaram uma geração de jogos eletrônicos na década de 70 com a criação do jogo de arcade Breakout. 

Este projeto tem o intuito de desenvolver um jogo inspirado no Breakout. É utilizada a placa FPGA DE1-SoC para executar o sistema e disponibilizar a interface de controle ao usuário. Um acelerômetro imbutido na placa permite captar a movimentação pretendida pelo usuário. Botões são utilizados para executar comandos no jogo. E os dados de imagem são transmitidos por um cabo VGA para um monitor CRT, sendo ele, o dispositivo que fará a exibição das telas ao usuário. 

Os requisitos para elaboração do sistema são apresentados a seguir:

* O código carregado na DE1-SoC deve ser feito em linguagem C;
* Um acelerômetro deve captar a movimentação feita na placa para alterar a posição da barra que irá colidir com a bola;
* Os botões devem ser utilizados para executar comandos no jogo;
* Os dados de imagem devem ser transmitidos de um cabo VGA para um monitor CRT;

</div>

<h2>  Equipe: <br></h2>
<uL> 
  <li><a href="https://github.com/Samara-Ferreira">Samara dos Santos Ferreira</a></li>
  <li><a href="https://github.com/Silviozv">Silvio Azevedo de Oliveira</a></li>
  <li><a href="https://github.com/SivalLeao">Sival Leão de Jesus</a></li>
  <li><a href="https://github.com/TAlmeida003">Thiago Neri dos Santos Almeida</a></li>
</ul>

<h1 align="center"> Sumário </h1>
<div id="sumario">
	<ul>
        <li><a href="#equipamentos">  Descrição dos Equipamentos e Software Utilizados</a></li>
        <li><a href="#arq_CPU">  Arquitetura da placa DE1-SoC</a></li>
        <li><a href="#Drives"> Drives de Dispositivos de Entrada e Saída (I/O) </a></li>
        <li><a href="#Inteface-Grafica"> Interface do Usuário </a></li>
        <li><a href="#Regras-de-jogo"> Dinâmica e Regras de Jogo </a></li>
        <li><a href="#Algoritmos"> Algoritmos de Jogo </a></li>
        <li><a href="#solucao-geral"> Solução Geral do projeto </a></li>
        <li><a href="#testes"> Testes Realizados </a></li>
        <li><a href="#conclusao"> Conclusão </a></li>
        <li><a href="#execucaoProjeto"> Execução do Projeto </a></li>
        <li><a href="#referencias"> Referências </a></li>
	</ul>	
</div>

<div id="equipamentos"> 
<h2> Descrição dos Equipamentos e Software Utilizados</h2>
<div align="justify"> 

<div id="arq_CPU"> 
<h2> Arquitetura da placa DE1-SoC</h2>
<div align="justify">

<div id="Drives"> 
<h2> Drives de Dispositivos de Entrada e Saída (I/O)</h2>
<div align="justify">

<div id="Inteface-Grafica"> 
<h2> Interface do Usuário </h2>
<div align="justify">

<div id="Regras-de-jogo"> 
<h2> Dinâmica e Regras de Jogo </h2>
<div align="justify">

O objetivo principal do jogo Breakout é destruir todos os blocos que compõem a estrutura do cenário, utilizando uma bolinha. O jogador assume o controle de uma prancha para rebater a bolinha e evitar que ela caia no "abismo", representado pela parte inferior da tela. Para garantir uma experiência dinâmica e desafiadora, o jogo conta com uma série de regras que serão apresentadas nesta seção.

<h3> Jogabilidade: Controle da Prancha </h3>

A movimentação da placa é baseada na inclinação da placa DE1-SoC. O jogador deverá posicionar a placa em uma certa inclinação para a direita ou esquerda, o que resultará na movimentação da prancha correspondente. Esse controle é realizado através do acelerômetro disponível na placa.

É importante ressaltar que a movimentação da prancha está limitada pelas paredes laterais do cenário, ou seja, a prancha não pode ultrapassar essas paredes durante o jogo.

Além disso, é crucial entender que a prancha não possui uma velocidade fixa. Sua velocidade varia de acordo com o ângulo de inclinação da placa. Quanto maior o ângulo de inclinação, maior será a velocidade da prancha, e vice-versa.

Os gifs a seguir ilustram a movimentação da placa e a consequente movimentação da prancha de acordo com esses movimentos.

<h3> Características da Bola e sua Movimentação </h3>

A bola apresenta duas características principais: sua movimentação contínua e suas interações com as estruturas do cenário. Na física do jogo, a bolinha mantém um movimento incessante nos eixos horizontal (x) e vertical (y), exceto em casos específicos nos quais o botão de pausa é acionado.

Quando a bolinha colide com algum objeto no cenário, como paredes laterais, superior, blocos ou a prancha controlada pelo jogador, ela é capaz de se refletir a partir do ponto de colisão. Essa reflexão pode ocorrer de três maneiras distintas: inversão de sentido apenas no eixo x, apenas no eixo y, ou simultaneamente nos dois eixos.

Analisando as diferentes colisões com cada objeto do cenário, temos as seguintes características:

* **Colisão com a Prancha:** Nesta colisão, a bolinha pode se refletir em três direções distintas, dependendo do ponto de impacto na prancha. A prancha é dividida em três partes: direita (a bolinha vai para a direita se bater nesse lado), esquerda (a bolinha vai para a esquerda se bater nesse lado) e centro (a bolinha reflete perfeitamente). Além disso, o ângulo e a velocidade da bolinha são alterados após a colisão, com cada lado da prancha oferecendo quatro velocidades diferentes e ângulos distintos de reflexão.

* **Colisão com Paredes Laterais:** Ao colidir com uma das paredes laterais, a bolinha conserva sua direção no eixo y e inverte o sentido no eixo x.

* **Colisão com a Parede Superior:** Quando a bolinha colide com a parede superior, ocorre o oposto das paredes laterais: ela mantém sua direção no eixo x e inverte o sentido no eixo y.

* **Colisão entre Paredes Superior e Lateral:** Se a bolinha colide entre a parede superior e lateral, ocorre a inversão nos dois eixos simultaneamente.

* **Colisão entre Prancha e Paredes Laterais:** Quando a bolinha colide entre a prancha e uma das laterais, também ocorre a inversão nos dois eixos simultaneamente.

* **Colisão entre os blocos:** O último tipo de colisão é com os blocos. Se a colisão ocorre nas laterais, é invertido o eixo x; nas partes superior e inferior, é invertido o eixo y. Adicionalmente, há colisões específicas nas pontas dos blocos, onde o comportamento varia dependendo do movimento da bola (subindo ou descendo) e da presença de blocos adjacentes.

<h3> Pontuação </h3>
O sistema de pontuação é baseado na quebra de blocos após cada colisão. Cada fileira de blocos possui um valor específico a ser pontuado. Os níveis mais baixos até os superiores possuem as seguintes pontuações progressivas: 1, 3, 5, 7, 9 e 11.

<h3> Finalização do Jogo </h3>
Existem duas condições de finalização do jogo: vitória ou derrota do jogador. A vitória é alcançada quando todos os blocos são quebrados durante a partida. Por outro lado, a derrota ocorre sempre que a bola ultrapassa o nível da prancha, resultando em sua queda e encerramento do jogo.

<div id="Algoritmos"> 
<h2> Algoritmos de Jogo </h2>
<div align="justify">

Para implementar as regras do jogo a nível de software, foram desenvolvidos diversos algoritmos responsáveis por gerenciar o comportamento dos elementos do jogo. Nesta seção, serão apresentadas as sequências responsáveis pela movimentação da bolinha e sua interação com os objetos do cenário.

<h3> Algoritmo de Colisão </h3>

Este algoritmo permite que a bolinha reconheça os objetos no cenário do jogo. Como todos os objetos têm formato retangular, exceto a bolinha, que é circular, foi desenvolvido um algoritmo clássico de detecção de colisão entre círculo e retângulo.

A lógica do algoritmo baseia-se em comparar um círculo com certo  raio ligeiramente maior (raio da bola mais o raio de colisão) e um retângulo de dimensões h e b Inicialmente, é procurado o ponto mais próximo entre o círculo e o retângulo, analisando as dimensões x e y. Esta análise permite considerar apenas os limites do retângulo.

Em seguida, é calculada a distância euclidiana entre a bola e o ponto de impacto utilizando o teorema de Pitágoras, e esse valor é arredondado, já que o jogo é em pixels. Se a distância calculada for menor ou igual ao raio da bola, significa que ocorreu uma colisão, e o algoritmo retorna 1. Caso contrário, retorna 0 para indicar que não houve colisão.

<h3> Algoritmo de Verificação Contínua </h3>

Em simulações físicas, a verificação de colisões é um processo contínuo e crucial para garantir a precisão e a fidelidade da simulação. Enquanto a abordagem discreta atualiza a posição dos objetos em intervalos fixos de tempo, a verificação contínua de colisões é mais precisa, evitando problemas como o "efeito de túnel".

No contexto deste projeto, o algoritmo de verificação contínua de colisões é implementado para garantir que as colisões sejam detectadas entre cada intervalo de tempo, mesmo em movimentos rápidos ou objetos pequenos.

O algoritmo de verificação contínua de colisões funciona da seguinte maneira: a partir de um número pré-definido de pontos intermediários entre a posição atual da bola e sua próxima posição, o algoritmo verifica se ocorrerá alguma colisão em cada ponto. Isso é feito ao calcular as coordenadas da bola em cada ponto intermediário e verificar se houve colisão com outros objetos do cenário.

Se uma colisão é detectada em algum ponto intermediário, a bola é movida para a posição onde ocorreu a colisão, e o tipo de colisão é informado para que a reflexão adequada seja realizada na próxima interação. Por outro lado, se nenhum ponto intermediário apresentar colisão, a bola realiza um movimento normal entre os quadros, sem nenhuma reflexão.


<div id="solucao-geral"> 
<h2> Solução Geral do projeto </h2>
<div align="justify">

<div id="testes"> 
<h2> Testes Realizados </h2>
<div align="justify">

<div id="conclusao"> 
<h2> Conclusão </h2>
<div align="justify">

<div id="execucaoProjeto"> 
<h2> Execução do Projeto  </h2>
<div align="justify">

<div id="referencias"> 
<h2> Referências  </h2>
<div align="justify">