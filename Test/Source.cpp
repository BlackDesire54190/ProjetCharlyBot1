#include "dl_dxf.h"
#include "filtreDxf.h"

using namespace std;

void search() {
	filtreDxf Filtre;
	DL_Dxf dxf;

	//� chaque fois que la fonction Text est appel� dans le fichier Dxf
	dxf.addText(&Filtre);
	//� chaque fois que la couche Leader est appel� dans le fichier Dxf
	dxf.addLeader(&Filtre);
	//� chaque fois que la fonction Line est appel� dans le fichier Dxf
	dxf.addLine(&Filtre);
	//� chaque fois que la fonction Circle est appel� dans le fichier Dxf
	dxf.addCircle(&Filtre);
	//� chaque fois que la fonction Arc est appel� dans le fichier Dxf
	dxf.addArc(&Filtre);
	//� chaque fois qu'un Mtext est appel� dans le fichier dxf
	dxf.addMText(&Filtre);
	//� chaque fois qu'une polyligne est vue
	dxf.addPolyline(&Filtre);
	//� chaque Ellipse
	dxf.addEllipse(&Filtre);
	//� chaque sommet 
	dxf.addVertex(&Filtre);
}

int main() {
	filtreDxf Filtre; //Filtre correspond � l'instanciation de la classe filtreDxf
	DL_Dxf dxf; //dxf correspond � l'instanciation de la classe dxf
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
		vector<float>Coordonnee = Filtre.Coordonnee; //copie du vecteur pour l'accessbilit� 
		vector<int>CoordAbs = Filtre.CoordAbs; //copie du vecteur pour l'accessbilit� 
		vector<string>Texte = Filtre.Texte; //copie du vecteur pour l'accessbilit� 
		/*Ci dessous la sortie des donn�es contenue dans les vecteurs */
		for (int i = 0; i < Coordonnee.size(); i++) {
			cout <<Texte[i]<<":" <<Coordonnee[i]<<endl;
		}
		cin >> a;
	}
	else {
		/*Si le fichier n'a pas ete trouv�*/
		cout << "Le Fihcier n'existe pas" << endl;
		cin >> a;
	}
	return 0;
}