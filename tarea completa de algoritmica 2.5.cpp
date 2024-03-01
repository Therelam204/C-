// Isaac Ramirez C.I: 30.719.508 /  Jesus Gonzalez C.I:31.184.771 / Seccion 1410112

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <direct.h>
#include <iostream>
#include <time.h>
#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

void REGISTRO();
void CONSULTA();
void MODIFICAR();
void DESINCORPORAR();
void LISTADO();

struct { 

char NBP[6];
char NEQ;
char USEQ[25];
char DPTO[35];
char FEREG[9];
char FEMOD[9];
char FEDES[9];
char SERIAL[9];
char MARCA[9];

} PC;

FILE* PARCHI;
FILE* PAUXI;
FILE* DESIN;
FILE* APODOS;

int OPC, OPC1, OPC2, OPC3, OP4, OP5, RE;
char NBP [6];
char CNBP[6];
char RRC;
char OM;
char ednl;
char s;
char d;
char COMPA;

time_t tiempo=time(0);
struct tm * tlocal= localtime(&tiempo);

int main (){

do{
system("cls");
system("COLOR 0D");

cout<<("\t\t*******************************************\n\n");
cout<<( "\t\t\t\tCONTROL DE INVENTARIO DE EQUIPOS\n\n");
cout<<("\t\t\t1.INGRESAR DATOS DE UN EQUIPO\n");
cout<<("\t\t\t2.CONSULTAR DATOS DE UN EQUIPO\n");
cout<<("\t\t\t3.MODIFICAR DATOS DEL REGISTRO DE UN EQUIPO\n");
cout<<("\t\t\t4.DESINCORPORAR UN EQUIPO DEL INVENTARIO\n");
cout<<("\t\t\t5.LISTA DE EQUIPOS \n");

cout<<"\t\t\t6.SALIR.\n\n";

cout<<"\t\t\t\t\tELIJA UNA OPCION:"; 

cin>>OPC;

switch(OPC){

case 1:
REGISTRO();
break;

case 2:
CONSULTA();
break;

case 3:
MODIFICAR();
break;

case 4: 
DESINCORPORAR();
break; 

case 5: 
LISTADO();
break; 

case 6: 
cout<<"\t\t\t\t\n\n\nCERRANDO TODO Y SALIENDO";
sleep(600);
break;

default: 
cout<< ("\t\t\t\t\n\n\nOpción inválidad!\n");
cout<< ("\t\t\t\t\n\n\n");
system ("pause");
break;
}
}while (OPC!=6);

} 

void REGISTRAR() {
	 system("cls");
	 system("COLOR 0B");
	
APODOS = fopen ("Nombre. Archivo.txt", "a+");
PARCHI = fopen ("ARCHIVO INVENTARIO.txt", "a"); 

 do { 

cout<<("\t\t\t\tREGISTRO DE EQUIPOS\n\n\n\n"); 

cout<<("\t\tINGRESE NBP:"); 

cin>>NBP; 

cout<<"INGRESE USUARIO:";
gets(PC. USEQ);

 fprintf (APODOS, "%s %d %s %s %s %s %s\n", PC. NBP, PC. MARCA, PC. DPTO, PC.USEQ, PC.SERIAL, PC.FEREG, PC.FEMOD, PC. FEDES);


cout<<"REGISTRARA OTRO EQUIPO (1 Para SI)";

cin>>OPC1;
   
system("cls");
   
} while (OPC1==1);

fclose (PARCHI);

return;
} 


void CONSULTA (){
	
ifstream APODOS;      
APODOS.open("PARCHITA.txt", ios:: in);                                                                                                               

    system("cls");                                              
    system("COLOR 0F");
    
 cout<< "CONSULTA";                                                                                             

do{ 

char AVENBP; //averiguar numero de bien público

cout<<"Ingrese CNBP a consultar:";                                                                                  

cin>> CNBP;

        do { int COMPA; // consulta de numero de bien público
            APODOS>>PC.MARCA>>PC.NBP>>PC.USEQ>>PC.SERIAL>>PC.DPTO>>PC.FEREG>>PC.FEMOD>>PC.FEDES;

        COMPA= strcmp (PC.NBP, CNBP);
        if (COMPA == 0);{

 cout<<"MOSTRAR TODOS LOS CAMPOS";
       RE= 1;
  }

if ( RE == 0 &&  APODOS.eof() ){

 cout<<"REGRISTRO NO ENCOTRADO";
}

} while (! APODOS.eof () || RE == 0 );

cout<<"DESEA HACER OTRA BUSQUEDA";
    ("1 para si");
     char RRC; 

     cin >> RRC;

} while (RRC == '1');
APODOS. close (); 
cout<<"Saliendo de consulta";
  system("PAUSE");

return;
}



