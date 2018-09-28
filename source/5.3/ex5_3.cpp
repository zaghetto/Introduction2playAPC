#include <playAPC/playapc.h>
#include <stdlib.h>
#include <time.h>

#define LADOHEROI 30
#define LADOVILAO 50

int criaVilao(Ponto *p, int img){
    int vilao;
    srand (time(NULL));

    vilao = CriaGrupo();

    (*p).x = rand()%180;
    (*p).y = -65;
    CriaQuadrado(LADOVILAO, (*p));
    Pintar(255, 255, 255);
    AssociaImagem(img);

    return vilao;
}

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
    int fundo, heroi, vilao;
    int imgfundo, imgheroi1, imgvilao1;
    Ponto pHeroi, pVilao;

	AbreJanela(1000, 500, "Angry Birds");
	PintarFundo(255, 255, 255);

	imgfundo = AbreImagem("./bg.png");
	imgheroi1 = AbreImagem("./heroi1.png");
	imgvilao1 = AbreImagem("./vilao1.png");

    fundo = criaFundo(imgfundo);
    heroi = criaHeroi(&pHeroi, imgheroi1);
    vilao = criaVilao(&pVilao, imgvilao1);

	Desenha();

	return 0;
}

