EXEC = raytracer

BINDIR = bin
OBJDIR = obj
SRCDIR = src

CXX = g++
CXXFLAGS = -Wall

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

$(BINDIR)/$(EXEC): $(OBJDIR) $(OBJECTS) $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

$(BINDIR):
	mkdir -p ./$(BINDIR)

$(OBJDIR):
	mkdir -p ./$(OBJDIR)

$(OBJDIR)/Main.o: $(SRCDIR)/Main.cpp $(OBJDIR)/RayTracer.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/RayTracer.o: $(SRCDIR)/RayTracer.cpp $(SRCDIR)/RayTracer.hpp $(OBJDIR)/Plane.o $(OBJDIR)/Sphere.o $(OBJDIR)/Triangle.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Plane.o: $(SRCDIR)/Plane.cpp $(SRCDIR)/Plane.hpp $(OBJDIR)/Object.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Sphere.o: $(SRCDIR)/Sphere.cpp $(SRCDIR)/Sphere.hpp $(OBJDIR)/Object.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Triangle.o: $(SRCDIR)/Triangle.cpp $(SRCDIR)/Triangle.hpp $(OBJDIR)/Object.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Object.o: $(SRCDIR)/Object.cpp $(SRCDIR)/Object.hpp $(OBJDIR)/Ray.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Ray.o: $(SRCDIR)/Ray.cpp $(SRCDIR)/Ray.hpp $(OBJDIR)/Vector3D.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/Vector3D.o: $(SRCDIR)/Vector3D.cpp $(SRCDIR)/Vector3D.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR) $(OBJDIR)