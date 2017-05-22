#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED



// definition des pins de la Mega


#define MoteurDroit 2
#define MoteurGauche 3
#define In1MoteurDroit 28
#define In2MoteurDroit 30
#define In3MoteurGauche 32
#define In4MoteurGauche 34
#define LassoPin 42
#define FunnyActionPin 40
#define GpioTirette 22
#define GpioJaune 24
#define GpioBleu 26
#define DetectAvant A8
#define DetectArriere A9

//definition des constantes

#define PWMMax 200
#define FrequenceEchantillonnage 50
#define NbTickPeriodique 100



//definition des variables globales
//Pour l'assert
#define P 10
#define I 0.001
#define D 0.01

#define Separateur ';'



int TimerId;
int CodeuseDroit;
int CodeuseGauche;
unsigned long Temps;
unsigned long DateAssert;
int ErreurDroit;
int SommeErreurDroit;
int DeltaErreurDroit;
int ErreurGauche;
int SommeErreurGauche;
int DeltaErreurGauche;
int AncienneErreur;
int Consigne;
int AncienneErreurDroit;
int AncienneErreurGauche;
int PWMDroit;
int PWMGauche;
int PrecisionDroit;
int Parcouru;
int PrecisionAssert;
bool FinDroit;
bool FinGauche;

//Pour verifier Frequence assert
//unsigned long DateDernierPassage;

//Pour la machine d'état
int EtatCourant;
char Actions[100];
//A => Avancer; R=> reculer; W => wait; F => funny action; L=> Leve pince : B => baisse pince ; T => tourne
int Param[100];
int Vitesse[100];
bool EtatComplete;


// Pour l'init et la Tirette
 bool Bleu;
 bool Tirette;
 unsigned long TempsDebut;




#endif // DEFINE_H_INCLUDED
