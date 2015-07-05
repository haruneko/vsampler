/**
 * Created by Hal@shurabaP on 2015/05/23.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef CORPUS_ROOT_PHONEMESET_H
#define CORPUS_ROOT_PHONEMESET_H

#include <QSet>

namespace vsampler {
namespace corpus {

    class PhonemeInfoProperty;
    typedef QSet<PhonemeInfoProperty> PhonemeSet;

}
}

Q_DECLARE_TYPEINFO(vsampler::corpus::PhonemeInfoProperty, Q_MOVABLE_TYPE);

#endif //CORPUS_ROOT_PHONEMESET_H
