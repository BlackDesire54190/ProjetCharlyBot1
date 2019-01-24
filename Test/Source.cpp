#include "dl_dxf.h"
#include "filtreDxf.h"
#include "LSerie.h"
#include <vector>
#include "filtreDxf.h"

using namespace std;

void search() {
	filtreDxf Filtre;
	DL_Dxf dxf;

	dxf.addText(&Filtre);
	dxf.addLeader(&Filtre);
	dxf.addLine(&Filtre);
	dxf.addCircle(&Filtre);
	dxf.addArc(&Filtre);
	dxf.addMText(&Filtre);
	dxf.addPolyline(&Filtre);
	dxf.addEllipse(&Filtre);
	dxf.addVertex(&Filtre);
}



int main() {
	filtreDxf Filtre;
	DL_Dxf dxf;
	

	int a;
	if (dxf.in(("C:\\Users\\CCF\\source\\repos\\BlackDesire54190\\ProjetCharlyBot1\\polyligne.dxf"), &Filtre)) {
		search();
		vector<float>Coordonnee = Filtre.Coordonnee;
		vector<int>CoordAbs = Filtre.CoordAbs;
		vector<string>Texte = Filtre.Texte;


		for (size_t i = 0; i < Coordonnee.size(); i++) {
			cout <<Texte[i]<<":" <<Coordonnee[i]<<endl;
		}


		vector<string>trame;

		for (size_t a = 0; a < Coordonnee.size(); a++) {
			if (Texte[a] == "Nombre de polyligne") {
				int nbpoly = Coordonnee[a];
				for (int b = 0; b < nbpoly; b++) {
					if (Texte[b] == "Sommets") {
						int nbsommets = Coordonnee[b];
						for (int c = 0; c < nbsommets; c++) {
							trame.push_back(Coordonnee[c]); // A VERIFIER
						}
					}
				}
			}
		}
		


		cin >> a;
	}
	else {
		
		cout << "Le Fihcier n'existe pas" << endl;
		
		cin >> a;
	}
	return 0;
}