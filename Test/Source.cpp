#include "dl_dxf.h"
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
	if (dxf.in(("C:\\Users\\asus\\Desktop\\SauvAlexis\\source\\repos\\Test\\ellipse.dxf"), &Filtre)) {
		search();
		vector<float>Coordonnee = Filtre.Coordonnee;
		vector<int>CoordAbs = Filtre.CoordAbs;
		vector<string>Texte = Filtre.Texte;
		for (int i = 0; i < Coordonnee.size(); i++) {
			cout <<Texte[i]<<":" <<Coordonnee[i]<<endl;
		}
		cin >> a;
	}
	else {
		
		cout << "Le Fihcier n'existe pas" << endl;
		cin >> a;
	}
	return 0;
}