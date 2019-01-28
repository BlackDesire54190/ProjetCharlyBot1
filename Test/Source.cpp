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
	

	
	if (dxf.in(("C:\\Users\\CCF\\source\\repos\\BlackDesire54190\\ProjetCharlyBot1\\polyligne.dxf"), &Filtre)) {
		search();
		vector<float>Coordonnee = Filtre.Coordonnee;
		vector<int>CoordAbs = Filtre.CoordAbs;
		vector<string>Texte = Filtre.Texte;


		//for (size_t i = 0; i < Coordonnee.size(); i++) {
		//	cout <<Texte[i]<<":" <<Coordonnee[i]<<endl;
		//}

		cout << endl << endl << endl;

		vector<string>trame;

		int a = 0;
		int b = 0;
		int c = 0;
		int nbsommets = 0;
		int nbpoly = 0;
		for (a; a < Coordonnee.size(); a++) {
			if (Texte[a] == "Nombre de polyligne") {
				nbpoly = Coordonnee[a] + a;
				b = b + a;
				for (b; a < nbpoly; a++) {
					if (Texte[a] == "Sommets") {
						
						nbsommets = Coordonnee[a] + a + 1;
						a = a + 1;
						for (a; a < nbsommets; a++) {
							ostringstream os;
							os << Coordonnee[a];
							trame.push_back(os.str()); // A VERIFIER
						}
					}
				}
			}
		}

		

		int stop;
		cin >> stop;
	}
	else {
		
		cout << "Le Fihcier n'existe pas" << endl;
		int stop;
		cin >> stop;
	}
	return 0;
}