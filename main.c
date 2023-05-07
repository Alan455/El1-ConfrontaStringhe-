/*********************************************************************************
 *                                                                               *
 *                   Architetture dei sistemi di Elaborazione                    *
 *                                                                               *
 *********************************************************************************

 Elaborato 1
 Descrizione:	Data una stringa C (terminata dal carattere nullo), contenente una
			frase (ossia parole separate da spazi e/o segni di punteggiatura),
			trovare la parola più lunga e la parola più corta. In caso di parole
			di uguale lunghezza, considerare la prima da sinistra.
			Le due parole vanno copiate in due array di caratteri come stringhe
			C (terminate dal carattere nullo).
			I segni di punteggiatura da considerare sono: ".,;:'?!"

 **********************************************************************************/


#include <stdio.h>


void main()
{
#define MAX_LEN	100
	char frase[MAX_LEN] = "Cantami, o Diva, del Pelide Achille l'ira funesta che infiniti addusse lutti agli Achei";
	char parolaMax[MAX_LEN + 1];
	char parolaMin[MAX_LEN + 1];
	__asm
	{
			XOR EAX,EAX //indice frase
			XOR ECX,ECX //contalettere
			XOR EDX,EDX //DH MaxParola/DL MinParola
			XOR EBX,EBX //BH temp//BL
			XOR ESI,ESI //puntatore alla parola corrente
			XOR EDI,EDI //
			LEA ESI,parolaMin-112
	indiceFrase:
			CMP frase[EAX],33
			JZ trovatoSeparatore
			CMP frase[EAX],39
			JZ trovatoSeparatore
			CMP frase[EAX],44
			JZ trovatoSeparatore
			CMP frase[EAX],46
			JZ trovatoSeparatore
			CMP frase[EAX],32
			JZ trovatoSeparatore
			CMP frase[EAX],58
			JZ trovatoSeparatore
			CMP frase[EAX],59
			JZ trovatoSeparatore
			CMP frase[EAX],63
			JZ trovatoSeparatore
			MOV BH,frase[EAX]
			MOV [ESI],BH
			INC ESI //incrementa il puntatore alla parola corrente
			INC ECX //conta il numero di caratteri della parola corrente
			INC EAX  //mantiene l'indice della frase
			CMP frase[EAX],-52 //il vettore è finito?
			JNE indiceFrase
	trovatoSeparatore:
			MOV[ESI],32 //aggiungo il \0 alla parola
			CMP CL,DH  //MaxParola
			JG aggiornaParolaMax //se l'indice della parola corrente è maggiore di MAXPAROLA allora jump
	controllaMin:
			CMP CL,DL	 //MinParola
			JL aggiornaParolaMin //se l'indice della parola corrente è minore di MinParola allora jump

	aggiornaParolaMax:
			LEA ESI,parolaMin - 112
			LEA EDI,parolaMax
			REP MOVS
			//JNZ aggiornaParolaMax
			//JMP controllaMin
	aggiornaParolaMin:



	}
	printf("%s\n%s\n",parolaMax, parolaMin);

}