void MODIFICAR(){ 

    system("cls");
    system("COLOR 80");

    cout<< ("MODIFICADO"); 

ifstream PARCHI; 
ofstream PAUXI;  
PARCHI.open("PARCHITA.txt",ios::in);
PAUXI.open("PAUXILIAR.txt",ios::app);


do{char ModifBP[6];
int COMPA,RE;

cout<<"NumBP DE DATOS MODIFICADOS:"; 

cin>>ModifBP; 

do{ 
   PARCHI>>PC.NBP,PC.MARCA,PC.DPTO,PC.USEQ,PC.SERIAL,PC.FEREG,PC.FEMOD,PC. FEDES;

COMPA= strcmp (PC.NBP, ModifBP);

if (COMPA==0)
{RE=1;

    do{ "DATOS MODIFICADOS"; 

    cout<<"1 MARCA"<<endl; 
    cout<<"2 DEPARTAMENTO"<<endl;
    cout<<"3 USUARIO DEL EQUIPO"<<endl; 
    cout<<"4 ESCAPE"<<endl; 
    cout<<"ELIJA DATO QUE DESEA SER MODIFICADO"<<endl;

cin>>OPC3;

switch (OPC3){ 

case 1:
cout<<"ACTUAL MARCA"<<ednl; 
cin>> PC.MARCA;

case 2: 
cout<<"ACTUAL DEPARTAMENTO"<<endl; 
cin>>PC.MARCA;

case 3:
cout<<"ACTUAL USUARIO"<<endl;
cin>>PC.MARCA;

default: 
cout<<"OPCIÓN NO VÁLIDA"; 
system ("pause");

} 

}while (OPC3!=4);
strftime (PC.FEMOD,9,"%d/%m/%y",tlocal);

}
if (RE=0 && PARCHI.eof()){

cout<<"REGISTRO NO ENCONTRADO";
} system ("pause");

PAUXI<<PC.NBP<<PC.MARCA<<PC.SERIAL<<PC.USEQ<<PC.DPTO<<PC.FEREG<<PC.FEMOD<<PC.FEDES;

}while(!PARCHI.eof());

cout<<"Desea hacer otra Modificacion?(1 Para SI)"; 

char OM; 
cin>> OM; 

  }while (OM=='1'); 
PARCHI.close();
PAUXI.close();

remove("PARCHITA.txt");
rename("PAUXILIAR.txt","PARCHITA.txt");

return; 
} 

void LISTADO(){ 

system("cls");
system("COLOR 80");

APODOS = fopen("PARCHITA.txt" , "r"); 

printf ("NBP MARCA DPTO USUA SERIAL FEREG FEMOD FEDES \n\n\n");

do { fread (&PC, sizeof(PC),1,APODOS);

printf("%s%s%s%s%s%s%s%\n",PC.MARCA>>PC.NBP>>PC.USEQ>>PC.SERIAL>>PC.DPTO>>PC.FEREG>>PC.FEMOD>>PC.FEDES);

} while (!PARCHI.feof());

fclose (PARCHI);

return;
}


void DESINCORPORAR () { 

system("cls"); 
system("COLOR 0F"); 
 
ifstream APODOS; 
ifstream PARCHI; 
ofstream PAUXI; 
ofstream DESIN; 

PARCHI.open ("ARCHIVO.txt",ios::in); 
PAUXI.open ("AUXILIAR.txt",ios::app);
DESIN.open ("DESINCORPOR.txt",ios::app);
 
 
 
do{ char DBP[6], 
    int:RE=0;
    
cout<< "INGRESAR NBP"; 
cin>>DBP; 
 
  do{int DCOM;
        PARCHI>>PC.MARCA>>PC.NBP>>PC.USEQ>>PC.SERIAL>>PC.DPTO>>PC.FEREG>>PC.FEMOD>>PC.FEDES;
 
  DCOM=strcmp (PC.NBP,DBP); 
 
  if( DCOM=0){ 
   RE=1; 

  cout<<"NBP:"<<PC.NBP<<endl; 
  cout<<"\n\n MARCA"<<PC.MARCA; 
  cout<<"\n\n MODELO"<<PC.USEQ; 
  cout<<"\n\n SERIAL"<<PC.SERIAL;
  cout<<"\n\n USU"<<PC.DPTO;
  cout<<"\n\n FDES"<<PC.FEREG;
  cout<<"\n\n FDES"<<PC.FEMOD;
  cout<<"\n\n FDES"<<PC.FEDES;

    do{"DESEA DESINCORPORAR ESTE EQUIPO"; 
    cout<<"1 DESINCORPORAR."; 
    cout<< "2 DESEA NO DESINCORPORAR."; 
 
   cin>> OP4; 
 
   switch (OP4){ 
 
   case 1: 
   strftime (PC.FEDES,9, "%d/%m/%y", tlocal); 
 
   DESIN<<PC.NBP,PC.MARCA,PC.SERIAL,PC.USEQ,PC.DPTO,PC.FEREG,PC.FEMOD,PC.FEDES;
   cout<<"Equipo Desincorporado"; 
 
   system ("pause"); 
   break; 
 
   case 2: 
 
   PAUXI<<PC.NBP,PC.MARCA,PC.SERIAL,PC.USEQ,PC.DPTO,PC.FEREG,PC.FEMOD,PC.FEDES;
   cout: "DESEA NO DESINCORPORAR"; 
 
   deafault: 
   cout<<"Opción no valida"; 
 
} 
 
} while (OP4!=1 && OP4!=2); 

}if DCDM 

else{PAUXI<<PC.NBP,PC.MARCA,PC.SERIAL,PC.USEQ,PC.DPTO,PC.FEREG,PC.FEMOD,PC.FEDES;

} while ( !PARCHI.eof()); 
  if (RE==0 && PARCHI.eof()){
 
   cout<< "ESE NBP NO ESTA REGISTRADO";
   system("PAUSE");
}   

   char OP5; 
   cout<<"DESEA HACER REPETICION DE ESTE MODULO? (1 PARA SI)"; 
 
   cin>>OP5; 
 
} while (OP5== 1); 
 
PARCHI.close(); 
PAUXI.close(); 
DESIN.close(); 
remove("ARCHIVO.txt"); 
rename("AUXILAR.txt","ARCHIVO.txt");

return; 
}
}
