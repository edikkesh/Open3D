# Open3D: www.open3d.org
# The MIT License (MIT)
# See license file or visit www.open3d.org for details

# examples/Python/Basic/solution.py

import sys
import open3d as o3d

if __name__ == "__main__":

    mesh = o3d.io.read_triangle_mesh("../../TestData/test_mesh.ply")

    if not mesh.has_triangles():
        sys.exit()

    mesh.identically_colored_connected_components()
    connected_components = mesh.identically_colored_connected_components_list;

    print('Number of connected components: %d\r\n'%len(connected_components))

    # Write the results in the results.txt file with the specified format
    outfile = open("results.txt", "w")

    for connComp in connected_components:
        orderedSet = sorted(connComp)
        for comp in orderedSet:
            outfile.write('%d '%comp)
        outfile.write('\n')

    outfile.close()
