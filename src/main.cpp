#include <c3ga/Mvec.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>

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

  //viewer.push((!(line1 | (pt3^ei))), "dot", 0, 255, 255);
  //viewer.push(!((!line1) | pt3), "dot", 0, 255, 255);


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

  c3ga::Mvec<double> plane = pt1 ^ pt2 ^ pt3^ ei;

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

  test();
  return 0;
}