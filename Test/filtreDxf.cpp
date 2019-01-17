#include "filtreDxf.h"
using namespace std;


filtreDxf::filtreDxf()
{
}

void filtreDxf::addPoint(const DL_PointData & data)
{
	Texte.push_back("Points, Donnee =");
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(3);
	Texte.push_back("Coordonnee du point en X");
	Coordonnee.push_back(data.x);
	Texte.push_back("Coordonnee du point en Y");
	Coordonnee.push_back(data.y);
	Texte.push_back("Coordonnee du point en Z");
	Coordonnee.push_back(data.z);
}


void filtreDxf::addText(const DL_TextData & data)
{
	string nom;
	Texte.push_back("Texte, donnee =");
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(8);
	nom = data.text;
	Texte.push_back("|"+nom+"|");
	Coordonnee.push_back(0);
	Texte.push_back("Rotation de l'angle par rapport a sa valeur par defaut");
	Coordonnee.push_back(data.angle);
	Texte.push_back("Coordonnee du point d'alignement en X");
	Coordonnee.push_back(data.apx);
	Texte.push_back("Coordonnee du point d'alignement en Y");
	Coordonnee.push_back(data.apy);
	Texte.push_back("Coordonnee du point d'alignement en Z");
	Coordonnee.push_back(data.apz);
	Texte.push_back("Coordonnee du point d'insertion en X");
	Coordonnee.push_back(data.ipx);
	Texte.push_back("Coordonnee du point d'insertion en Y");
	Coordonnee.push_back(data.ipy);
	Texte.push_back("Coordonnee du point d'insertion en Z");
	Coordonnee.push_back(data.ipz);
}

void filtreDxf::addLine(const DL_LineData & data)
{
	Texte.push_back("Ligne Donnee");
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(6);
	Texte.push_back("debut des coordonnees en X");
	Coordonnee.push_back(data.x1);
	Texte.push_back("Fin des coordonnees en X");
	Coordonnee.push_back(data.x2);
	Texte.push_back("Debut des Coordonnes en Y");
	Coordonnee.push_back(data.y1);
	Texte.push_back("Fin des coordonnees en Y");
	Coordonnee.push_back(data.y2);
	Texte.push_back("Debut des Coordonnes en Z");
	Coordonnee.push_back(data.z1);
	Texte.push_back("Fin des coordonnees en Z");
	Coordonnee.push_back(data.z2);

}

void filtreDxf::addArc(const DL_ArcData & data)
{
	Texte.push_back("Arc Donnee");
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(6);
	Texte.push_back("Coordonnee en X du point central");
	Coordonnee.push_back(data.cx);
	Texte.push_back("Coordonnee en y du point central");
	Coordonnee.push_back(data.cy);
	Texte.push_back("Coordonnee en z du point central");
	Coordonnee.push_back(data.cz);
	Texte.push_back("Rayon de l'arc");
	Coordonnee.push_back(data.radius);
	Texte.push_back("Angle de Depart");
	Coordonnee.push_back(data.angle1);
	Texte.push_back("Angle de fin");
	Coordonnee.push_back(data.angle2);
}

void filtreDxf::addCircle(const DL_CircleData & data)
{
	string nom = "cerlce donné";
	Texte.push_back(nom);
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(4);
	Texte.push_back("Coordonnee du point central en X");
	Coordonnee.push_back(data.cx);
	Texte.push_back("Coordonnee du point central en Y");
	Coordonnee.push_back(data.cy);
	Texte.push_back("Coordonnee du point central en Z");
	Coordonnee.push_back(data.cz);
	Texte.push_back("Rayon du cercle");
	Coordonnee.push_back(data.radius);
}


void filtreDxf::afficher()
{
	cout << Texte.size() << " elements Tableau 1" << endl << Coordonnee.size() << " elements Tableau 2" << endl;
	for (int i = 0; i < Texte.size(); i++) {
		cout << Texte[i] << "=" << Coordonnee[i] << endl;
	}
	cout << "Les donnees dans les coordonnees se trouvent a la position:";
	for (int i = 0; i < CoordAbs.size(); i++) {
		cout  <<CoordAbs[i]<<",";
	}
}

void filtreDxf::addBlock(const DL_BlockData& data) {
	Texte.push_back("BlockData, Donnees");
	int s = Texte.size();
	CoordAbs.push_back(s - 1);
	Coordonnee.push_back(3);
	Texte.push_back("Base Point x");
	Coordonnee.push_back(data.bpx);
	Texte.push_back("Base Point y");
	Coordonnee.push_back(data.bpy);
	Texte.push_back("Base Point z");
	Coordonnee.push_back(data.bpz);
}
filtreDxf::~filtreDxf()
{

}
