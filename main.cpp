#include <iostream>
#include <cmath>
#include <string.h>
#include <windows.h>
#include "conio.h"
#include <math.h>
#define pi 3.14159265

using namespace std;

int  sx,sy,vx,vy;;
float a3,dx,dy;

class vetores {
    int abicissa, ordenada;

  	public:
    	void set_values (float,float);

    	void set_xy();

    	float coordenada1() {return abicissa;}

    	float coordenada2() {return ordenada;}

    	float modulo() {

    		float a1=abicissa * abicissa;
    		float a2=ordenada * ordenada;

			a3=sqrt(a1+a2);

			return a3;
		}

};

vetores vet1;
vetores vet2;
vetores vetsoma;
vetores vetsub;
vetores vetmult;
vetores vetmult1;
vetores vetmult2;
vetores versor1;
vetores versor2;

void voltamenu(){

	cout << "precione qualquer tecla para voltar ao menu";
	getch();
	system("cls");
}

void vetores::set_values (float x, float y) {
  	abicissa = x;
  	ordenada = y;
}

void vetores::set_xy(){
	vx = abicissa;
	vy = ordenada;
}

void somavetor(){

	system("cls");
	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx + vx;
	sy = sy + vy;

	vetsoma.set_values(sx,sy);

	cout << "vetor 1: ("<<vet1.coordenada1()<<","<<vet1.coordenada2()<<")"<<endl;
	cout << "vetor 2: ("<<vet2.coordenada1()<<","<<vet2.coordenada2()<<")"<<endl;

	cout << "vetor Soma: ("<<vetsoma.coordenada1()<<","<<vetsoma.coordenada2()<<")"<<endl;

	voltamenu();

}

void subtraivetor(){

	system("cls");
	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx - vx;
	sy = sy - vy;

	vetsub.set_values(sx,sy);

	cout << "vetor 1: ("<<vet1.coordenada1()<<","<<vet1.coordenada2()<<")"<<endl;
	cout << "vetor 2: ("<<vet2.coordenada1()<<","<<vet2.coordenada2()<<")"<<endl;

	cout << "vetor Subtracao: ("<<vetsub.coordenada1()<<","<<vetsub.coordenada2()<<")"<<endl;

	voltamenu();

}

void declaravetor(){

	int x,y;
	system("cls");
	cout << "Digite as coordenadas do vetor 1:" << endl;
	cin >> x;
	cin >> y;
	vet1.set_values(x,y);

	cout << "Digite as coordenadas do vetor 2:" << endl;
	cin >> x;
	cin >> y;
	vet2.set_values(x,y);

	cout << "vetor 1: ("<<vet1.coordenada1()<<","<<vet1.coordenada2()<<")"<<endl;
	cout << "vetor 2: ("<<vet2.coordenada1()<<","<<vet2.coordenada2()<<")"<<endl;

	voltamenu();


}

void escalavetor(){
	int cont=0,E;

	while(cont!=1 && cont!=2){

		system("cls");
		cout << "Digite qual vetor deseja multiplicar por um escalar:" << endl;
		cout << " 1.Vetor 1." << endl;
		cout << " 2.Vetor 2." << endl;
		cin >> cont;
		system("cls");
		cout << "Digite o valor pelo qual o vetor sera multiplicado:" << endl;
		cin >> E;
		switch (cont){

			case 1:
				vet1.set_xy();
				vx = vx * E;
				vy = vy * E;
				vetmult1.set_values(vx,vy);

				cout << "vetor 1: ("<<vet1.coordenada1()<<","<<vet1.coordenada2()<<")"<<endl;
				cout << "vetor Multiplicado: ("<<vetmult1.coordenada1()<<","<<vetmult1.coordenada2()<<")"<<endl;

				voltamenu();

			break;
			case 2:
				vet2.set_xy();
				vx = vx * E;
				vy = vy * E;
				vetmult2.set_values(vx,vy);

				cout << "vetor 2: ("<<vet2.coordenada1()<<","<<vet2.coordenada2()<<")"<<endl;
				cout << "vetor Multiplicado: ("<<vetmult2.coordenada1()<<","<<vetmult2.coordenada2()<<")"<<endl;

				voltamenu();

			break;
			default:cout<<"opcao invalida,precione qualquer botao para selecionar novamente" <<endl;getch();break;

		}
	}

}

void multvetor(){

	system("cls");
	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx * vx;
	sy = sy * vy;

	vetmult.set_values(sx,sy);

	cout << "vetor 1: ("<<vet1.coordenada1()<<","<<vet1.coordenada2()<<")"<<endl;
	cout << "vetor 2: ("<<vet2.coordenada1()<<","<<vet2.coordenada2()<<")"<<endl;

	cout << "vetor Multiplicação: ("<<vetmult.coordenada1()<<","<<vetmult.coordenada2()<<")"<<endl;

	voltamenu();

}

void modulovetor(){

	int cont=0;

	while(cont!=1 && cont!=2){


		system("cls");
		cout << "Digite qual vetor :" << endl;
		cout << " 1.Vetor 1." << endl;
		cout << " 2.Vetor 2." << endl;
		cin >> cont;
		system("cls");

		switch (cont){
			case 1:cout << "Modulo do vetor 1: "<< vet1.modulo() <<endl;break;
			case 2:cout << "Modulo do vetor 2: "<<  vet2.modulo() <<endl;break;
			default:cout<<"opcao invalida" <<endl;system("cls");break;

		}
	}
	voltamenu();
}

