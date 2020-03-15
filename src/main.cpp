#include <c3ga/Mvec.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <utility>

#include "Geogebra_c3ga.hpp"
#include "c3gaTools.hpp"

#include "Entry.hpp"

const double epsilon = 1e-6;

///////////////////////////////////////////////////////////
void sample1() {
  Viewer_c3ga viewer;

  // 4  points
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(3, 2, 0.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 3, 0.5);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(2, 2, 2.0);
  viewer.push(pt1, "pt1", 200, 0, 0);
  viewer.push(pt2, "pt2", 200, 0, 0);
  viewer.push(pt3, "pt3", 200, 0, 0);
  viewer.push(pt4, "pt4", 200, 0, 0);

  // a line
  c3ga::Mvec<double> line = pt3 ^ pt2 ^ c3ga::ei<double>();
  viewer.push(line, "line", 0, 200, 0);

  // a plane
  c3ga::Mvec<double> plane = pt1 ^ pt2 ^ pt3 ^ c3ga::ei<double>();
  viewer.push(plane, "plane", 150, 200, 0);

  // a sphere
  c3ga::Mvec<double> sphere = pt1 ^ pt2 ^ pt3 ^ pt4;
  viewer.push(sphere, "sphere", 0, 0, 200);
  std::cout << "sphere " << sphere << std::endl;

  // a circle (sphere-plane intersection)
  c3ga::Mvec<double> circle = !(!plane ^ !sphere);
  // c3ga::Mvec<double> circle = pt1 ^ pt2 ^ pt3;
  viewer.push(circle, "circle", 0, 200, 0);

  viewer.display();
  viewer.render("output.html");
}

///////////////////////////////////////////////////////////
void sample2() {

  Viewer_c3ga viewer;

  // plane from 3  points (plane z=0)
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(3, 2, 0.0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 3, 0.0);
  c3ga::Mvec<double> plane = pt1 ^ pt2 ^ pt3 ^ c3ga::ei<double>();
  // viewer.push(plane, 50,50,50);

  // sphere
  c3ga::Mvec<double> sphere =
      c3ga::point<double>(0, 0, 2.0) ^ c3ga::point<double>(2, 0, 2.0) ^
      c3ga::point<double>(1, 1, 2.0) ^ c3ga::point<double>(1, 0, 3.0);
  viewer.push(sphere, 200, 200, 00);

  // circle
  c3ga::Mvec<double> circle = c3ga::point<double>(0, -0.75, 0.5) ^
                              c3ga::point<double>(2, -0.75, 0.5) ^
                              c3ga::point<double>(1, -0.75, 1.5);
  viewer.push(circle, 200, 0, 0);

  // line
  c3ga::Mvec<double> line = c3ga::point<double>(0, -0.75, 2.3) ^
                            c3ga::point<double>(2, -0.75, 2.3) ^
                            c3ga::ei<double>();
  viewer.push(line, 200, 0, 0);

  // circle plane intersection
  c3ga::Mvec<double> pp1 = !circle ^ !plane;
  viewer.push(!pp1, 0, 200, 0);

  // circle sphere intersection
  c3ga::Mvec<double> pp2 = !circle ^ !sphere;
  viewer.push(!pp2, 0, 200, 0);

  // line sphere intersection
  c3ga::Mvec<double> pp3 = !line ^ !sphere;
  viewer.push(!pp3, 0, 200, 0);

  viewer.display();
  viewer.render("output.html");
}

