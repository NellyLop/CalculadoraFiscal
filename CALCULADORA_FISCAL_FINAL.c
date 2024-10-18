#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define RESET_COLOR "\x1b[0m"
#define AZUL_T "\x1b[34m"
#define ROJO_T "\x1b[31m"
#define MAGENTA_T  "\x1b[35m"
#define MAGENTA_F  "\x1b[45m"
#define VERDE_T        "\x1b[32m"
#define CYAN_T     "\x1b[36m"
#define AMARILLO_T "\x1b[33m"
#define VERDE_F        "\x1b[42m"
#define CYAN_F     "\x1b[46m"
void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void margen()
{
	gotoxy(42,3);printf(VERDE_T"~~ INFORMATICA SA DE CV ~~"RESET_COLOR);
	gotoxy(40,6);printf(AMARILLO_T"Calculadora Fiscal de ISR"RESET_COLOR);
	gotoxy(17,6);printf(MAGENTA_F"04/12/2023"RESET_COLOR);
    int x, y;
    x = 15;
    gotoxy(x, 1);
    printf(MAGENTA_T "%c", 201);
    gotoxy(x, 28);
    printf("%c", 200);
    // agregar margen al menú
    for (x = 16; x <= 90; x++)
    {
        gotoxy(x, 1);
        printf(MAGENTA_T "%c", 205);
        gotoxy(x, 28);
        printf("%c", 205);
    }
    for (y = 2; y <= 27; y++)
    {
        gotoxy(15, y);
        printf(MAGENTA_T "%c", 186);
        gotoxy(91, y);
        printf("%c", 186);
    }
    gotoxy(91, 1);
    printf(MAGENTA_T "%c", 187);
    gotoxy(91, 28);
    printf("%c", 188);
    x = 27;
    gotoxy(x, 2);
    printf("%c", 201);
    gotoxy(x, 4);
    printf("%c", 200);

    for (x = 28; x <= 83; x++)
    {
        gotoxy(x, 2);
        printf(MAGENTA_T "%c", 205);
        gotoxy(x, 4);
        printf("%c", 205);
    }

    gotoxy(27, 3);
    printf(MAGENTA_T "%c", 186);
    gotoxy(84, 3);
    printf("%c", 186);
    gotoxy(84, 2);
    printf("%c", 187);
    gotoxy(84, 4);
    printf("%c" RESET_COLOR, 188);
}
void datos(float salarioDiario,int diasF,int diasN,int exentas,int gravables)
{
	int otro;
	do{
	void margen();
	void cuadrito();
	float sueldo,extra,BaseG,Lim,Excedente,marginal,fija,ImpuestoC,credito,impuestoPagar;
	float porcentaje;
	float salarioD;
	int tipo;
	int goce,singoce,res,dias,inca;
	gotoxy(20,10);printf(CYAN_T"Salario Diario: "RESET_COLOR"$ ");
	scanf("%f",&salarioD);
	gotoxy(20,12);printf(CYAN_T"Calcular ISR para: "RESET_COLOR"[   ]");
	gotoxy(22,14);printf("1. Saldo quincenal");
	gotoxy(22,16);printf("2. Saldo mensual");
	gotoxy(41,12);scanf("%d",&tipo);
	printf(VERDE_T);
	gotoxy(47,27);system("pause");
	printf(RESET_COLOR);
	system("cls");
	margen();
		gotoxy(20,10);printf(CYAN_T"Salario diario: "RESET_COLOR" $%.2f",salarioD);
		gotoxy(20,12);printf(CYAN_T"> # dias efectivamente trabajados:  "RESET_COLOR);
		scanf("%d",&dias);
		gotoxy(22,14);printf(CYAN_T"> # dias de incapacidad:  "RESET_COLOR);
		scanf("%d",&inca);
		gotoxy(22,16);printf(CYAN_T">> Permiso con goce de sueldo:  "RESET_COLOR);
		scanf("%d",&goce);
		gotoxy(22,18);printf(CYAN_T">> Permiso sin goce de sueldo:  "RESET_COLOR);
		scanf("%d",&singoce);
		if (inca>0 &&inca<=3)
		{
			diasF=dias+goce+inca;
			gotoxy(67,12);printf(VERDE_T"Dias a pagar: "RESET_COLOR"%d",diasF);
		}else if(inca>3){
			diasF=dias+goce+3;
			diasN=inca-3;
			gotoxy(67,12);printf(VERDE_T"Dias a pagar: "RESET_COLOR"%d",diasF);
			gotoxy(67,14);printf(ROJO_T"Dias no pagados: "RESET_COLOR"%d",diasN);
		}else{
		diasF=dias;
		gotoxy(67,12);printf(VERDE_T"Dias a pagar: "RESET_COLOR"%d",diasF);
		}
		gotoxy(20,20);printf(CYAN_T"> Percepciones excentas: $ "RESET_COLOR);
		scanf("%d",&exentas);
		gotoxy(20,22);printf(CYAN_T"> Percepciones gravables: "RESET_COLOR"$ ");
		scanf("%d",&gravables);
		printf(VERDE_T);
		gotoxy(47,27);system("pause");
		printf(RESET_COLOR);
		system("cls");
		margen();	
	if(tipo==1)
	{
		sueldo=salarioD*diasF;
		gotoxy(20,10);printf(CYAN_T"Salario Quincenal: "RESET_COLOR"$ %.2f\n",sueldo);
		extra=gravables;
		BaseG=sueldo+extra;
		gotoxy(20,12);printf(CYAN_T"Base Gravable:"RESET_COLOR" $ %.2f\n",BaseG);	
		if (BaseG>=0.01 && BaseG<= 368.10)
		{
        	Lim= 0.01;
        	porcentaje=1.92;
        	fija=0;
    	} 
		if (BaseG>=368.11 && BaseG<= 3124.35)
		{
        	Lim=368.11;
        	porcentaje=6.40;
        	fija=7.05;
    	} 
		if (BaseG>=3124.36 && BaseG<= 5490.75)
		{
        	Lim=3124.36;
        	porcentaje=10.88;
        	fija=183.45;
        } 
		if (BaseG>=5490.76 && BaseG<= 6382.80)
		{
        	Lim=5490.76;
        	porcentaje=16.00;
        	fija=441.00;
    	} 
		if (BaseG>=6382.81 && BaseG<=7641.90)
		{
        	Lim=6382.81;
        	porcentaje=17.92;
        	fija=583.65;
    	}
    		if (BaseG>=7641.91 && BaseG<=15412.80)
		{
        	Lim=7641.91;
        	porcentaje=21.36;
        	fija=809.25;
    	}
    		if (BaseG>=15412.81 && BaseG<=24292.65)
		{
        	Lim=15412.81;
        	porcentaje=23.52;
        	fija=2469.15;
    	}
    		if (BaseG>=24292.66 && BaseG<=46378.50)
		{
        	Lim=24292.66;
        	porcentaje=30.00;
        	fija=4557.75;
    	}
			if (BaseG>=46378.51 && BaseG<=61838.10)
		{
        	Lim=46378.51;
        	porcentaje=32.00;
        	fija=11183.40;
    	}
    		if (BaseG>=61838.11 && BaseG<=185514.30)
		{
        	Lim=61838.11;
        	porcentaje=34.00;
        	fija=16130.55;
    	}
    		if (BaseG>=185514.31)
		{
        	Lim=185514.31;
        	porcentaje=35.00;
        	fija=58180.35;
    	} 
		 
    	
		gotoxy(20,14);printf(CYAN_T"Limite inferior:"RESET_COLOR" $ %.2f ",Lim);
		Excedente=BaseG-Lim;
		gotoxy(20,16);printf(CYAN_T"Excedente: "RESET_COLOR"$ %.2f ",Excedente);
		marginal=(Excedente * porcentaje)/100;
		gotoxy(20,18);printf(CYAN_T"Marginal: "RESET_COLOR"$ %.2f ",marginal);
		ImpuestoC=marginal+fija;
		gotoxy(20,20);printf(CYAN_T"Impuesto a cargo: "RESET_COLOR"$ %.2f ",ImpuestoC);
		
		if (sueldo>=0.01 && sueldo<= 872.85)
		{
			credito=200.85;
    	} 
		if (sueldo>=872.86 && sueldo<= 1309.20)
		{
			credito=200.70;
        } 
		if (sueldo>=1309.21 && sueldo<= 1713.60)
		{
			credito=200.70;
		} 
		if (sueldo>=1713.61 && sueldo<=1745.70 )
		{
			credito=193.80;
    	} 
		if (sueldo>=1745.71 && sueldo <=2193.75)
		{
			credito=188.70;
        } 
    	if (sueldo>=2193.76 && sueldo <=2327.55)
		{
			credito=174.75;
		} 
    	if (sueldo>=2327.56 && sueldo <=2632.65)
		{
			credito=160.35;
    	}
    	if (sueldo>=2632.66 && sueldo <=3071.40)
		{
			credito=145.35;
    	}
    	if (sueldo>=3071.41 && sueldo <=3510.15)
		{
			credito=125.10;
    	} 
    	if (sueldo>=3510.16 && sueldo <=3642.60)
		{
			credito=107.40;
    	} 
    	if (sueldo>=3642.61)
		{
			credito=0;
    	} 

		gotoxy(20,22);printf(CYAN_T"Credito al salario: "RESET_COLOR"$ %.2f",credito);
		impuestoPagar=ImpuestoC-credito;
		gotoxy(60,14);printf(VERDE_T"Impuesto a pagar: "RESET_COLOR);
		gotoxy(62,16);printf(" $ %.2f",impuestoPagar);
		gotoxy(37,8);printf(ROJO_T"Actualize la tabla dentro de 27 dias"RESET_COLOR);
		cuadrito();
		gotoxy(20,25);printf(VERDE_T"Desea otro calculo: "RESET_COLOR "1. Si / 2. No  [   ]");
		gotoxy(57,25);scanf("%d",&otro);
		printf(VERDE_T);
		gotoxy(47,27);system("pause");
		printf(RESET_COLOR);
		system("cls");		
	}else if(tipo==2)
	{
		sueldo=salarioD*diasF;
		gotoxy(20,10);printf(CYAN_T"Salario Mensual: "RESET_COLOR"$ %.2f\n",sueldo);
		extra=gravables;
		BaseG=sueldo+extra;	
		gotoxy(20,12);printf(CYAN_T"Base Gravable:"RESET_COLOR" $ %.2f\n",BaseG);
		if (BaseG>=0.01 && BaseG<= 746.04)
		{
        	Lim= 0.01;
        	porcentaje=1.92;
        	fija=0;
    	} 
		if (BaseG>=746.05 && BaseG<= 6332.05)
		{
        	Lim=746.05;
        	porcentaje=6.40;
        	fija=14.32;
    	} 
		if (BaseG>=6332.06 && BaseG<= 11128.01	)
		{
        	Lim=6332.06;
        	porcentaje=10.88;
        	fija=371.83;
        } 
		if (BaseG>=11128.02 && BaseG<= 12935.82)
		{
        	Lim=11128.02;
        	porcentaje=16.00;
        	fija=893.63;
    	}
    	if (BaseG>=12935.83 && BaseG<= 15487.71)
		{
        	Lim=12935.83;
        	porcentaje=17.92;
        	fija=1182.88;
    	}
    	if (BaseG>=15487.72 && BaseG<= 31236.49)
		{
        	Lim=15487.72;
        	porcentaje=21.36;
        	fija=1640.18;
    	}
    	if (BaseG>=31236.50 && BaseG<= 49233.00)
		{
        	Lim=31236.50;
        	porcentaje=23.52;
        	fija=5004.12;
    	} 
    	if (BaseG>=49233.01 && BaseG<= 93993.90)
		{
        	Lim=49233.01;
        	porcentaje=30.00;
        	fija=9236.89;
    	}
    	if (BaseG>=93993.91 && BaseG<= 125325.20)
		{
        	Lim=93993.91;
        	porcentaje=32.00;
        	fija=22665.17;
    	}
		if (BaseG>=125325.21 && BaseG<= 375975.61)
		{
        	Lim=125325.21;
        	porcentaje=34.00;
        	fija=32691.18;
    	}
    	if (BaseG>=375975.62	)
		{
        	Lim=375975.62	;
        	porcentaje=35.00;
        	fija=117912.32;
    	} 
	
		gotoxy(20,14);printf(CYAN_T"Limite inferior:"RESET_COLOR" $ %.2f ",Lim);
		Excedente=BaseG-Lim;
		gotoxy(20,16);printf(CYAN_T"Excedente: "RESET_COLOR"$ %.2f ",Excedente);
		marginal=(Excedente * porcentaje)/100;
		gotoxy(20,18);printf(CYAN_T"Marginal: "RESET_COLOR"$ %.2f ",marginal);
		ImpuestoC=marginal+fija;
		gotoxy(20,20);printf(CYAN_T"Impuesto a cargo: "RESET_COLOR"$ %.2f ",ImpuestoC);
		
		if (sueldo>=0.01 && sueldo<= 1768.96)
		{
			credito=407.02;
    	} 
		if (sueldo>=1768.97 && sueldo<= 2653.38)
		{
			credito=406.83;
        } 
		if (sueldo>=2653.39 && sueldo<= 3472.84)
		{
			credito=406.62;
		} 
		if (sueldo>=3472.85 && sueldo<= 3537.87)
		{
			credito=392.77;
    	} 
		if (sueldo>=3537.88 && sueldo <=4446.15)
		{
			credito=382.46;
        } 
    	if (sueldo>=4446.16 && sueldo <=4717.18)
		{
			credito=354.23;
		} 
    	if (sueldo>=4717.19 && sueldo <=5335.42)
		{
			credito=324.87;
    	}
    	if (sueldo>=5335.43 && sueldo <=6224.67)
		{
			credito=294.63;
    	}
    	if (sueldo>=6224.68 && sueldo <=7113.90)
		{
			credito=253.54;
    	} 
    	if (sueldo>=7113.91 && sueldo <=7382.33)
		{
			credito=217.61;
    	} 
    	if (sueldo>=7382.34)
		{
			credito=0;
    	} 
		gotoxy(20,22);printf(CYAN_T"Credito al salario: "RESET_COLOR"$ %.2f",credito);
		impuestoPagar=ImpuestoC-credito;
		gotoxy(60,14);printf(VERDE_T"Impuesto a pagar: "RESET_COLOR);
		gotoxy(62,16);printf(" $ %.2f",impuestoPagar);
		cuadrito();
		gotoxy(37,8);printf(ROJO_T"Actualize la tabla dentro de 27 dias"RESET_COLOR);
		gotoxy(20,25);printf(VERDE_T"Desea otro calculo: "RESET_COLOR "1. Si / 2. No  [   ]");
		gotoxy(57,25);scanf("%d",&otro);
		printf(VERDE_T);
		gotoxy(47,27);system("pause");
		printf(RESET_COLOR);
		system("cls");	
	}
	margen();
}while(otro==1);

}

