#include "dl_dxf.h"
#include "filtreDxf.h"

using namespace std;

void search() {
	filtreDxf Filtre;
	DL_Dxf dxf;
	dxf.addText(&Filtre);
	dxf.addLeader(&Filtre);
	dxf.addLine(&Filtre);
	dxf.addBlock(&Filtre);
	dxf.addCircle(&Filtre);
	dxf.addArc(&Filtre);
}
int main() {
	filtreDxf Filtre;
	DL_Dxf dxf;
	int a;
	if (dxf.in(("C:\\Users\\asus\\source\\repos\\Test\\MyGod.dxf"), &Filtre)) {
		search();
		Filtre.afficher();
		cin >> a;
	}
	else {
		
		cout << "Le Fihcier n'existe pas" << endl;
		cin >> a;
	}
	return 0;
}