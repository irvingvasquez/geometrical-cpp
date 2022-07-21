/*
Perpendicular to the largest edge path
*/

#include "definitions.h"
#include "maps.h"

using namespace gcpp;

int main(int argc, char** argv){
    std::string file (argc > 1 ? argv[1] : "../data/polygon_points.xyz");

    maps::PolygonalMap2D roi;

    roi.readFromXYZ(file);

    return 0;
}