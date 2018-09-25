#include <playAPC/playapc.h>

#define LARGURA 30

int criaChao(){
    Ponto p;
    int chao;

    chao = CriaGrupo();
    p.x = -100;
    p.y = -100;

    CriaRetangulo(200, 30, p);
    Pintar(83, 187, 68);

    return chao;

}

int criaInimigo(Ponto *p){
    int inimigo;

    inimigo = CriaGrupo();
    (*p).x = 60;
    (*p).y = -80;

    CriaQuadrado(LARGURA, (*p));
    Pintar(255, 0, 0);

    return inimigo;

}

int criaHeroi(Ponto *p){
    int heroi;

    heroi = CriaGrupo();
    (*p).x = -100;
    (*p).y = -80;

    CriaQuadrado(LARGURA, (*p));
    Pintar(0, 0, 255);

    return heroi;
}

int main(){
    int heroi, inimigo, chao;
    Ponto pHeroi, pInimigo;
    int colidiu;

    AbreJanela(500, 500, "Colisão");
	PintarFundo(255, 255, 255);
	MostraPlanoCartesiano(10);

	chao = criaChao();
	heroi = criaHeroi(&pHeroi);
	inimigo = criaInimigo(&pInimigo);

	colidiu = 0;
	do{
        if(pHeroi.x + LARGURA >= pInimigo.x){
            colidiu = 1;
        }
        else{
            pHeroi.x++;
            Move(pHeroi, heroi);
        }
        Desenha1Frame();
	}while(!colidiu);

	Desenha();

    return 0;
}
