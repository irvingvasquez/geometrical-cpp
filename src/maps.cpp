#include "maps.h"

using namespace gcpp::maps;

MapBase::MapBase()
{

}

PolygonalMap2D::PolygonalMap2D()
{
  area_polygon = new Polygon_2();
}

PolygonalMap2D::~PolygonalMap2D()
{
  delete area_polygon;
}

double PolygonalMap2D::getHeight()
{
  return area_polygon->top_vertex()->y() - area_polygon->bottom_vertex()->y();
}


void PolygonalMap2D::rotateMap(double angle)
{
  //Polygon_2 *poly= Map->area_polygon;
  Polygon_2* new_polygon = new Polygon_2();
  
  Polygon_2::iterator it;
  
  for(it = area_polygon->vertices_begin(); it!=area_polygon->vertices_end(); it++){
    double new_x = cos(angle) * it->x() - sin(angle) * it->y();
    double new_y = sin(angle) * it->x() + cos(angle) * it->y();
    new_polygon->push_back(Point_2(new_x, new_y));
  }
  
  delete area_polygon;
  area_polygon = new_polygon;
}


bool PolygonalMap2D::readFromXYZ(string file)
{
    CGAL::Point_set_3<Kernel::Point_3> point_set;
    CGAL::Point_set_3<Kernel::Point_3>::const_iterator point_set_iterator;

    std::ifstream f (file);

    // Reading input in XYZ format
    if (!f || !CGAL::read_xyz_point_set (f, point_set))
    {
        std::cerr << "Can't read input file " << std::endl;
        return EXIT_FAILURE;
    }

    //std::cout << "Set: \n" << point_set;

    area_polygon->clear();
    for (point_set_iterator = point_set.begin(); point_set_iterator != point_set.end(); ++ point_set_iterator)
    {
        Kernel::Point_3 p3 = point_set.point(*point_set_iterator);
        //std::cout << point_set.point(*point_set_iterator);
        area_polygon->push_back(Point_2( p3.x(), p3.y()));
    }
    
    //std::cout << "Polygon: \n" << *area_polygon << std::endl;

    //point_set.collect_garbage();
    return true;
}


bool PolygonalMap2D::intersectLine(Line_2 line, vector< Point_2 >& points)
{
  /**
  * For each segment of the polygon it adds a vertex if a collision exists
  */
   
  bool intersects = false;
  points.clear();
  
  Polygon_2::iterator start;
  Polygon_2::iterator end;
  
  start = area_polygon->vertices_begin();
  end = start;
  end ++;
  
  while(end != area_polygon->vertices_end()){
	Segment_2 segment(*start, *end);
	
	// without C++11
	CGAL::Object result = CGAL::intersection<Kernel>(segment, line);

	if(const CGAL::Point_2<Kernel> *ipoint = CGAL::object_cast<CGAL::Point_2<Kernel> >(&result) ){
	  // intersection con puntos
	  //cout << "Intersection" << ipoint->x() << " " << ipoint->y() << endl;
	  points.push_back(Point_2(ipoint->x(),ipoint->y()));
	  intersects = true;
	} else
	  if (const CGAL::Segment_2<Kernel> *iseg = CGAL::object_cast<CGAL::Segment_2<Kernel> >(&result) ){
	    // interseccion de un segmento
	      //points.push_back(iseg->source());
	      //points.push_back(iseg->target());
	      intersects = true;
	  } else {
	    // no intersection
	  }
	start++;
	end++;
  }
    
  end= area_polygon->vertices_begin();
  
  Segment_2 segment(*start, *end);
  
  CGAL::Object result = CGAL::intersection<Kernel>(segment, line);

  if(const CGAL::Point_2<Kernel> *ipoint = CGAL::object_cast<CGAL::Point_2<Kernel> >(&result) ){
    // intersection con puntos
    //cout << "Intersection" << ipoint->x() << " " << ipoint->y();
    points.push_back(Point_2(ipoint->x(),ipoint->y()));
    intersects = true;
  } else
    if (const CGAL::Segment_2<Kernel> *iseg = CGAL::object_cast<CGAL::Segment_2<Kernel> >(&result) ){
      // interseccion de un segmento
      //points.push_back(iseg->source());
      //points.push_back(iseg->target());
      intersects = true;
    } else {
      
    }

  return intersects;
}