///////////////////////////////////////////////////////////
void sample_polygons() {
  Viewer_c3ga viewer;

  // a set of points
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(2, 3, 0.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(3, 3, 0.5);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(4, 2, 0.5);
  c3ga::Mvec<double> pt5 = c3ga::point<double>(2.5, -2, 0.5);

  // put points on a list
  std::list<c3ga::Mvec<double>> myList;
  myList.push_back(pt1);
  myList.push_back(pt2);
  myList.push_back(pt3);
  myList.push_back(pt4);
  myList.push_back(pt5);

  viewer.pushPolygon(myList, 0, 200, 0);

  viewer.display();
  viewer.render("output.html");
}

void sample_intersect_sphere() {
  Viewer_c3ga viewer;

  // 4  points
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(3, 2, 0.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 3, 0.5);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(2, 2, 2.0);
  viewer.push(pt1, "pt1", 200, 0, 0);
  viewer.push(pt2, "pt2", 200, 0, 0);
  viewer.push(pt3, "pt3", 200, 0, 0);
  viewer.push(pt4, "pt4", 200, 0, 0);

  c3ga::Mvec<double> pt5 = c3ga::point<double>(1.5, 2.5, 0.5);
  c3ga::Mvec<double> pt6 = c3ga::point<double>(3.5, 2.5, 0.5);
  c3ga::Mvec<double> pt7 = c3ga::point<double>(2.5, 3.5, 0.5);
  c3ga::Mvec<double> pt8 = c3ga::point<double>(2.5, 2.5, 2.0);
  viewer.push(pt1, "pt1", 200, 0, 0);
  viewer.push(pt2, "pt2", 200, 0, 0);
  viewer.push(pt3, "pt3", 200, 0, 0);
  viewer.push(pt4, "pt4", 200, 0, 0);

  viewer.push(pt1, "pt5", 200, 0, 0);
  viewer.push(pt2, "pt6", 200, 0, 0);
  viewer.push(pt3, "pt7", 200, 0, 0);
  viewer.push(pt4, "pt8", 200, 0, 0);

  // a sphere
  c3ga::Mvec<double> sphere = pt1 ^ pt2 ^ pt3 ^ pt4;
  viewer.push(sphere, "sphere", 0, 0, 200);
  std::cout << "sphere " << sphere << std::endl;

  // a sphere
  c3ga::Mvec<double> sphere2 = pt5 ^ pt6 ^ pt7 ^ pt8;
  viewer.push(sphere2, "sphere", 0, 0, 200);
  std::cout << "sphere2 " << sphere2 << std::endl;

  auto intersection = !(!sphere ^ !sphere2);

  viewer.push(intersection, "intersection", 200, 0, 200);

  viewer.display();
  viewer.render("output.html");
}

void sample_does_pass_inside_circle() {
  Viewer_c3ga viewer;

  // 4  points
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(3, 2, 0.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 3, 0.5);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(2, 2, 2.0);
  c3ga::Mvec<double> pt5 = c3ga::point<double>(2.5, 2.5, 2);
  viewer.push(pt1, "pt1", 200, 0, 0);
  viewer.push(pt2, "pt2", 200, 0, 0);
  viewer.push(pt3, "pt3", 200, 0, 0);
  viewer.push(pt4, "pt4", 200, 0, 0);
  viewer.push(pt5, "pt5", 200, 0, 0);

  // a sphere
  auto circle = pt1 ^ pt2 ^ pt3;
  viewer.push(circle, "circle", 0, 0, 200);
  std::cout << "circle " << circle << std::endl;

  // a line
  auto line = pt4 ^ pt5 ^ c3ga::ei<double>();

  std::cout << "line " << line << std::endl;

  auto dualSphere = (!line) | circle;

  double radius;
  c3ga::Mvec<double> center = c3ga::point<double>(0, 0, 0);

  radiusAndCenterFromDualSphere(dualSphere, radius, center);

  radius = dualSphere | dualSphere;
  viewer.push(center, "center", 200, 0, 0);
  std::cout << "center" << center << std::endl;
  // viewer.push(dualSphere, "dualSphere", 0,200,200);
  std::cout << "dualSphere " << dualSphere << std::endl;

  std::cout << "Radius" << radius << std::endl;

  if (radius <= 0)
    viewer.push(line, "line", 0, 200, 0);
  else
    viewer.push(line, "line", 200, 0, 0);

  viewer.display();
  viewer.render("output.html");
}

c3ga::Mvec<double> translator(c3ga::Mvec<double> t) {
  return 1 - 0.5 * c3ga::ei<double>() * t;
}

void sample_translation() {
  Viewer_c3ga viewer;

  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(0, 3, 1.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(0, 1, 0);

  auto circle = pt1 ^ pt2 ^ pt3;

  auto t = c3ga::e1<double>() + c3ga::e2<double>() + c3ga::e3<double>();

  auto T = translator(t);

  viewer.push(pt1, "pt1", 255, 0, 0);
  viewer.push(pt2, "pt2", 255, 0, 0);
  viewer.push(pt3, "pt3", 255, 0, 0);

  viewer.push(circle, "circle", 0, 255, 0);

  auto translatedCircle = pt1 ^ pt2 ^ pt3;
  for (int i = 0; i < 10; i++) {
    translatedCircle =
        T * translatedCircle * T.inv(); // * = produit géometrique
    viewer.push(translatedCircle, "translatedCircle", 0, 0, 255);
  }

  viewer.display();
  viewer.render("output.html");
}

c3ga::Mvec<double> rotator(float alpha, const c3ga::Mvec<double> &bivector) {
  return std::cos(0.5 * alpha) - bivector * std::sin(12 * alpha);
}

void sample_rotation() {
  Viewer_c3ga viewer;

  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 1, 1.0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(0, 2, 1.0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(0, 1.5, 2.5);

  auto circle = pt1 ^ pt2 ^ pt3;

  viewer.push(pt1, "pt1", 255, 0, 0);
  viewer.push(pt2, "pt2", 255, 0, 0);
  viewer.push(pt3, "pt3", 255, 0, 0);

  viewer.push(circle, "circle", 0, 255, 0);

  auto rotatedCircle = pt1 ^ pt2 ^ pt3;

  auto bivector = c3ga::e1<double>() ^ c3ga::e2<double>();
  for (float i = 0.1; i < 10.; i += 0.1) {
    auto R = rotator(i, bivector);
    rotatedCircle = R * rotatedCircle * R.inv(); // * = produit géometrique
    rotatedCircle.roundZero();
    viewer.push(rotatedCircle, "rotatedCircle", 0, 0, 255);
  }
  viewer.display();
  viewer.render("output.html");
}

c3ga::Mvec<double> escalator(float s, const c3ga::Mvec<double> &bivector) {
  return 1 - bivector * (1 - s) / (1 + s);
}

void sample_scale() {

  Viewer_c3ga viewer;

  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 1, 1.0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(1, 2, 1.0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(1, 1.5, 2.5);

  auto circle = pt1 ^ pt2 ^ pt3;

  viewer.push(pt1, "pt1", 255, 0, 0);
  viewer.push(pt2, "pt2", 255, 0, 0);
  viewer.push(pt3, "pt3", 255, 0, 0);

  viewer.push(circle, "circle", 0, 255, 0);

  auto scaledCircle = pt1 ^ pt2 ^ pt3;

  auto bivector = c3ga::e0<double>() ^ c3ga::ei<double>();
  for (float i = 0.1; i < 10.; i += 0.1) {
    auto S = escalator(i, bivector);
    scaledCircle = S * scaledCircle * S.inv(); // * = produit géometrique
    scaledCircle.roundZero(1.0e-10);
    viewer.push(scaledCircle, "scaledCircle", 0, 0, 255);
  }
  viewer.display();
  viewer.render("output.html");
}

void sample_is_point_in_sphere() {
  Viewer_c3ga viewer;

  // 4  points
  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 2, 0.5);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(3, 2, 0.5);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 3, 0.5);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(2, 2, 2.0);
  c3ga::Mvec<double> pt5 = c3ga::point<double>(2.5, 2.5, 2);
  c3ga::Mvec<double> pt6 = c3ga::point<double>(1.5, 1.5, 0.5);
  viewer.push(pt1, "pt1", 200, 0, 0);
  viewer.push(pt2, "pt2", 200, 0, 0);
  viewer.push(pt3, "pt3", 200, 0, 0);
  viewer.push(pt4, "pt4", 200, 0, 0);
  viewer.push(pt5, "pt5", 200, 200, 0);
  viewer.push(pt6, "pt6", 200, 200, 0);

  // a sphere
  auto sphere = pt1 ^ pt2 ^ pt3 ^ pt4;

  // a point
  auto point = pt5; //^ c3ga::ei<double>();

  std::cout << "point " << point << std::endl;
  viewer.push(point, "point", 0, 200, 0);
  auto scalar = (!(!point ^ !sphere));
  auto pointIsInSphere = scalar <= 0;
  std::cout << " Scalar = " << scalar << std::endl;

  if (pointIsInSphere) {
    viewer.push(sphere, "sphere", 0, 200, 0);
  } else {
    viewer.push(sphere, "sphere", 200, 0, 0);
  }
  std::cout << "sphere " << sphere << std::endl;
  /*
    auto dualSphere = (!point) | sphere;

    double radius;
    c3ga::Mvec<double> center = c3ga::point<double>(0, 0, 0);

    radiusAndCenterFromDualSphere(dualSphere, radius, center);

    radius = dualSphere | dualSphere;
    viewer.push(center, "center", 200, 0, 0);
    std::cout << "center" << center << std::endl;
    // viewer.push(dualSphere, "dualSphere", 0,200,200);
    std::cout << "dualSphere " << dualSphere << std::endl;

    std::cout << "Radius" << radius << std::endl;

    if (radius <= 0)
      viewer.push(point, "point", 0, 200, 0);
    else
      viewer.push(point, "point", 200, 0, 0);
  */
  viewer.display();
  viewer.render("output.html");
}
void sample_draw_sphere_from_point_and_radius() {
  Viewer_c3ga viewer;

  c3ga::Mvec<double> pt1 = c3ga::point<double>(1, 1, 1);
  auto radius = 2.;
  auto dualSphere = pt1 - ((radius * radius) / 2 * c3ga::ei<double>());

  auto sphere = !dualSphere;

  std::cout << c3ga::whoAmI(sphere) << std::endl;
  viewer.push(pt1, "pt1", 255, 0, 0);

  viewer.push(sphere, "sphere", 255, 255, 0);

  viewer.display();
  viewer.render("output.html");
}

void sample_generate_tetraedre() {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(0.5, 1, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(1, 0, 0);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(0.5, 0.5, 1);
  viewer.push(pt1, "pt1", 255, 255, 0);
  viewer.push(pt2, "pt2", 255, 255, 0);
  viewer.push(pt3, "pt3", 255, 255, 0);
  viewer.push(pt4, "pt4", 255, 255, 0);
  c3ga::Mvec<double> line1 = pt1 ^ pt2 ^ ei;
  c3ga::Mvec<double> line2 = pt1 ^ pt3 ^ ei;
  c3ga::Mvec<double> line3 = pt1 ^ pt4 ^ ei;
  c3ga::Mvec<double> line4 = pt2 ^ pt3 ^ ei;
  c3ga::Mvec<double> line5 = pt2 ^ pt4 ^ ei;
  c3ga::Mvec<double> line6 = pt3 ^ pt4 ^ ei;
  viewer.push(line1, 0, 0, 255);
  viewer.push(line2, 0, 0, 255);
  viewer.push(line3, 0, 0, 255);
  viewer.push(line4, 0, 0, 255);
  viewer.push(line5, 0, 0, 255);
  viewer.push(line6, 0, 0, 255);

  viewer.display();
  viewer.render("output.html");
}

void test() {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(0.5, 1, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(1, 0, 0);
  c3ga::Mvec<double> line1 = pt1 ^ pt2 ^ ei;

  viewer.push(line1, "line", 255, 255, 0);
  viewer.push(pt3, "pt3", 0, 255, 0);

  // viewer.push((!(line1 | (pt3^ei))), "dot", 0, 255, 255);
  // viewer.push(!((!line1) | pt3), "dot", 0, 255, 255);

  viewer.display();
  viewer.render("output.html");
}

void sample_plane_cross_sphere() {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(0.5, 1, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(0.5, 0.5, 1);

  c3ga::Mvec<double> pt4 = c3ga::point<double>(3, 7, 5);

  c3ga::Mvec<double> plane = pt1 ^ pt2 ^ pt3 ^ ei;

  auto r = 1;
  auto dualSphere = pt4 - ((r * r) / 2 * c3ga::ei<double>());

  auto sphere = !dualSphere;

  c3ga::Mvec<double> intersect = !((!plane) ^ (!sphere));
  c3ga::Mvec<double> center;
  c3ga::Mvec<double> direction;

  double radius = (intersect | intersect);

  std::cout << c3ga::whoAmI(intersect) << std::endl;
  std::cout << radius << std::endl;
  viewer.push(plane, 0, 0, 255);
  viewer.push(sphere, 255, 0, 255);
  viewer.push(intersect, 0, 255, 0);
  viewer.display();
  viewer.render("output.html");
}

void sample_generate_tetraedre_cross_sphere() {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  // TETRAEDRE
  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(1, 2, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 0, 0);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(1, 1, 2);
  viewer.push(pt1, "pt1", 255, 255, 0);
  viewer.push(pt2, "pt2", 255, 255, 0);
  viewer.push(pt3, "pt3", 255, 255, 0);
  viewer.push(pt4, "pt4", 255, 255, 0);
  c3ga::Mvec<double> line12 = pt1 ^ pt2 ^ ei;
  c3ga::Mvec<double> line13 = pt1 ^ pt3 ^ ei;
  c3ga::Mvec<double> line14 = pt1 ^ pt4 ^ ei;
  c3ga::Mvec<double> line23 = pt2 ^ pt3 ^ ei;
  c3ga::Mvec<double> line24 = pt2 ^ pt4 ^ ei;
  c3ga::Mvec<double> line34 = pt3 ^ pt4 ^ ei;
  viewer.push(line12, 0, 0, 255);
  viewer.push(line13, 0, 0, 255);
  viewer.push(line14, 0, 0, 255);
  viewer.push(line23, 0, 0, 255);
  viewer.push(line24, 0, 0, 255);
  viewer.push(line34, 0, 0, 255);

  c3ga::Mvec<double> plane123 = line12 ^ pt3;
  c3ga::Mvec<double> plane234 = line23 ^ pt4;
  c3ga::Mvec<double> plane124 = line12 ^ pt4;
  c3ga::Mvec<double> plane134 = line13 ^ pt4;

  /*viewer.push(plane123, 255, 255, 255);
  viewer.push(plane234, 255, 255, 255);
  viewer.push(plane124, 255, 255, 255);
  viewer.push(plane134, 255, 255, 255);*/

  // SPHERE

  c3ga::Mvec<double> center = c3ga::point<double>(1, 1, 1);
  auto radius = 1.;
  auto dualSphere = center - (((radius * radius) / 2) * c3ga::ei<double>());
  viewer.push(center, "center", 200, 200, 200);
  viewer.push(dualSphere, "DualSphere", 200, 0, 0);

  // INTERSECTION
  c3ga::Mvec<double> intersection1 = !((!plane123) ^ (dualSphere));
  c3ga::Mvec<double> intersection2 = !((!plane234) ^ (dualSphere));
  c3ga::Mvec<double> intersection3 = !((!plane124) ^ (dualSphere));
  c3ga::Mvec<double> intersection4 = !((!plane134) ^ (dualSphere));

  std::cout << "Intersection 1 : " << c3ga::whoAmI(intersection1) << std::endl;
  std::cout << "Intersection 2 : " << c3ga::whoAmI(intersection2) << std::endl;
  std::cout << "Intersection 3 : " << c3ga::whoAmI(intersection3) << std::endl;
  std::cout << "Intersection 4 : " << c3ga::whoAmI(intersection4) << std::endl;

  viewer.push(intersection1, 0, 200, 0);
  viewer.push(intersection2, 0, 200, 0);
  viewer.push(intersection3, 0, 200, 0);
  viewer.push(intersection4, 0, 200, 0);

  double intersect2Radius;
  c3ga::Mvec<double> intersect2Center, intersect2Direction;
  extractDualCircle(intersection2.dual(), intersect2Radius, intersect2Center,
                    intersect2Direction);

  c3ga::Mvec<double> lineIntersection2 = center ^ intersect2Center ^ ei;
  std::cout << "Intersection 2 line : " << c3ga::whoAmI(lineIntersection2)
            << std::endl;
  viewer.push(intersect2Center, 200, 200, 0);
  viewer.push(center, 200, 200, 0);

  viewer.display();
  viewer.render("output.html");

}

void sampleLeftOrRightToCircle(){
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  c3ga::Mvec<double> pt = c3ga::point<double>(1, 1, 1);
  c3ga::Mvec<double> ptBis = c3ga::point<double>(1, 1, -1);

  c3ga::Mvec<double> center = c3ga::point<double>(0, 0, 0);
  double radius = 2.;

  c3ga::Mvec<double> dualSphere = center  - (((radius * radius) / 2) * c3ga::ei<double>());
  c3ga::Mvec<double> plan = c3ga::point<double>(1, 1, 0) ^ c3ga::point<double>(1, 0, 0) ^ c3ga::point<double>(2, 2, 0) ^ ei;

  c3ga::Mvec<double> circle = !((dualSphere)^(!plan));

  c3ga::Mvec<double> intersect = !((!circle)^(pt));
  c3ga::Mvec<double> intersectBis = !((!circle)^(ptBis));

  std::cout<< c3ga::whoAmI(intersect) << std::endl;
  std::cout<< c3ga::whoAmI(intersectBis) << std::endl;

  viewer.push(circle, "circle", 255, 0 ,0);
  viewer.push(pt, "pt", 255, 0 ,0);
  viewer.push(ptBis,"ptBis", 255, 0 ,0);
  viewer.push(intersect,"intersect", 0,255,0);
  viewer.push(intersectBis,"intersect bis", 0, 0, 255);

  viewer.display();
  viewer.render("output.html");
}

bool isImaginaryCircle(c3ga::Mvec<double> multiVector) {
  return c3ga::whoAmI(std::move(multiVector)) ==
         "imaginary circle (dual pair point)";
}

bool isRealCircle(c3ga::Mvec<double> multiVector) {
  return c3ga::whoAmI(std::move(multiVector)) ==
         "circle (imaginary dual pair point)";
}

bool isRealPairPoint(c3ga::Mvec<double> multiVector) {
  return c3ga::whoAmI(std::move(multiVector)) ==
      "pair point (imaginary dual circle)";
}

bool isTangentBiVector(c3ga::Mvec<double> multiVector) {
  return c3ga::whoAmI(std::move(multiVector)) ==
         "tangent bivector (dual tangent vector)";
}

c3ga::Mvec<double> randomPointBetween(const double minorBound,
                                      const double majorBound) {
  assert(minorBound < majorBound);
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  // generator
  std::default_random_engine generator(seed);

  // unifirm distribution over [-1,1]
  std::uniform_real_distribution<double> uniformRealDistribution(minorBound,
                                                                 majorBound);

  // build the point
  return c3ga::point(uniformRealDistribution(generator),
                     uniformRealDistribution(generator),
                     uniformRealDistribution(generator));
}

void sample_grossissement_sphere(int n) {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  // TETRAEDRE
  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(1, 2, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 0, 0);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(1, 1, 2);
  viewer.push(pt1, "pt1", 255, 255, 0);
  viewer.push(pt2, "pt2", 255, 255, 0);
  viewer.push(pt3, "pt3", 255, 255, 0);
  viewer.push(pt4, "pt4", 255, 255, 0);
  c3ga::Mvec<double> line12 = pt1 ^ pt2 ^ ei;
  c3ga::Mvec<double> line13 = pt1 ^ pt3 ^ ei;
  c3ga::Mvec<double> line14 = pt1 ^ pt4 ^ ei;
  c3ga::Mvec<double> line23 = pt2 ^ pt3 ^ ei;
  c3ga::Mvec<double> line24 = pt2 ^ pt4 ^ ei;
  c3ga::Mvec<double> line34 = pt3 ^ pt4 ^ ei;
  viewer.push(line12, 0, 0, 255);
  viewer.push(line13, 0, 0, 255);
  viewer.push(line14, 0, 0, 255);
  viewer.push(line23, 0, 0, 255);
  viewer.push(line24, 0, 0, 255);
  viewer.push(line34, 0, 0, 255);

  c3ga::Mvec<double> plane123 = line12 ^ pt3;
  c3ga::Mvec<double> plane234 = line23 ^ pt4;
  c3ga::Mvec<double> plane124 = line12 ^ pt4;
  c3ga::Mvec<double> plane134 = line13 ^ pt4;

 /* c3ga::Mvec<double> circle123 = pt1 ^ pt2 ^ pt3;
  c3ga::Mvec<double> circle234 = pt2 ^ pt3 ^ pt4;
  c3ga::Mvec<double> circle124 = pt1 ^ pt2 ^ pt4;
  c3ga::Mvec<double> circle134 = pt1 ^ pt3 ^ pt4;
  viewer.push(circle123,0,0,255);
  viewer.push(circle234,0,0,255);
  viewer.push(circle124,0,0,255);
  viewer.push(circle134,0,0,255);*/

  std::vector<c3ga::Mvec<double>> planeList;
  planeList.push_back(plane123);
  planeList.push_back(plane234);
  planeList.push_back(plane124);
  planeList.push_back(plane134);

  // SPHERES
  // c3ga::Mvec<double> center = c3ga::point<double>(1, 1, 1);

  std::vector<c3ga::Mvec<double>> toTestCenterList;
  std::vector<c3ga::Mvec<double>> resultCenterList;

  for (int i = 0; i < n; ++i) {
    toTestCenterList.push_back(randomPointBetween(0, 2.0));
  }

  double radius = 0.01;

  // INTERSECTIONS
  while (!toTestCenterList.empty()) {
    std::vector<c3ga::Mvec<double>> notIntersectingCenterList;
    for (const auto &center : toTestCenterList) {
      auto dualSphere = center - (((radius * radius) / 2) * c3ga::ei<double>());
      //viewer.push(center, "center", 200, 0, 0);
      // viewer.push(dualSphere, "DualSphere", (int)(255*radius)% 255,
      // (int)(255*radius)% 255, (int)(255*radius)% 255);
      std::vector<c3ga::Mvec<double>> realIntersectionList;

      for (const auto &plane : planeList) {
        c3ga::Mvec<double> intersection = !((!plane) ^ (dualSphere));
        /*std::cout << "Intersection: " << c3ga::whoAmI(intersection)
                  << std::endl;*/
        // viewer.push(intersection, 0, 200, 0);
        /*double intersectRadius;
        c3ga::Mvec<double> intersectCenter, intersectDirection;
        extractDualCircle(intersection.dual(), intersectRadius, intersectCenter,
                          intersectDirection);*/
        // viewer.push(intersectCenter, "intersect center", 200, 200, 0);
        if (isRealCircle(intersection) || isTangentBiVector(intersection))
          realIntersectionList.push_back(intersection);
      }

      if (realIntersectionList.size() >= 2) {
        // Result point
        std::cout << "OK" << std::endl;
        resultCenterList.push_back(center);
      }
      if (realIntersectionList.size() == 1) {
        // Not good point
        std::cout << "Not good point" << std::endl;
      }
      if (realIntersectionList.empty()) {
        // Not big enough
        std::cout << "Empty" << std::endl;
        notIntersectingCenterList.push_back(center);
      }
      if (radius > 1.)
        continue;
      radius += 0.01;
    }
    toTestCenterList = notIntersectingCenterList;
  }

  for (const auto& resultCenter : resultCenterList) {
    viewer.push(resultCenter, 0, 255, 0);
  }
  viewer.display();
  viewer.render("output.html");
}


void sample_grossissement_sphere_with_circles(int n) {
  Viewer_c3ga viewer;
  c3ga::Mvec<double> ei = c3ga::ei<double>();

  // TETRAEDRE
  c3ga::Mvec<double> pt1 = c3ga::point<double>(0, 0, 0);
  c3ga::Mvec<double> pt2 = c3ga::point<double>(1, 2, 0);
  c3ga::Mvec<double> pt3 = c3ga::point<double>(2, 0, 0);
  c3ga::Mvec<double> pt4 = c3ga::point<double>(1, 1, 2);
  viewer.push(pt1, "pt1", 255, 255, 0);
  viewer.push(pt2, "pt2", 255, 255, 0);
  viewer.push(pt3, "pt3", 255, 255, 0);
  viewer.push(pt4, "pt4", 255, 255, 0);
  c3ga::Mvec<double> line12 = pt1 ^ pt2 ^ ei;
  c3ga::Mvec<double> line13 = pt1 ^ pt3 ^ ei;
  c3ga::Mvec<double> line14 = pt1 ^ pt4 ^ ei;
  c3ga::Mvec<double> line23 = pt2 ^ pt3 ^ ei;
  c3ga::Mvec<double> line24 = pt2 ^ pt4 ^ ei;
  c3ga::Mvec<double> line34 = pt3 ^ pt4 ^ ei;
  viewer.push(line12, 0, 0, 255);
  viewer.push(line13, 0, 0, 255);
  viewer.push(line14, 0, 0, 255);
  viewer.push(line23, 0, 0, 255);
  viewer.push(line24, 0, 0, 255);
  viewer.push(line34, 0, 0, 255);

   c3ga::Mvec<double> circle123 = pt1 ^ pt2 ^ pt3;
   c3ga::Mvec<double> circle234 = pt2 ^ pt3 ^ pt4;
   c3ga::Mvec<double> circle124 = pt1 ^ pt2 ^ pt4;
   c3ga::Mvec<double> circle134 = pt1 ^ pt3 ^ pt4;
   /*viewer.push(circle123,0,0,255);
   viewer.push(circle234,0,0,255);
   viewer.push(circle124,0,0,255);
   viewer.push(circle134,0,0,255);*/

  std::vector<c3ga::Mvec<double>> circleList;
  circleList.push_back(circle123);
  circleList.push_back(circle234);
  circleList.push_back(circle124);
  circleList.push_back(circle134);

  // SPHERES
  // c3ga::Mvec<double> center = c3ga::point<double>(1, 1, 1);

  std::vector<c3ga::Mvec<double>> toTestCenterList;
  std::vector<c3ga::Mvec<double>> resultCenterList;


  c3ga::Mvec<double> ptEliminator = c3ga::point<double>(-5, -5, -5);

  int i = 0;
  while (i < n) {
    c3ga::Mvec<double> ptRandom = randomPointBetween(0, 2.0);
    auto line = ptEliminator ^ ptRandom ^ ei;

    int count = 0;
    for(const auto& circle : circleList) {
      auto intersect = !((!line) ^ (!circle));
      //std::cout << c3ga::whoAmI(intersect) << std::endl;
      if(c3ga::whoAmI(intersect) == "dual sphere") count++;
    }
    /*viewer.push(ptRandom, 255,0,0);
    viewer.push(line, 0,0,0);*/
    if(count%2 != 0) {
      toTestCenterList.push_back(ptRandom);
      i++;
      std::cout << i << std::endl;
    }
  }

  double radius = 0.001;

  // INTERSECTIONS
  while (!toTestCenterList.empty()) {
    std::vector<c3ga::Mvec<double>> notIntersectingCenterList;
    for (const auto &center : toTestCenterList) {
      auto dualSphere = center - (((radius * radius) / 2) * c3ga::ei<double>());
      //viewer.push(center, "center", 200, 0, 0);
      // viewer.push(dualSphere, "DualSphere", (int)(255*radius)% 255,
      // (int)(255*radius)% 255, (int)(255*radius)% 255);
      std::vector<c3ga::Mvec<double>> realIntersectionList;

      for (const auto &circle : circleList) {
        c3ga::Mvec<double> intersection = !((!circle) ^ (dualSphere));

        // viewer.push(intersection, 0, 200, 0);
        /*double intersectRadius;
        c3ga::Mvec<double> intersectCenter, intersectDirection;
        extractDualCircle(intersection.dual(), intersectRadius, intersectCenter,
                          intersectDirection);*/
        // viewer.push(intersectCenter, "intersect center", 200, 200, 0);
        if (isRealPairPoint(intersection))
          realIntersectionList.push_back(intersection);
        else {
           std::string s = c3ga::whoAmI(intersection);
           if (s != "imaginary pair point (dual circle)") std::cout << s << std::endl;
        }

      }

      if (realIntersectionList.size() >= 2) {
        // Result point
        //std::cout << "OK" << std::endl;
        resultCenterList.push_back(center);
        //viewer.push(dualSphere, 200,200,200);
      } else if (realIntersectionList.size() == 1) {
        // Not good point
        //std::cout << "Not good point" << std::endl;
      } else if (realIntersectionList.empty()) {
        // Not big enough
        //std::cout << "Empty" << std::endl;
        notIntersectingCenterList.push_back(center);
      }

    }
    /*if (radius > 1.)
      break;
    std::cout << radius << std::endl;*/
    radius += 0.001;
    toTestCenterList = notIntersectingCenterList;
  }

  for (const auto& resultCenter : resultCenterList) {
    viewer.push(resultCenter, 0, 255, 0);
  }
  viewer.display();
  viewer.render("output.html");
}
///////////////////////////////////////////////////////////

/**
 *
 * | inner product
 * * geometric product
 *
 *
 */
int main() {

  // sample1();

  // sample2();

  // sample_polygons();

  // sample_intersect_sphere();

  // sample_does_pass_inside_circle();

  // sample_translation();

  // sample_rotation();

  // sample_scale();

  // sample_is_point_in_sphere();

  // sample_draw_sphere_from_point_and_radius();

  // sample_generate_tetraedre();

  // sample_plane_cross_sphere();

  // test();

  // sample_generate_tetraedre_cross_sphere();

  //sample_grossissement_sphere(150);

  //sampleLeftOrRightToCircle();

  sample_grossissement_sphere_with_circles(10000);
  return 0;
}