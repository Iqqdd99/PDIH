#include <dos.h>

#define BYTE unsigned char

BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

// hace una pausa
void pausa(void){
   union REGS inregs, outregs;
   inregs.h.ah = 0x00;
   int86(0x16, &inregs, &outregs);
}

// establece el modo de vídeo: 3-texto, 4-gráfico
void modovideo(BYTE modo){
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

//TODO

//coloca el cursor en una posición determinada
void my_gotoxy(void){

}

//fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO
void my_setcursortype(void){

}

//fija el modo de video deseado
void my_setvideomode(void){

}

//obtiene el modo de video actual
void my_getvideomode(void){

}

//modifica el color de primer plano con que se mostrarán los caracteres
void my_textcolor(void){

}

//modifica el color de fondo con que se mostrarán los caracteres
void my_textbackground(void){

}

//borra toda la pantalla
void my_clrscr(void){

}

//escribe un carácter en pantalla con el color indicado actualmente
void my_cputchar(void){

}

//obtiene un carácter de teclado y lo muestra en pantalla
void my_getche(void){

}

//EXTRA

//Permite dibujar un recuadro en la	pantalla en	modo texto.
// Params: coordenada superior izquierda, coordenada inferior derecha del recuadro,
//  color de primer plano y el color de fondo.

void textborder(void){

}

//Establece el modo VGA para crear dibujos sencillos en pantalla
void setDrawVGA(void){

}

int main(){
   int i;
   
    modovideo(MODOTEXTO);
    pausa();


    return 0;
}
