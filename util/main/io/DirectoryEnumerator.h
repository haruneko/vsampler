/**
 * Created by Hal@shurabaP on 2015/06/11.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_FILEENUMERATOR_H
#define VSAMPLER_FILEENUMERATOR_H

#include <functional>
#include <QDir>
#include <QFileInfo>
#include <QList>

namespace vsampler {
namespace util {
    typedef std::function<QList<QDir>(const QDir &)> DirectoryEnumerator;
    extern const DirectoryEnumerator FileDirectoryEnumerator;
}
}


#endif //VSAMPLER_FILEENUMERATOR_H