void versor(){
	
	float p[2], soma=0.0;
	int i,cont=0;
	system("cls");
	cout << "Digite qual vetor :" << endl;
	cout << " 1.Vetor 1." << endl;
	cout << " 2.Vetor 2." << endl;
	cin >> cont;
	system("cls");

	switch (cont){
		
		case 1:
			vet1.set_xy();
			p[0]=vx;
			p[1]=vy;
			
			printf("O versor e (");
			for(i=0;i<2;i++){
				soma=soma+(p[i]*p[i]);
			}
			for(i=0;i<2;i++){
				
				printf(" %.2f", p[i]/sqrt(soma));
			}
			printf(") \n\n");

		break;
		case 2:
			
			vet2.set_xy();
			p[0]=vx;
			p[1]=vy;
			
			printf("\n");
			printf("O versor e (");
			for(i=0;i<2;i++){
				soma=soma+(p[i]*p[i]);
			}
			for(i=0;i<2;i++){
				printf(" %.2f", p[i]/sqrt(soma));
			}
			printf(") \n\n");
		
		break;
		default:cout<<"opcao invalida" <<endl;system("cls");break;

	}
	voltamenu();
	}

void pescalar(){

	int escalar;

	system("cls");
	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx * vx;
	sy = sy * vy;
	escalar = sx + sy;

	cout <<"O produto escalar e: "<<escalar<<endl;

	voltamenu();

}

void angulo(){
	system("cls");
	float p[2],q[2], soma=0.0, soma2=0.0, soma3=0.0, ang;
	int i;
	
	vet1.set_xy();
	p[0]=vx;
	p[1]=vy;
	vet2.set_xy();
	q[0]=vx;
	q[1]=vy;
	
	for(i=0;i<2;i++){
		soma=soma+(p[i]*p[i]);
		soma2=soma2+(q[i]*q[i]);
		soma3=soma3+(p[i]*q[i]);
	}
		ang=acos((soma3)/(sqrt(soma*soma2)));
		printf("\n O angulo e %.2f graus\n\n", (180*ang)/pi);
		voltamenu();
}

void pop(){
	int p1,p2,p3,p4;

	system("cls");
	int escalar,a,b;;

	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx * vx;
	sy = sy * vy;
	escalar = sx + sy;

	vet1.set_xy();
	a = vx;
	b = vy;
	vet2.set_xy();

	p1 = a % vx;
	p2 = b % vy;
	p3 = vx % a;
	p4 = vy % b;

	if( p1==0 && p2==0 ){
		cout << "Vetores paralelos,";

	}else if( p3==0 && p4==0){
		cout << "Vetores paralelos,";

	}else cout << "Vetores nao paralelos,";

	if(escalar == 0){
		cout << "e Vetores Ortogonais"<<endl;
	}else cout << "e Vetores nao ortogonais"<<endl;

	voltamenu();
}

void pinterno(){

	int escalar;

	system("cls");
	vet1.set_xy();
	sx = vx;
	sy = vy;
	vet2.set_xy();
	sx = sx * vx;
	sy = sy * vy;
	escalar = sx + sy;

	cout <<"O produto interno e: "<<escalar<<endl;

	voltamenu();
}

void norma (){
	int cont=0;

	while(cont!=1 && cont!=2){


		system("cls");
		cout << "Digite qual vetor :" << endl;
		cout << " 1.Vetor 1." << endl;
		cout << " 2.Vetor 2." << endl;
		cin >> cont;
		system("cls");

		switch (cont){
			case 1:cout << "Norma do vetor 1: "<< vet1.modulo() <<endl;break;
			case 2:cout << "Norma do vetor 2: "<<  vet2.modulo() <<endl;break;
			default:cout<<"opcao invalida" <<endl;system("cls");break;

		}
	}
	voltamenu();
}

int main () {
	int menu=20;

	while(menu!=0){

		cout << "Bem Vindo,Selecione uma opçao:" << endl;
		cout << "  1.Declarar Vetores." << endl;
		cout << "  2.Somar Vetores." << endl;
		cout << "  3.Subtrair Vetores." << endl;
		cout << "  4.Multiplicar vetor por escalar." << endl;
		cout << "  5.Multiplicar vetores." << endl;
		cout << "  6.Modulo do Vetor." << endl;
		cout << "  7.Versor." << endl;
		cout << "  8.Produto Escalar." << endl;
		cout << "  9.Angulo Entro os vetores." << endl;
		cout << "  10.Paralelismo, ortogonalidade e perpendicularismo." << endl;
		cout << "  11.Calcular produto interno." << endl;
		cout << "  12.Norma Dos vetores." << endl;
		cout << "  13.Ver Cabecalho." << endl;
		cout << "  0.Sair." << endl;
		cin >> menu;

		switch(menu){

			case 1:declaravetor();break;

			case 2:somavetor();break;

			case 3:subtraivetor();break;

			case 4:escalavetor();break;

			case 5:multvetor();break;

			case 6:modulovetor();break;

			case 7:versor();break;

			case 8:pescalar();break;

			case 9:angulo();break;

			case 10:pop();break;

			case 11:pinterno();break;

			case 12:norma();break;

			case 13:
                system("cls");
                cout << "Unifacs-Universidade Salvador" << endl;
                cout << "Avaliacao de Linguagem de  Progamacao" << endl;
                cout << "Marcos Henrique Lordelo Marques" << endl;
                cout << "Pablo Rufat Munoz " << endl;
                cout <<"Questao 4\n"<< endl;
                cout << "Precione qualquer tecla para voltar ao menu:" <<endl;
                getch();
                system("cls");
            break;
		}
	}

  	return 0;
}
