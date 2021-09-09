#include <iostream>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compteur = 0, name_error_compteur = 0;
char temp_prenom[99] = "";
char no_valid_name[99] = "XAEA-XII";
char exit_code[99] = "EXIT";
float temp_note, moyenne, note_sum, note_max;
float note_min = 999;
char eleve_max[99] = "";
char eleve_min[99] = "";

void getMoyenne(){
    note_sum = note_sum + temp_note;
    moyenne = note_sum / compteur;
    printf("Moyenne de la classe :  %f \n", moyenne);
}

void getMax(){
    if(temp_note > note_max){
        note_max = temp_note;
        int i = 0;
        while(i != 98){
            eleve_max[i] = temp_prenom[i];
            i++;
        }
    }
    printf("La meilleure note est de : %f", note_max);
    printf(" et est detenu par : %s \n", eleve_max);
}

void getMin(){
    if(temp_note < note_min){
        note_min = temp_note;
        int a = 0;
        while(a != 98){
            eleve_min[a] = temp_prenom[a];
            a++;
        }
    }
    printf("La pire note est de : %f", note_min);
    printf(" et est detenu par : %s \n", eleve_min);
}

int checkName(){
    if(strcmp(temp_prenom, no_valid_name) == 0){
        printf("Le nom maudit :slight_smile: \n");
        exit(2);
    }else if(strcmp(temp_prenom, exit_code) == 0){
        exit(1);
    }
}


int main(int argc, char** argv) {

    while (true){

        printf("Saisissez le nom de l eleve : ");
        scanf("%s", &temp_prenom);

        checkName();

        printf("Saisissez la note de l eleve : ");
        scanf("%f", &temp_note);

        compteur++;

        getMoyenne();

        getMax();
        getMin();

    }

    return 0;
}
