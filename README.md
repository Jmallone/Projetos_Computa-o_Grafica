# Projetos_Computa-o_Grafica
Projetos da Materia de Computação Gráfica - [BCC35F]

## Dependências :running_man:
-[OpenGL](https://opengl.br.jaleco.com/)

:pencil: **Atividade Pratica 1**
<p align="center">
  <img src="/imgs/atv_1.gif">
</p>

**Descrição:**

> O programa ao executar deve mostrar um quadrado vermelho de lado 10 alinhado
ao canto inferior esquerdo da janela.
<br>O seu programa deve possibilitar duas transformações geométricas a serem executadas nesse quadrado: a translação e a rotação (centróide do quadrado como ponto de rotação).
<br><br>• Modo de translação: as teclas do teclado de setas ←, →, ↑ e ↓ devem alterar os fatores de translação tx e ty apropriadamente.
<br>• Modo de rotação: as teclas do teclado ← e → devem alterar o ângulo de rotação θ adequadamente. Adotando-se o centróide do quadrado como ponto de rotação, considerando-se eventuais transformações geométricas que ele possa ter sofrido anteriormente.
<br><br>Para transitar entre esses dois modos, o usuário deve pressionar a teclar ‘r’ para entrar no modo de rotação e a tecla ‘t’ para entrar no modo de translação. O programa começa no modo de translação, antes de qualquer tecla ser pressionada.

**Como executar:**

	gcc atv_pratica1.c -o main -lGL -lglut -lGLU
	./main

