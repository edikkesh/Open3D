This repository is a clone of the Open3D repository with extended functionality for finding connected components of a triangle mesh with identical colors.
The original Open3D repository can be found here: https://github.com/intel-isl/Open3D

# Requirements
	Implement a function to return a list of identically-colored connected  components. An identically-colored connected component is a connected  component where each vertex in the component has the same color. In this  question, a connected component is represented by a list of vertex indices.    Example triangle mesh 
  A triangle mesh is represented by vertices and triangles.    In this example, there are 7 vertices:  [0, 1, 2, 3, 4, 5, 6]    There are 6 triangles:  [(0, 2, 3), (0, 3, 1), (1, 3, 4), (2, 5, 3), (3, 5, 6), (3, 6, 4)]    Each vertex has a color:  [red, red, blue, blue, green, red, red]    Given this mesh, the expected output of IdenticallyColoredConnectedComponents  is:  [[0, 1], [2, 3], [4], [5, 6]]  where the order of the lists are sorted ascendingly by the smallest element in  each list; and within each list, the vertices are sorted ascendingly by their  indices.    We then write the results into "​ results.txt"​ , where each line in the text file  represents one connected component. In each line, vertex indices are separated  by space:  ```  0 1  2 3  4  5 6  ```  

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
