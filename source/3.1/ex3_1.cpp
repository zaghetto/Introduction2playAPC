#include <playAPC/playapc.h>

int criaBonecoDeNeve(){
    Ponto p1, p2;
    int boneco;

    boneco = CriaGrupo();

    p1.x = 0;
	p1.y = -50;
	CriaCirculo(50, p1);
	Pintar(255, 255, 255);

	p1.x = 0;
	p1.y = 15;
	CriaCirculo(25, p1);
	Pintar(255, 255, 255);

    p1.x = 0;
	p1.y = 50;
	CriaCirculo(15, p1);
	Pintar(255, 255, 255);

	p1.x = -10;
	p1.y = 50;
	CriaCirculo(2, p1);
	Pintar(0, 0, 0);

	p1.x = 10;
	p1.y = 50;
	CriaCirculo(2, p1);
	Pintar(0, 0, 0);

	p1.x = -20;
	p1.y = 60;
	CriaRetangulo(40, 5, p1);
	Pintar(147, 127, 90);

	p1.x = -10;
	p1.y = 60;
	CriaRetangulo(20, 30, p1);
	Pintar(147, 127, 90);

	p1.x = 20;
	p1.y = 30;
	p2.x = 50;
	p2.y = -10;
	CriaReta(p1, p2);
	Pintar(70, 49, 21);
	Grafite(3);

	p1.x = -20;
	p1.y = 30;
	p2.x = -50;
	p2.y = -10;
	CriaReta(p1, p2);
	Pintar(70, 49, 21);
	Grafite(3);

	return boneco;
}

int main(){
    Ponto p;
    int boneco;

	AbreJanela(300, 300, "Boneco de neve");
	PintarFundo(232, 232, 232);

	boneco = criaBonecoDeNeve();

    p.x = -100;
    p.y = -80;
    for(float i = -100; i < 200; i++){
        Move(p, boneco);
        p.x = i;
        Desenha1Frame();
    }

	Desenha();

	return 0;
}
