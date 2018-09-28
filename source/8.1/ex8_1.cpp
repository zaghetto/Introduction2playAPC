#include <playAPC/playapc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAIO 5

int main(){
    Ponto p2, p1;
    int x, y;
    int grupo1, grupo2;
    int criouGrupo2;
    int colidiu;
    float distancia;
    float somaRaios;

    AbreJanela(600, 600, "Clicando");
    PintarFundo(255, 255, 255);
    srand(time(NULL));

    grupo1 = CriaGrupo();

    p1.x = 80;
    p1.y = 100;
    CriaQuadrado(RAIO*2, p1);
    Pintar(0, 0, 255);

    criouGrupo2 = 0;
    colidiu = 0;
    while(!colidiu){
        if(ApertouBotaoMouse(GLFW_MOUSE_BUTTON_LEFT)){
            PosicaoMouse(&x, &y);
            if(x < 80 && !criouGrupo2){
                grupo2 = CriaGrupo();
                p2.x = x;
                p2.y = y;
                CriaQuadrado(RAIO*2, p2);
                Pintar(rand()%256, rand()%256, rand()%256);
                criouGrupo2 = 1;
            }
        }

        if(p1.y > 100){
            p1.y = -100;
        }
        else{
            p1.y++;
        }
        Move(p1, grupo1);

        if(criouGrupo2){
            if(p2.x > 100){
                criouGrupo2 = 0;
            }
            else{
                Move(p2, grupo2);
                p2.x++;
            }

            somaRaios = RAIO + RAIO;
            distancia = sqrt(pow(p1.x - p2.x, 2) +  pow(p1.y - p2.y, 2));
            if(somaRaios > distancia){
                colidiu = 1;
            }
        }
        Desenha1Frame();
    }

    Desenha();

    return 0;
}
