// jpu fs helper library
// Copyright 2025 Adam Perkowski.
// Use of this source code is governed by the BSD 3-Clause License.
// See the LICENSE file for details.

#ifndef FS_HPP
#define FS_HPP

#include <string>

bool extractTarGz(const std::string& filename, const std::string& outputDir) {
    std::string cmd = "tar -xzf " + filename + " -C " + outputDir; // FIXME: security risk, i hate this personally
    return system(cmd.c_str()) == 0;
}

#endif // FS_HPP
