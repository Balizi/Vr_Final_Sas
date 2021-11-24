#include<stdio.h>
#include<string.h>
struct Clients
{
	char CIN[15];
	char Nom[15];
	char Prenom[15];
	float Montant;
};
struct Clients Clt[100];
struct Clients Cl[100];
int n=0,i,a,j,x;
char ci[16];
void Menu_Principal();
//C'est Une Procédure Qui Permet D_afficher Tous les Compte Bancaire Des Clients
void Afficher()
{
	for(i=0;i<n;i++)
	{
		printf("\n\nVotre Cin : %s ,Votre Nom : %s ,Votre Prenom : %s ,Votre Montant : %.2f \n",Clt[i].CIN,Clt[i].Nom,Clt[i].Prenom,Clt[i].Montant);
	}
}
//C'est Une Procédure Qui Permet De Retire Un Montant Au Client Par Sont Cin
void Retrait()
{
	if(Recherche_Par_CIN()!=-1)
	{
		int mnt;
		printf("Taper le montat que vous Retrait : ");
		scanf("%d",&mnt);
		Clt[a].Montant=Clt[a].Montant-mnt;
		printf("Retrait est faite");
	}
	else
	{
		printf("CIN INCORECTE !!!!");
	}
	Menu_Principal();
}
//C'est Une Procédure Qui Permet De Insérer Au Bien Ajouter Un Montant Au Client Par Sont Cin
void Depot()
{
	if(Recherche_Par_CIN()!=-1)
	{
		int mnt;
		printf("Taper le montat que vous Depot : ");
		scanf("%d",&mnt);
		Clt[a].Montant=Clt[a].Montant+mnt;
		printf("Depot est faite");
	}
	else
	{
		printf("CIN INCORECTE !!!");
	}
	Menu_Principal();
}
//C'est Une Procédure De ,Sous Menu Des Operations Qui Permet De Faire Des Operation Comme Depot Au Retarit Sur Un Compte Bancaire De Client
void Operations()
{
	int choix;
	printf("\n*****************Menu Des Operations*****************\n");
	printf("1)Retrait\n");
	printf("2)Depot\n");
	printf("Taper Votre Choix : ");
	scanf("%d",&choix);
	switch(choix)
	{
		case 1:{
			Retrait();
		};break;
		case 2:{
			Depot();
		};break;
		default:printf("Votre Choix Incorecte");
	}
}
//C'est Une Procédure Qui Permet De Trier Tout les Compte Bancaire De Client Par Ordre Ascendant Au Bien Croissante
void Par_Ordre_Ascendant()
{
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Clt[j].Montant<Clt[i].Montant)
			{
				Cl[i]=Clt[i];
				Clt[i]=Clt[j];
				Clt[j]=Cl[i];
			}
		}
	}
}
//C'est Une Procédure Qui Fait l_appele a la Procédure Qui Fait le Trier Par Ordre Ascendant Après Afficher les Client Dont Montant Supérieure a Un Montant Donné Par Order Ascendant
void Par_Ordre_AscendantX()
{
	int y;
	printf("Taper un Montant : ");
	scanf("%d",&y);
	Par_Ordre_Ascendant();
	printf("les comptes bancaires ayant un montant superieur a %d Ascendant\n",y);
	for(i=0;i<n;i++)
	{
		if(Clt[i].Montant>y)
		{
			printf("Votre Cin : %s ,Votre Nom : %s ,Votre Prenom : %s ,Votre Montant : %.2f \n",Clt[i].CIN,Clt[i].Nom,Clt[i].Prenom,Clt[i].Montant);
		}
	}
}
//C'est Une Procédure Qui Permet De Trier Tout les Compte  De Client Par Ordre Descendant Au Bien Decroissante
void Par_Ordre_Descendant()
{
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Clt[j].Montant>Clt[i].Montant)
			{
				Cl[i]=Clt[i];
				Clt[i]=Clt[j];
				Clt[j]=Cl[i];
			}
		}
	}
}
//C'est Une Procédure Qui Fait l_appele a la Procédure Qui Fait le Trier Par Ordre Descendant Après prend les 3 Premiers montants est Ajouter 1.3%
void Fidelisation()
{
	Par_Ordre_Descendant();
	for(i=0;i<3;i++)
	{
		Clt[i].Montant=Clt[i].Montant+(Clt[i].Montant*0.013);
	}
	printf("Fidelisation success\n");
	Menu_Principal();
}
//C'est Une Procédure Qui fait l_appele a la Procédure Qui fait le Trier Par Ordre Descendant Après Afficher les Client Dont Montant Supérieure a Un Montant Donné Par Order Descendant
void Par_Ordre_DescendantX()
{
	int mn;
	printf("Taper un montant : ");
	scanf("%d",&mn);
	Par_Ordre_Descendant();
	printf("Les Comptes Bancaires Ayant Un montant Superieur a %d Descendant\n",mn);
	for(i=0;i<n;i++)
	{
		if(Clt[i].Montant>mn)
		{
			printf("Votre CIN : %s ,Votre Nom : %s ,Votre Prenom : %s ,Votre Montant : %.2f \n",Clt[i].CIN,Clt[i].Nom,Clt[i].Prenom,Clt[i].Montant);
		}
	}
}
//C'est Une Procédure Qui Permet De Criee Un Compte Pour Un Client
void Introduire_un_compte_bancaire()
{
	printf("Taper les info de Client Num : %d\n",n+1);
	printf("Taper Votre CIN : ");
	scanf("%s",Clt[n].CIN);
	printf("Taper Votre Nom : ");
	scanf("%s",Clt[n].Nom);
	printf("Taper Votre Prenom : ");
	scanf("%s",Clt[n].Prenom);
	printf("Taper Votre Montant : ");
	scanf("%f",&Clt[n].Montant);
	n++;
	Menu_Principal();
}
//C'est Une Procédure Qui Permet De Criee Plusieurs Compte Bancaires
void Introduire_Plusieurs_Comptes_Bancaires()
{
	printf("Taper le nomber de compte que vous vollez Introduire : ");
	scanf("%d",&x);
	for(i=n;i<n+x;i++)
	{
		printf("Taper les info de Client Num : %d\n",i+1);
		printf("Taper Votre CIN : ");
		scanf("%s",Clt[i].CIN);
		printf("Taper Votre Nom : ");
		scanf("%s",Clt[i].Nom);
		printf("Taper Votre Prenom : ");
		scanf("%s",Clt[i].Prenom);
		printf("Taper Votre Montant : ");
		scanf("%f",&Clt[i].Montant);
		//n++;
	}
	n += x;
	Menu_Principal();
}
//C'est Une Fonction Qui Fait la Recherche Par CIN 
int Recherche_Par_CIN()
{
	a=-1;
	printf("Taper Votre CIN que vous chercher : ");
	scanf("%s",ci);
	for(i=0;i<n;i++)
	{
		if(strcmp(Clt[i].CIN,ci)==0)
		{
			a=i;
			break;
		}
	}
	return a;
}
//C'est Une Procédure ,Sous Menu qui donne les choix de L_Affichage  
void Affichage()
{
	int choix;
	printf("\n*****************Menu D_affichage*****************\n");
	printf("1)Par Ordre Ascendant\n");
	printf("2)Par Ordre Descendant\n");
	printf("3)Par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit) :\n");
	printf("4)Par Ordre Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit) :\n");
	printf("5)Recherche par CIN\n");
	printf("Taper Votre Choix : ");
	scanf("%d",&choix);
	switch(choix)
	{
		case 1:{
			Par_Ordre_Ascendant();
			Afficher();
			Menu_Principal();
		};break;
		case 2:{
			Par_Ordre_Descendant();
			Afficher();
			Menu_Principal();
		};break;
		case 3:{
			Par_Ordre_AscendantX();
			Menu_Principal();
		};break;
		case 4:{
			Par_Ordre_DescendantX();
			Menu_Principal();
		};break;
		case 5:{
			if(Recherche_Par_CIN()!=-1)
			{
				printf("le client dont CIN %s exsite\n",ci);
				printf("CIN : %s ,Nom : %s ,Prenom : %s ,Montant : %.2f\n",Clt[a].CIN,Clt[a].Nom,Clt[a].Prenom,Clt[a].Montant);
			}
			else
			{
				printf("le client dont CIN %s n'existe pas\n",ci);
			}
			Menu_Principal();
		};break;
		default : printf("Votre Choix incorecte !!!!!!");
	}
}
//C'est Un Menu Principal Qui Fait La Gestion Des Compte Bancaire
void Menu_Principal()
{
	int choix;
	printf("*****************Menu Principal*****************\n\n");
	printf("1)Introduire un compte bancaire\n");
	printf("2)Introduire plusieurs comptes bancaires\n");
	printf("3)Operations :\n");
	printf("4)Affichage :\n");
	printf("5)Fidelisation\n");
	printf("6)Quitter l_application\n");
	printf("Taper Votre Choix : ");
	scanf("%d",&choix);
	switch(choix)
	{
		case 1:{
			Introduire_un_compte_bancaire();
		};break;
		case 2:{
			Introduire_Plusieurs_Comptes_Bancaires();
		};break;
		case 3:{
			Operations();
		};break;
		case 4:{
			Affichage();
		};break;
		case 5:{
			Fidelisation();
		};break;
		case 6:{
			printf("Clicker sur une touche");
		};break;
		default :printf("Votre Choix incorecte !!!!!!");
	}
}
main()
{
	Menu_Principal();
}
