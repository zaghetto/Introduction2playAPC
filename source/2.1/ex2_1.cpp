#include <playAPC/playapc.h>

int main(){
    Ponto p1, p2;
	AbreJanela(500, 500, "Linha, Quadrado, Círculo");
	PintarFundo(255, 255, 255);

	MostraPlanoCartesiano(10);

	p1.x = -50;
	p1.y = -50;
	p2.x = 50;
	p2.y = 50;
	CriaReta(p1, p2);
	Pintar(255, 0, 0);

	p1.x = 50;
	p1.y = -80;
	CriaQuadrado(30, p1);
	Pintar(0, 255, 0);

	p1.x = -50;
	p1.y = 30;
	CriaCirculo(10, p1);
	Pintar(0, 0, 255);

	Desenha();

	return 0;
}
