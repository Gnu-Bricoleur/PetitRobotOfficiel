#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

// definition des pins de la Mega

#define MoteurDroit 2
#define MoteurGauche 3
#define In1MoteurDroit 28
#define In2MoteurDroit 30
#define In3MoteurGauche 32
#define In4MoteurGauche 34
#define LassoPin 29
#define FunnyActionPin 31


//definition des constantes

#define PWMMax 100



//definition des variables globales
//Pour l'assert
#define P 10
#define I 0.001
#define D 0.01
int CodeuseDroit;
int CodeuseGauche;
unsigned long Temps;
unsigned long DateAssert;
int ErreurDroit;
int SommeErreurDroit;
int DeltaErreurDroit;
int AncienneErreur;
int Consigne;
int ParcouruDroit;

//Pour la machine d'état
int EtatCourant;
char Actions[100];
//A => Avancer; R=> reculer; W => wait; F => funny action; L=> Leve pince : B => baisse pince ; T => tourne
int Param[100];
bool EtatComplete;


#endif // DEFINE_H_INCLUDED
