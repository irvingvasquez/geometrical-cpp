#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <CGAL/polygon_function_objects.h>
#include <CGAL/Polygon_set_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Partition_traits_2.h>
#include <CGAL/Partition_is_valid_traits_2.h>
#include <CGAL/polygon_function_objects.h>
#include <CGAL/Polygon_set_2.h>


namespace gcpp
{

namespace definitions
{

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef CGAL::Partition_traits_2<Kernel>                    Traits;
typedef CGAL::Is_convex_2<Traits>                           Is_convex_2;
typedef Traits::Polygon_2                                   Polygon_2;
typedef Traits::Point_2                                     Point_2;
typedef Polygon_2::Vertex_const_iterator                    Vertex_iterator;
typedef CGAL::Polygon_set_2<Kernel, Point_2> 	Polygon_set;
typedef Kernel::Line_2 Line_2;
typedef Kernel::Segment_2 Segment_2;
typedef Kernel::Vector_2 Vector_2;
}

}


#endif