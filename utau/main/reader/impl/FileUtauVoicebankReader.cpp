/**
 * Created by Hal@shurabaP on 2015/06/11.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#include "FileUtauVoicebankReader.h"

namespace {
    const QString OtoIniName("oto.ini");
    const QString CharacterTxtName("character.txt");
}

const vsampler::utau::VoicebankReader vsampler::utau::impl::FileUtauVoicebankReader =
        [](const QDir &directory, QTextCodec *codec) -> vsampler::util::Try<vsampler::utau::Voicebank> {
            return vsampler::util::applyTry<vsampler::utau::Voicebank>(
                    [directory, codec]() -> vsampler::utau::Voicebank {
                        return FileUtauVoicebankReaderImpl().read(directory, codec);
                    }
            );
        };


vsampler::utau::Voicebank vsampler::utau::impl::FileUtauVoicebankReaderImpl::read(
        const QDir &directory, QTextCodec *codec) {
    QList<QDir> directories(directoryEnumerator(directory));
    MetaInfo metaInfo(metaInfoReader(QFileInfo(directory.filePath(CharacterTxtName)), codec, deviceFactory));

    QHash<QString, VoiceAlias> aliases;
    foreach(const QDir &dir, directories) {
        aliases.unite(voiceAliasesReader(QFileInfo(dir.filePath(OtoIniName)), codec, voiceAliasLineReader, deviceFactory));
    }

    return Voicebank(metaInfo, aliases, directory);
}
