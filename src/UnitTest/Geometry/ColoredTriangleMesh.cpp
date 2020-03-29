// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2020 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#include "Open3D/Open3D.h"
#include "TestUtility/UnitTest.h"

using namespace open3d;
using namespace std;
using namespace unit_test;

TEST(ColoredTriangleMesh, IdenticallyColoredConnectedComponents) {
    geometry::TriangleMesh mesh;
    std::string filename("../../../examples/TestData/test_mesh.ply");
    if (io::ReadTriangleMesh(filename, mesh)) {
        utility::LogInfo("Successfully read {}\n", filename);
    } else {
        utility::LogWarning("Failed to read {}\n", filename);
        EXPECT_TRUE(false);
    }

    //
    // Verify the accuracy of total counts
    //
    // Get the connected components of the original model
    mesh.IdenticallyColoredConnectedComponents();
    auto connected_components =
            mesh.identically_colored_connected_components_list_;

    // Print connected_components in the specified format
    size_t coloredCount = 0;
    for (auto connComp : connected_components) {
        for (auto comp : connComp) {
            printf("%d ", comp);
            coloredCount++;
        }
        printf("\n");
    }
    utility::LogInfo("Vertex count: {}, Colored count: {}",
                     mesh.vertices_.size(), coloredCount);

    EXPECT_TRUE(coloredCount == mesh.vertices_.size());

    //
    // Verify that connected componenets are exclusive of each other
    //
    auto itr1 = connected_components.begin();
    for (; itr1 != connected_components.end()-1; itr1++) {
        auto itr2 = itr1 + 1;
        for (auto num : *itr1) {
            EXPECT_TRUE(itr2->find(num) == itr2->end());
        }
    }

    // The model contains two distinct meshes resulting in
    // two distinct connected components.
    // We clone the model and paint it with a uniform color so that
    // we can verify that the number of distinct components is 2.
    geometry::TriangleMesh uniformMesh(mesh.vertices_, mesh.triangles_);
    uniformMesh.PaintUniformColor(Eigen::Vector3d(0.5, 0.5, 0.5));

    // Get the connected components of the uniform model
    uniformMesh.IdenticallyColoredConnectedComponents();
    connected_components =
            uniformMesh.identically_colored_connected_components_list_;

    EXPECT_TRUE(2 == connected_components.size());

    std::vector<std::set<int>>::const_iterator uiter =
            connected_components.begin();
    EXPECT_TRUE(*uiter ==
                std::set<int>({0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                               22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
                               33, 34, 35, 36, 37, 38, 39, 40, 41}));
    std::advance(uiter, 1);
    EXPECT_TRUE(*uiter ==
                std::set<int>({42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
                               53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
                               64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
                               75, 76, 77, 78, 79, 80, 81, 82, 83}));
}
