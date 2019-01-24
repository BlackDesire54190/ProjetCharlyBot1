#include "filtreDxf.h"
#include <cmath>
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
	Texte.push_back("Coordonnee du point d'insertion en X");
	Coordonnee.push_back(data.ipx);
	Texte.push_back("Coordonnee du point d'insertion en Y");
	Coordonnee.push_back(data.ipy);

	
}

void filtreDxf::addMText(const DL_MTextData & data)
{
	string texte;
	texte = data.text;
	Texte.push_back("MText");
	CoordAbs.push_back(Texte.size() - 1);
	Coordonnee.push_back(0);
	Texte.push_back("Texte");
	CoordAbs.push_back(Texte.size() - 1);
	Coordonnee.push_back(0);
	Texte.push_back(texte);
	Coordonnee.push_back(0);
	Texte.push_back("Mtext Hauteur");
	Coordonnee.push_back(data.height);
	Texte.push_back("MText Largeur");
	Coordonnee.push_back(data.width);

}

void filtreDxf::addEllipse(const DL_EllipseData& data) {
	float deg1, deg2;
	deg1 = data.angle1;
	deg2 = data.angle2;
	deg1 = (180 * deg1) / M_PI;
	deg2 = (180 * deg2) / M_PI;
	Texte.push_back("Debut de l'angle en deg");
	Coordonnee.push_back(deg1);
	Texte.push_back("Fin de l'angle en deg");
	Coordonnee.push_back(deg2);
	Texte.push_back("Centre de l'ellipse en X");
	Coordonnee.push_back(data.cx);
	Texte.push_back("Centre de l'ellipse en Y");
	Coordonnee.push_back(data.cy);
	Texte.push_back("Coordonee en X du point final de l'axe principal");
	Coordonnee.push_back(data.mx);
	Texte.push_back("Coordonee en Y du point final de l'axe principal");
	Coordonnee.push_back(data.my);
	Texte.push_back("Ratio mineur/majeur");
	Coordonnee.push_back(data.ratio);
}

void filtreDxf::addVertex(const DL_VertexData & data)
{
	filtreDxf Filtre;
	DL_Dxf dxf;
	Texte.push_back("Sommets");
	Coordonnee.push_back(2);
	Texte.push_back("Point X");
	Coordonnee.push_back(data.x);
	Texte.push_back("Points Y");
	Coordonnee.push_back(data.y);
	dxf.endEntity(&Filtre);
}

void filtreDxf::addLayer(const DL_LayerData & data)
{
	Texte.push_back("Flag");
	Coordonnee.push_back(data.flags);
}

void filtreDxf::addPolyline(const DL_PolylineData & data)
{
	Texte.push_back("Nombre de polyligne suivante");
	Coordonnee.push_back(data.number);
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
	Texte.push_back("Rayon du cercle");
	Coordonnee.push_back(data.radius);
}



//void filtreDxf::addBlock(const DL_BlockData& data) {
//	Texte.push_back("BlockData, Donnees");
//	int s = Texte.size();
//	CoordAbs.push_back(s - 1);
//	Coordonnee.push_back(3);
//	Texte.push_back("Base Point x");
//	Coordonnee.push_back(data.bpx);
//	Texte.push_back("Base Point y");
//	Coordonnee.push_back(data.bpy);
//	Texte.push_back("Base Point z");
//	Coordonnee.push_back(data.bpz);
//}
filtreDxf::~filtreDxf()
{

}
