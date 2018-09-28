#include <playAPC/playapc.h>
#define LADOHEROI 30

int criaHeroi(Ponto *p, int img){
    int heroi;

    heroi = CriaGrupo();

    (*p).x = -155;
    (*p).y = -10;
    CriaQuadrado(LADOHEROI, (*p));
    Pintar(255, 255, 255);
    AssociaImagem(img);

    return heroi;
}

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
    int fundo, heroi;
    int imgfundo, imgheroi1;
    Ponto pHeroi;

	AbreJanela(1000, 500, "Angry Birds");
	PintarFundo(255, 255, 255);

	imgfundo = AbreImagem("./bg.png");
	imgheroi1 = AbreImagem("./heroi1.png");

    fundo = criaFundo(imgfundo);
    heroi = criaHeroi(&pHeroi, imgheroi1);

	Desenha();

	return 0;
}
