This repository is a clone of the Open3D repository with extended functionality for finding connected components of a triangle mesh with identical colors.
The original Open3D repository can be found here: https://github.com/intel-isl/Open3D

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
