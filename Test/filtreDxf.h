#pragma once
#include "dl_global.h"
#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include <vector>

class filtreDxf : public DL_CreationAdapter{
private: 

	/*int nbrLigne;
	int nbrCercle;
	int nbrArc;*/

public: filtreDxf();
		std::vector<std::string>Texte;
		std::vector<float>Coordonnee;
		std::vector<int>CoordAbs;
		virtual void addPoint(const DL_PointData& data);
		virtual void addLine(const DL_LineData& data);
		virtual void addArc(const DL_ArcData& data);
		virtual void addCircle(const DL_CircleData& data);
		virtual void addText(const DL_TextData& data);
		virtual void addMText(const DL_MTextData& data);
		virtual void addEllipse(const DL_EllipseData& data);
		virtual void addVertex(const DL_VertexData& data);
		virtual void addLayer(const DL_LayerData& data);
		virtual void addPolyline(const DL_PolylineData& data);


		

	~filtreDxf();
};


