#include <playAPC/playapc.h>
#define PASSO 10
#define INICIO_TELA -100
#define LARGURA_TELA 200

int main(){

    Ponto p1, p2;
    int barrinha, bolinha;
    int raio = 10, colidiu;
    int largura_ret = 30, altura_ret = 10;

    AbreJanela(600, 600, "Barrinha");
    PintarFundo(255, 255, 255);

    MostraPlanoCartesiano(10);

    bolinha = CriaGrupo();

    p1.x = INICIO_TELA  + raio + rand()%(LARGURA_TELA - raio);
    p1.y = INICIO_TELA ;

    CriaCirculo(raio, p1);
    Pintar(0, 0, 255);

    barrinha = CriaGrupo();

    p2.x = 0;
    p2.y = INICIO_TELA+20;

    CriaRetangulo(largura_ret, altura_ret, p1);
    Pintar(255, 0, 0);

    colidiu = 0;
    while(!colidiu){

        if(ApertouTecla(GLFW_KEY_LEFT)){
            p2.x-= PASSO;
        }

        if(ApertouTecla(GLFW_KEY_RIGHT)){
            p2.x+= PASSO;
        }

        if(p1.y-raio == p2.y+raio &&  p1.x >= p2.x && p1.x <= p2.x+largura_ret ){

            colidiu = 1;

        }

        if(p1.y < INICIO_TELA){
            p1.x = INICIO_TELA + raio + rand()%(LARGURA_TELA - raio);
            p1.y = -INICIO_TELA;
        }
        else{
            p1.y--;
        }
        Move(p1, bolinha);
        Move(p2, barrinha);

        Desenha1Frame();
    }

    Desenha();

    return 0;
}
