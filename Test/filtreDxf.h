#pragma once
#include "dl_global.h"
#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include <vector>

class filtreDxf : public DL_CreationAdapter{
private: 
	std::vector<std::string>Texte;
	std::vector<float>Coordonnee;
	std::vector<int>CoordAbs;
	/*int nbrLigne;
	int nbrCercle;
	int nbrArc;*/

public: filtreDxf();
		virtual void addPoint(const DL_PointData& data);
		virtual void addLine(const DL_LineData& data);
		virtual void addArc(const DL_ArcData& data);
		virtual void addCircle(const DL_CircleData& data);
		virtual void addText(const DL_TextData& data);
		virtual void addBlock(const DL_BlockData& data);
		void afficher();
		

	~filtreDxf();
};


