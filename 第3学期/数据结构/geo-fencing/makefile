main: main.o yourcode/Point.o yourcode/PointInPolygon.o yourcode/RTreeUsage.o yourcode/triangulate.o yourcode/submit-1AddPolygonBeforeQueryPoint.o yourcode/submit-2AddPointBeforeQueryPolygon.o yourcode/submit-3AddBeforeQuery.o yourcode/submit-4MixQueryPoint.o yourcode/submit-5MixQueryPolygon.o yourcode/submit-6MixQuery.o
	g++ -o main main.o yourcode/Point.o yourcode/PointInPolygon.o yourcode/RTreeUsage.o yourcode/triangulate.o yourcode/submit-1AddPolygonBeforeQueryPoint.o yourcode/submit-2AddPointBeforeQueryPolygon.o yourcode/submit-3AddBeforeQuery.o yourcode/submit-4MixQueryPoint.o yourcode/submit-5MixQueryPolygon.o yourcode/submit-6MixQuery.o
main.o: main.cpp
	g++ -O2 -std=c++11 -c -o main.o main.cpp
%.o: yourcode/%.cpp
	g++ -O2 -std=c++11 -c -o $@ $<