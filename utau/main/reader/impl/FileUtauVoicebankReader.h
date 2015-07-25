/**
 * Created by Hal@shurabaP on 2015/06/11.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_FILEUTAUVOICEBANKREADER_H
#define VSAMPLER_FILEUTAUVOICEBANKREADER_H

#include <functional>
#include <io/DeviceFactory.h>
#include <io/DirectoryEnumerator.h>
#include "reader/VoicebankReader.h"
#include "MetaInfoReader.h"
#include "VoiceAliasLineReader.h"
#include "VoiceAliasesReader.h"

namespace vsampler {
namespace utau {
namespace impl {

    /**
     * This class is an implementation of UtauVoicebankReader.
     * FileUtauVoicebankReaderImpl reads UtauVoicebank from local files.
     */
    class FileUtauVoicebankReaderImpl final {
        MetaInfoReader metaInfoReader;
        VoiceAliasesReader voiceAliasesReader;
        VoiceAliasLineReader voiceAliasLineReader;
        util::DeviceFactory deviceFactory;
        util::DirectoryEnumerator directoryEnumerator;
    public:
        FileUtauVoicebankReaderImpl(
                const MetaInfoReader metaInfoReader = FileMetaInfoReader,
                const VoiceAliasesReader voiceAliasesReader = FileVoiceAliasesReader,
                const VoiceAliasLineReader voiceAliasLineReader = FileVoiceAliasLineReader,
                const util::DeviceFactory deviceFactory = util::FileDeviceFactory,
                const util::DirectoryEnumerator directoryEnumerator = util::FileDirectoryEnumerator) :
            metaInfoReader(metaInfoReader), voiceAliasesReader(voiceAliasesReader), voiceAliasLineReader(voiceAliasLineReader),
            deviceFactory(deviceFactory), directoryEnumerator(directoryEnumerator) { }

        Voicebank read(const QDir &directory, QTextCodec *codec);
    };
    extern const VoicebankReader FileUtauVoicebankReader;
}
}
}


#endif //VSAMPLER_FILEUTAUVOICEBANKREADER_H
