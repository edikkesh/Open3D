This repository is a clone of the Open3D repository with extended functionality for finding connected components of a triangle mesh with identical colors.
The original Open3D repository can be found here: https://github.com/intel-isl/Open3D

Requirements for this enhancement are detailed in the <b>requirement.pdf</b> document.

## Building the new Open3D
	Please follow the build instructions given at the original Open3D site (above link). 

## Testing the new functionality
	The code was developed and tested on Windows.
	One C++ sample program and one Python script are added to the examples.
	A test case is also added to the set of unit tests.
	
* The C++ example executable is located at Open3D\build\bin\examples\Debug.
	The program accepts the name of a mesh file as a parameter as follows:
	
		solution test_mesh.ply
		
	The program writes a sorted list of sorted lists in a file named <b>results.txt</b>.
		
* The python example is located at Open3D\examples\Python\Basic. It can be run as follows:
	
		python solution.py
		
	The script writes a sorted list of sorted lists in a file named <b>results.txt</b>.
		
* The test is called <b>ColoredTriangleMesh.IdenticallyColoredConnectedComponents</b>.
	The program <b>unitTests</b> is located at Open3D\build\bin\Debug. Run the test as follows:
	
		unitTests --gtest_filter=ColoredTriangleMesh.IdenticallyColoredConnectedComponents

## New and modified files
	CMakeLists.txt
	examples/Cpp/CMakeLists.txt
	examples/Cpp/solution.cpp (new)
	examples/Python/Basic/solution.py (new)
	examples/TestData/results.txt (new)
	examples/TestData/test_mesh.ply (new)
	src/Open3D/Geometry/TriangleMesh.cpp
	src/Open3D/Geometry/TriangleMesh.h
	src/Python/open3d_pybind/geometry/trianglemesh.cpp
	src/UnitTest/Geometry/ColoredTriangleMesh.cpp (new)
	
## Algorithm design

The algorithm is implemented as a method of the class <b>TriangleMesh</b>. Since the algorithm is fairly straightforward we only present the C++ code and not the psuedo code.

The core idea is to iterate through all the vertices of the mesh and for each vertex find the adjacent vertices and retain the ones that have the same color as the vertex. This is done recursively until a complete set of identically-colored and connected vertices is identified. An identified set is stored in a data member representing a set of sets. The choice for the type of the data member follows the pattern used in the Open3D design. The data member declaration is as follows:

	std::vector<std::set<int>> identically_colored_connected_components_list_;
	
The choice for the signuture of the funtion also follows the pattern used with similar functions in Open3D. As can be seen from the code below, our implementation uses two nested loops to simulate recursion. 

	TriangleMesh &TriangleMesh::IdenticallyColoredConnectedComponents() {
	    if (!HasAdjacencyList()) {
		ComputeAdjacencyList();
	    }
    
	    std::vector<bool> visited(vertices_.size(), false);

	    for (int vidx = 0; vidx < vertices_.size(); vidx++) {
		if (visited[vidx]) continue;

		std::set<int> identicallyColoredPatch;
		identicallyColoredPatch.insert(vidx);
		visited[vidx] = true;

		Eigen::Vector3d color = vertex_colors_[vidx];
		std::queue<int> queue;

		queue.push(vidx);
		while (!queue.empty()) {
		    int idx = queue.front();
		    queue.pop();

		    std::unordered_set<int> adjacents = adjacency_list_[idx];

		    for (auto nidx : adjacents) {
			if (vertex_colors_[nidx] == color && !visited[nidx]) {
			    identicallyColoredPatch.insert(nidx);
			    visited[nidx] = true;
			    queue.push(nidx);
			}
		    }
		}

		identically_colored_connected_components_list_.push_back(identicallyColoredPatch);
	    }

	    return *this;
	}

## Notes
* Our C++ implementaion generates a sorted list of sorted lists (std::vector< std::set<int> >). However, when the data is accessed in our Python example (solution.py), the individual member lists are no longer sorted. As a remedy, we sort the individual lists inside the Python script before writing them to the output file.
	
* In Visual Studio, the option <b>/biobj</b> should be added as a command line option for project <b>Geometry</b>.

* In Visual Studio, the library <b>pthread.lib</b> should be removed from the link libraries list for project <b>unitTests</b>.
