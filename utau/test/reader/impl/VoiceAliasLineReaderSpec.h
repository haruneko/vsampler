/**
 * Created by Hal@shurabaP on 2015/04/28.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef UTAU_VOICEALIASESREADER_H
#define UTAU_VOICEALIASESREADER_H

#include <gmock/gmock.h>
#include <QtTest/QTest>
#include "value/VoiceAlias.h"
#include "reader/impl/VoiceAliasLineReader.h"
#include "../../MultipleTest.h"

Q_DECLARE_METATYPE(QSharedPointer<vsampler::utau::impl::VoiceAliasLineElement>)

namespace vsampler {
namespace utau {
namespace impl {

    class VoiceAliasLineReaderSpec : public QObject {
        Q_OBJECT
    private slots:
        void read_should_properly_parse_one_line_data() {
            QTest::addColumn<QString>("input");
            QTest::addColumn<QSharedPointer<VoiceAliasLineElement> >("expected");
            QTest::newRow("proper ") <<
                    "あ.wav=- あ,98,50,51,100,150" <<
                    QSharedPointer<VoiceAliasLineElement>(new VoiceAliasLineElement("あ", VoiceAlias(QFileInfo("あ.wav"), 98.0, 50.0, 51.0, 100, 150.0)));
            QTest::newRow("invalid1") << "あ.wav=,98,50,51,100" << QSharedPointer<VoiceAliasLineElement>();
            QTest::newRow("invalid2") << "あ.wav=98,50,51,100,150" << QSharedPointer<VoiceAliasLineElement>();
            QTest::newRow("invalid3") << "totally invalid" << QSharedPointer<VoiceAliasLineElement>();
        }

        void read_should_properly_parse_one_line() {
            QFETCH(QString, input);
            QFETCH(QSharedPointer<VoiceAliasLineElement>, expected);
            QCOMPARE(VoiceAliasLineReader::read(input), expected);
        }
    };

}
}
}
DECLARE_TEST(vsampler::utau::impl::VoiceAliasLineReaderSpec)

#endif //UTAU_VOICEALIASESREADER_H
