#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int main(){
	
		int nombre_president,k=0,i=0;
		int nombre_electeur,j=0,f=0;
		
	// ------------- demander a l'ultilisateur d'entrer le nombre de presidents ------------------
		printf("entrez le nombre de presidents : ");
		scanf("%d", &nombre_president);
	
	// ------------- forcer l'ultilisateur a entrer un nombre de presidents >= 5 ------------------
			while(nombre_president<5)
			{
			printf ("entrez un nombre de president superieur ou egal 5 : ");
			scanf("%d", &nombre_president);
			}
			
			// creation liste des presidents
			char nom_president[nombre_president][50]; 
			
			do  {
				printf("entrez le nom de president %d :\t",i+1);
				scanf("%s",&nom_president[i]);
				i++;
				}while(i<nombre_president);
				
	// ------------- affichage la liste des presidents ---------------------------	
		
			for (k=0;k<nombre_president;k++)
			{
				printf("le nom de %d president : %s\n", k+1, nom_president[k]);
			}

	// ------------- demander a l'ultilisateur d'entrer le nombre d'electeurs ------------------

			printf("entrez le nombre des electeurs : ");
			scanf("%d", &nombre_electeur);
	// ------------- forcer l'ultilisateur d'entrer un nombre d'electeurs >= 10 ------------------		
			while(nombre_electeur<10){
				printf("entrez le nombre des electeurs superieur ou egal 10 : ");
				scanf("%d", &nombre_electeur);
			}
			
			//creation liste des electeurs
			char nom_electeur[nombre_electeur][20]; 
			
			do {
				printf("entrez CIN de %d electeur : ",j+1);
				scanf("%s", &nom_electeur[j]);
				j++;
			}while(j<nombre_electeur);
			
	// ------------- affichage la liste des electeurs ---------------------------	

			for (f=0;f<nombre_electeur;f++)
			{
				printf ("CIN %d electeur : %s\n",f+1 ,nom_electeur[f]);
			}
			
	// ---------------------------------------------------------------------------------------------	
	// --------------------------------- PREMIER TOUR ----------------------------------------------
	// ---------------------------------------------------------------------------------------------
	
	int choix;
	float vote[nombre_president]={0};

	// -------------- calculer vote et pourcentage et test d'egalite ---------------------------	
	
	int counteur;
	
		do{
				// boucle pour vider la table de vote
				for(int k=0;k<nombre_president;k++) 
				{
					vote[k]=0;
				}
				
				counteur =1;
				
				for ( i=0; i<nombre_electeur ; i++)
				{
					for ( j=0 ; j<nombre_president ; j++)
					{
					printf("pour voter le president %s tapez %d\n",nom_president[j], j+1);
					}
				printf("CIN %s votre choix ?\n", nom_electeur[i]);
				scanf("%d", &choix);
				vote[choix-1]++;
				}
	
	// ------------- calculer et afficher directement pourcentage ------------------------	
				for ( i=0; i<nombre_president; i++)
				{
					vote[i] = (vote[i]/nombre_electeur)*100; // formule pour calculer le pourcentage
					printf("president %s a %g\n",nom_president[i],vote[i]);
				}
		
	// ---------------------- test egalite ---------------------------

	for ( i=0 ; i<nombre_president-1 ; i++)
		{
			if (vote[i] == vote[i+1])
			{
				counteur++;
			}
		}
		
		}while (counteur == nombre_president);
		
	// ------------------- filtration ------------------------
	float vote2[nombre_president];
	char nom_president2[nombre_president][50];
	int c=0;// la nouvelle taille de nouveau table 
	for  (i=0;i<nombre_president;i++)
	{
			if ( vote[i]>= 15)
			{	
				// copier les votes de présidents qui dépassent 15% dans un nouveau tableau
				vote2[c] = vote[i];	
				// copier les noms de présidents qui dépassent 15% dans un nouveau tableau
				strcpy(nom_president2[c], nom_president[i]); 
				c++;
			}
	}
	
	int nombre_president2 = c; 
		
	// -------------- presidents qui ont reussi la premiere tour --------------------------

	printf("\nles presidents qui ont reussi la premiere tour sont\n");

		for ( i=0 ; i<nombre_president2 ; i++)
		{
			printf("\npresident %s\n", nom_president2[i]);
		} 
		
	// ------------------------------------------------------------------------------------------------------------------	
	// ------------------------------------------ DEUXIEME TOUR ---------------------------------------------------------
	// ------------------------------------------------------------------------------------------------------------------
	
	printf ("\n\n \t deuxieme tour \t\n");
	
	// ---------------------- debut d'election TOUR 2 -------------------------------------------

		do{
				for(k=0;k<nombre_president2;k++)
				{
					vote2[k]=0;
				}
				counteur=1;	// bash ndir comparaison mabin l3adad presidents m3a counteur 3la wed egalité 			
				for ( i=0; i<nombre_electeur ; i++)
				{
					
					for ( j=0 ; j<nombre_president2 ; j++) 
					{
						printf("pour voter le president %s tapez %d\n",nom_president2[j], j+1);
					}
					
				printf("CIN %s votre choix ?\n", nom_electeur[i]);
				scanf("%d", &choix);
				vote2[choix-1]++;
				
				}
				
	// ------------- calculer et afficher directement pourcentage ------------------------	
		
		for ( i=0; i<nombre_president2; i++)
		{
			vote2[i] = (vote2[i]/nombre_electeur)*100; // formule pour calculer le pourcentage
			printf("president %s a %g\n",nom_president2[i],vote2[i]);
		}
		
	// -------------------------- test egalite -----------------------------------------

			for ( i=0 ; i<nombre_president2-1 ; i++)
			{
				if (vote2[i] == vote2[i+1])
				{
					counteur++;
				}
			}
		
		}while (counteur == nombre_president2);
	// ------------- trouver le president qui a le plus petit nombre de vote ----------------------
	
		int min=0;		
		for ( i=0 ; i<nombre_president2-1 ; i++)
		{
			if( vote2[min]>vote2[i+1])
			{
				min = i+1;
				//printf("\nmin db hya%d",min);
			}
		}
		printf("Pourcentage de vote le plus bas : %g\n",vote2[min]);

	// ------------- filtration deuxieme tour ----------------------
	
	float vote3[nombre_president2];
	char nom_president3[nombre_president2][50];
	int p=0;
	
		for ( i=0 ; i<nombre_president2;i++)
		{
			if (vote2[i]>vote2[min])
			{
				vote3[i]=vote2[i];
				strcpy(nom_president3[p], nom_president2[i]);
				p++;
			}
		}
		// printf("counteur p : %d",p);
	if (p==1)
	{
		printf("\nfelicitations .. le president gagnant est %s", nom_president3[0]);
		return 0;
	}
	
	int nombre_president3 = p; 
	
	// ------------------------------------------------------------------------------------------------------------------	
	// ------------------------------------------ TROISIEME TOUR --------------------------------------------------------
	// ------------------------------------------------------------------------------------------------------------------
	
		printf ("\n\n\t deuxieme tour \t\n");
	
	// ---------------------- debut d'election TOUR 3 -------------------------------------------
	int max;	
	do{

				for(k=0;k<nombre_president3;k++)
				{
					vote3[k]=0;
				}
	
			for ( i=0; i<nombre_electeur ; i++)
			{
				for ( j=0 ; j<nombre_president3 ; j++) 
				{
					printf("pour voter le president %s tapez %d\n",nom_president3[j], j+1);
			}
			printf("CIN %s votre choix ?\n", nom_electeur[i]);
			scanf("%d", &choix);
			vote3[choix-1]++;
			}
			
	// --------------- calculer et afficher direcetement pourcentage ----------------------------
			
			for ( i=0; i<nombre_president3; i++)
		{
			vote3[i] = (vote3[i]/nombre_electeur)*100; // formule pour calculer le pourcentage
			printf("president %s a %g\n",nom_president3[i],vote3[i]);
		}
			
	// ------------- trouver le president qui a le plus grand nombre de vote ----------------------
	max=0;	
		
		for ( i=0 ; i<nombre_president3-1 ; i++)
		{
			if( vote3[max]<vote3[i+1])
			{
				max = i+1;
			}
		}
		printf("Pourcentage de vote le plus grand : %g\n",vote3[max]);

	// ----------- trouver s'il y a une similarité dans les votes ------------------------------
	counteur=0;
		for ( i=0 ; i<nombre_president3 ; i++)
		{
			if(vote3[max] == vote3[i]){
			counteur++;
			}
			
		}
	
	}while(counteur != 1);
		
	printf("\nle president gagnant : %s\n",nom_president[max]);
		
	return 0;
	}

