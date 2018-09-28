#include <playAPC/playapc.h>

int criaFundo(int img){
    Ponto p;
    int fundo;

    fundo = CriaGrupo();

    p.x = -200;
    p.y = -100;
    CriaRetangulo(400, 200, p);
    Pintar(255, 255, 255);
    AssociaImagem(img);

    return fundo;
}

int main(){
    int fundo;
    int imgfundo;
	AbreJanela(1000, 500, "Angry Birds");
	PintarFundo(255, 255, 255);

	imgfundo = AbreImagem("./bg.png");

    fundo = criaFundo(imgfundo);

	Desenha();

	return 0;
}
