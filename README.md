This repository is a clone of the Open3D repository with extended functionality for finding connected components of a triangle mesh with identical colors.
The original Open3D repository can be found here: https://github.com/intel-isl/Open3D

Requirements for this enhancement are detailed in the requirement.pdf document.

## Building the new Open3D
	Please follow the build instructions given at the original Open3D site (above link).

## Testing the new functionality
	The code is tested on Windows.
	
* The C++ example executable is located at Open3D\build\bin\examples\Debug.
	The program accepts the name of a mesh file as a parameter:
	
		solution test_mesh.ply
		
	The program writes a sorted list of sorted lists in a file named "results.txt".
		
* The python example is located at Open3D\examples\Python\Basic. It can be run as follows:
	
		python solution.py
		
	The script writes a sorted list of sorted lists in a file named "results.txt".
		
* The test is called ColoredTriangleMesh.IdenticallyColoredConnectedComponents.
	The program unitTests is located at Open3D\build\bin\Debug. Run the test as follows:
	
		unitTests --gtest_filter=ColoredTriangleMesh.IdenticallyColoredConnectedComponents

## New or modified files
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

## Core features

* 3D data structures
* 3D data processing algorithms
* Scene reconstruction
* Surface alignment
* 3D visualization
* Python binding

## Supported OSes and compilers

* Ubuntu 16.04 or newer: GCC 5.x or newer [![Build Status](https://travis-ci.org/intel-isl/Open3D.svg?branch=master)](https://travis-ci.org/intel-isl/Open3D)
* macOS: XCode 8.0 or newer [![Build Status](https://travis-ci.org/intel-isl/Open3D.svg?branch=master)](https://travis-ci.org/intel-isl/Open3D)
* Windows: Visual Studio 2017 or newer [![Build status](https://ci.appveyor.com/api/projects/status/3hasjo041lv6srsi/branch/master?svg=true)](https://ci.appveyor.com/project/yxlao/open3d/branch/master)

## Citation
Please cite [our work](https://arxiv.org/abs/1801.09847) if you use Open3D.

```
@article{Zhou2018,
	author    = {Qian-Yi Zhou and Jaesik Park and Vladlen Koltun},
	title     = {{Open3D}: {A} Modern Library for {3D} Data Processing},
	journal   = {arXiv:1801.09847},
	year      = {2018},
}
```
