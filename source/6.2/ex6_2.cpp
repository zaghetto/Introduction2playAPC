#include <playAPC/playapc.h>
#include <stdlib.h>
#include <time.h>

#define LADOHEROI 30
#define LADOVILAO 50
#define CHAO -65

int criaVilao(Ponto *p, int img){
    int vilao;
    srand (time(NULL));

    vilao = CriaGrupo();

    (*p).x = rand()%180;
    (*p).y = CHAO;
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

int colidiuChao(Ponto pHeroi){

    if(pHeroi.y <= CHAO){
        return 1;
    }
    return 0;
}

int main(){
    int fundo, heroi, vilao;
    int imgfundo, imgheroi1, imgvilao1;
    Ponto pHeroi, pVilao;
    float theta, v0, t;
    int colisao;

	AbreJanela(1000, 500, "Angry Birds");
	PintarFundo(255, 255, 255);

	imgfundo = AbreImagem("./bg.png");
	imgheroi1 = AbreImagem("./heroi1.png");
	imgvilao1 = AbreImagem("./vilao1.png");

    fundo = criaFundo(imgfundo);
    heroi = criaHeroi(&pHeroi, imgheroi1);
    vilao = criaVilao(&pVilao, imgvilao1);

    Desenha1Frame();

    printf("Digite o angulo (0, 360): ");
    scanf("%f", &theta);

    printf("Digite a velocidade inicial: ");
    scanf("%f", &v0);

    theta = theta* PI/180;
    colisao = 0;
    t = 0;
    do{
        pHeroi.x = pHeroi.x + v0 * cos(theta) * t;
        pHeroi.y = pHeroi.y + v0 * sin(theta) * t - ((1/2.0) * (9.8) * (t*t));
        Move(pHeroi, heroi);
        t += 0.1;

        colisao = colidiuChao(pHeroi);

        Desenha1Frame();
    }while(!colisao);

    printf("Fim de jogo");
	Desenha();

	return 0;
}
