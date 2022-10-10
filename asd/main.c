#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void nom (int scores[], char names[][15])
{
    int cpt=0,trouve=0;
    char name[15];
    printf ("entrer votre nom : ");
    scanf(" %s",name);
    system("cls");
    while((cpt<10) && (trouve==0))
    {
        if(strcmp(names[cpt],name)==0)
        {
            for(int i=cpt; i>0; i--)
            {
                strcpy(names[i],names[i-1]);
                scores[i]=scores[i-1];
            }
            trouve++;
        }
        cpt++;
    }
    if(trouve==0)
    {
        for(int i=9; i>0; i--)
        {
            strcpy(names[i],names[i-1]);
            scores[i]=scores[i-1];
        }
    }
    strcpy(names[0],name);
    scores[0]=0;
}


int main()
{
    char m[][15]= {"CHARGE","PROGRAMME","POSITION","ILLUSION","CARTOUCHE","MONITEUR","ARGENT","FLEURS","VISAGE","DESSERT","COLORADO","MACARON","CODAGE","FROMAGE"};
    int choix,reponse;
    char names[10][15],alphabet[26],cache[15],lettre,mot[15];
    int scores[10];
    int coups,indice,correct,help;
    time_t t;
    int time_taken;

    srand(time(NULL));

    do
    {
        printf("*****************BIENVENUE AU JEU*****************\n");
        printf("                   1 - LE PENDU \n                     2 - MOTUS\n\n                     3-QUITTER\n\n                 choisir un jeu : ");
        scanf("%i",&choix);

        while(choix<1 || choix>3)
        {
            printf("-------choix pas disponible ! reesayer :");
            scanf("%i",&choix);
        }

        system("cls");


        for (int i=0; i<10; i++)
        {
            scores[i]=-rand()-1;
            strcpy(names[i]," ");
        }

        do
        {
            time_taken=0;
            correct=0;
            help=1;
            indice=rand()%14;
            for(int i=0; i<strlen(m[indice]); i++)
                cache[i]='_';

            if (choix!=3)
            {
                nom(scores,names);

                if (choix==1)
                {
            coups=strlen(m[indice])-2;

                    for (char i='A'; i<='Z'; i++)
                        alphabet[i]=i;

                    do
                    {
                        int exist=0;
                        printf("il vous reste %i secondes et %i tentatives\n\n",60-time_taken,coups);
                        for (int i=0; i<strlen(m[indice]); i++)
                            printf(" %c",cache[i]);
                        printf("\n\n");
                        for (char i='A'; i<='Z'; i++)
                            printf("%c  ",alphabet[i]);
                        printf("\n\n");

                        if (coups>=6)
                            printf("   _______\n  |       |\n  |\n  |\n  |\n  |\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        else if(coups==5)
                            printf("   _______\n  |       |\n  |       |\n  |\n  |\n  |\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        else if(coups==4)
                            printf("   _______\n  |       |\n  |       |\n  |       O\n  |\n  |\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        else if(coups==3)
                            printf("   _______\n  |       |\n  |       |\n  |       O\n  |       |\n  |\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        else if(coups==2)
                            printf("   _______\n  |       |\n  |       |\n  |       O\n  |      /|\\\n  |\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        else if(coups==1)
                            printf("   _______\n  |       |\n  |       |\n  |       O\n  |      /|\\\n  |      / \\\n  |\n _|_________\n|           |_\n|_____________|\n\n");
                        if(help==1)
                            printf("\ncliquer [?] pour help");

                        t=time(NULL);
                        printf("\nentrer une lettre : ");
                        scanf(" %c",&lettre);
                        system("cls");
                        for (char i='A'; i<='Z'; i++)
                        {
                            if (toupper(lettre)==i)
                                alphabet[i]='_';
                        }

                        char hint;
                        while((help==1) && (lettre=='?'))
                        {
                            hint=rand()%26+65;
                            for (int i=0; i<strlen(m[indice]); i++)
                            {
                                if ((m[indice][i]==hint) && cache[i]=='_')
                                {
                                    cache[i]=hint;
                                    help--;
                                    correct+=1;
                                    scores[0]++;
                                    alphabet[hint]='_';
                                }
                            }
                        }

                        for(int i=0; i<strlen(m[indice]); i++)
                        {
                            if ((toupper(lettre)==m[indice][i])&&(cache[i]=='_'))
                            {
                                cache[i]=toupper(lettre);
                                correct++;
                                scores[0]+=2;
                                exist++;
                            }
                        }
                        if ((exist==0) && (lettre!='?'))
                        {
                            coups--;
                        }

                        t=time(NULL)-t;
                        time_taken+=((int)t);
                    }
                    while((time_taken<60) && (coups>0) && (correct<strlen(m[indice])));
                }
                else if (choix==2)
                {
                    do
                    {
                        int exist=0;  coups=5;
                        printf("il vous reste %i secondes et %i tentatives\n\n",60-time_taken,coups);
                        for (int i=0; i<strlen(m[indice]); i++)
                            printf(" %c",cache[i]);
                        printf("\n\n");

                        if(help==1)
                            printf("\ncliquer [?] pour help");

                        t=time(NULL);
                        printf("\nproposer un mot de %i lettre : ",(int)strlen(m[indice]));
                        scanf(" %s",mot);
                        system("cls");

                        char hint;
                        while((help==1) && (strcmp(mot,"?")==0))
                        {
                            hint=rand()%26+65;
                            for (int i=0; i<strlen(m[indice]); i++)
                            {
                                if ((m[indice][i]==hint) && cache[i]=='_')
                                {
                                    cache[i]=hint;
                                    help--;
                                    scores[0]++;
                                }
                            }
                        }
                        for(int i=0; i<strlen(m[indice]); i++)
                        {
                            if ((toupper(mot[i])==m[indice][i]) && cache[i]=='_')
                            {
                                cache[i]=toupper(mot[i]);
                                scores[0]+=2;
                                exist++;
                            }
                        }
                        if ((exist<strlen(m[indice])) && (strcmp(mot,"?")!=0))
                            coups--;
                        else if (exist==strlen(m[indice]))
                        {
                            scores[0]=2*strlen(m[indice]);
                            correct=1;
                        }
                        t=time(NULL)-t;
                        time_taken+=((int)t);
                    }
                    while((time_taken<60) && (coups>0) && (correct==0));
                }
                int j=0;
                    while((scores[0]>0) && (j<strlen(m[indice]-2-coups)))
                    {
                        scores[0]--;
                        j++;
                    }

                if (coups==0)
                    printf("             FIN DE JEU ! VOUS AVEZ DEPASSER LES TENTATIVES !");
                else if (time_taken>=60)
                    printf("             FIN DE JEU ! TEMPS ECOULEE !");
                else
                    printf("             BRAVO !");
                printf(" le mot cachee est [%s]\n\n",m[indice]);
                do
                {
                    printf("\n   1 - REJOUER\n   2 - VERIFIER SCORE\n   3 - CLASSEMENT\n   4 - RETOURNER AU MENU PRICIPAL\n   5 - QUITTER LE JEU\n\n");
                    printf("QUE VOULER VOUS ? ");
                    scanf ("%i",&reponse);

                    while(reponse>5 || reponse<=0)
                    {
                        printf("-------choix pas disponible ! reessayer : ");
                        scanf("%i",&reponse);
                    }

                    system("cls");
                    if(reponse==2)
                        printf("                le score de [%s] est [%i] \n\n",names[0],scores[0]);
                    else if (reponse==3)
                    {
                        int aux1,tri=0,n=10;
                        char aux2[15];

                        while((n>0) && (tri=1))
                        {
                            for (int i=0; i<n-1; i++)
                            {
                                if (scores[i]<scores[i+1])
                                {
                                    aux1=scores[i];
                                    scores[i]=scores[i+1];
                                    scores[i+1]=aux1;

                                    strcpy(aux2,names[i]);
                                    strcpy(names[i],names[i+1]);
                                    strcpy(names[i+1],aux2);

                                    tri=1;
                                }
                            }
                            n--;
                        }
                        int i=0;
                        while (scores[i]>=0)
                        {
                            printf("\n%15s       %i\n",names[i],scores[i]);
                            i++;
                        }
                    }
                }
                while((reponse!=1) && (reponse!=4) && (reponse!=5));
            }
        }
        while(reponse==1);
    }
    while((reponse==4) && (choix!=3));
    return 0;
}