void cuadrito()
{
	int x, y;
    x = 58;
    gotoxy(x, 15);
    printf(AMARILLO_T "%c", 218);
    gotoxy(x, 17);
    printf("%c"RESET_COLOR, 192);
    
    for (x = 59; x <= 78; x++)
    {
        gotoxy(x, 15);
        printf(AMARILLO_T "%c", 196);
        gotoxy(x, 17);
        printf(AMARILLO_T "%c", 196);
    }
    for (y = 16; y <= 16; y++)
    {
        gotoxy(58, y);
        printf(AMARILLO_T "%c", 179);
        gotoxy(79, y);
        printf(AMARILLO_T "%c", 179);
       
    }
    gotoxy(79, 15);
    printf(AMARILLO_T "%c", 191);
    gotoxy(79, 17);
    printf("%c"RESET_COLOR,217 );

	
}


void pausa()
{
	gotoxy(40,14);printf(ROJO_T"Saliendo del programa"RESET_COLOR);
	sleep(2);
	gotoxy(40,14);printf("                       ");
	system("cls");
	
}
int main() {
	int diasF,diasN,exentas,gravables;
	float sueldo,salarioDiario;
	margen();
	datos(salarioDiario,diasF,diasN,exentas,gravables);
	pausa();
    return 0;
}
