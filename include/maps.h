/*
Copyright (C) <2022>  Juan Irving Vásquez-Gómez
jivg.org, Instituto Politécnico Nacional

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/


#ifndef MAPS_H
#define MAPS_H

#include "definitions.h"
#include <vector>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_2.h>
#include <CGAL/Point_set_3/IO.h>
#include <fstream>

namespace gcpp{

namespace maps{

using namespace gcpp::definitions;
using namespace std;

/*-------------------------------------------------------------------------*/
/**
  @brief    Map of the region of interest

  Map of the region of interest
  Mapa del terreno
 */
/*-------------------------------------------------------------------------*/
class MapBase
{
public:
  MapBase();

};



/*-------------------------------------------------------------------------*/
/**
  @brief  Bidimensional map

  Mapa bidimensional del terreno
 */
/*-------------------------------------------------------------------------*/
class PolygonalMap2D : public MapBase{
  
public:
//PolygonalMap2D(Polygon_2 *polygon);
PolygonalMap2D();
~PolygonalMap2D();

  Polygon_2 *area_polygon;
  
  Point_2 cartesian_home_location;
  
  //Point_2 takeOffLocation;
  
  /** Returns the height of the polygon
   * The higher point less the lower point
   */
  double getHeight();
  
  bool readFromXYZ(string file);

  //bool readMapFromKML(string file);
  
  //bool readFromMissionPlannerPoly(string file);
  
  // TODO: convert to protected members
  //geodeticCoordinate geoReferencePoint;
  
  //Point_2 cartesianReferencePoint;
  
  /*
  * 
  * 
  * 
  */
  bool intersectLine(Line_2 line, vector< Point_2 >& points);
  
  void rotateMap(double angle);
  
protected:

};

}

}


#endif