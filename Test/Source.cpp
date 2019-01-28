#include "dl_dxf.h"
#include "filtreDxf.h"

using namespace std;

void search() {
	filtreDxf Filtre;
	DL_Dxf dxf;

	//à chaque fois que la fonction Text est appelé dans le fichier Dxf
	dxf.addText(&Filtre);
	//à chaque fois que la couche Leader est appelé dans le fichier Dxf
	dxf.addLeader(&Filtre);
	//à chaque fois que la fonction Line est appelé dans le fichier Dxf
	dxf.addLine(&Filtre);
	//à chaque fois que la fonction Circle est appelé dans le fichier Dxf
	dxf.addCircle(&Filtre);
	//à chaque fois que la fonction Arc est appelé dans le fichier Dxf
	dxf.addArc(&Filtre);
	//à chaque fois qu'un Mtext est appelé dans le fichier dxf
	dxf.addMText(&Filtre);
	//à chaque fois qu'une polyligne est vue
	dxf.addPolyline(&Filtre);
	//à chaque Ellipse
	dxf.addEllipse(&Filtre);
	//à chaque sommet 
	dxf.addVertex(&Filtre);
}

int main() {
	filtreDxf Filtre; //Filtre correspond à l'instanciation de la classe filtreDxf
	DL_Dxf dxf; //dxf correspond à l'instanciation de la classe dxf
/*---------------------------------------------------------------------------------*/
/*ici la fonction dxf in correspond a une focntion d'ouverture de fichier dans la  */
/*Classe filtreDxf                                                                 */
/*La fonction search appelle toutes les fonctions utiles pour le fraisage          */
/*Alexis De Brito, Romain Thiel, Julien Loesel                                     */
/*---------------------------------------------------------------------------------*/

	int a;
	//Ouverture du fichier DXF 
	if (dxf.in(("C:\\Users\\asus\\Desktop\\SauvAlexis\\source\\repos\\Test\\ellipse.dxf"), &Filtre)) {
		search();
		vector<float>Coordonnee = Filtre.Coordonnee; //copie du vecteur pour l'accessbilité 
		vector<int>CoordAbs = Filtre.CoordAbs; //copie du vecteur pour l'accessbilité 
		vector<string>Texte = Filtre.Texte; //copie du vecteur pour l'accessbilité 
		/*Ci dessous la sortie des données contenue dans les vecteurs */
		for (int i = 0; i < Coordonnee.size(); i++) {
			cout <<Texte[i]<<":" <<Coordonnee[i]<<endl;
		}
		cin >> a;
	}
	else {
		/*Si le fichier n'a pas ete trouvé*/
		cout << "Le Fihcier n'existe pas" << endl;
		cin >> a;
	}
	return 0;
}