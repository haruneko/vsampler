/**
 * Created by Hal@shurabaP on 2015/06/23.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_TRYSPEC_H
#define VSAMPLER_TRYSPEC_H

#include <QtTest/QtTest>

#include "util/Try.h"
#include "../MultipleTest.h"

using namespace vsampler::util;

class TrySpec : public QObject {
    Q_OBJECT
private slots:
    void constructor_and_apply_should_properly_instantiate_Try() {
        Try<int> t1(1); QCOMPARE(t1.get(), 1); QCOMPARE(t1.isSuccess(), true);
        Try<int> t2(new vsampler::util::Exception()); QVERIFY_EXCEPTION_THROWN(t2.get(), Exception*); QCOMPARE(t2.isFailure(), true);
        Try<int> t3(t1); QCOMPARE(t3.get(), 1); QCOMPARE(t3.isSuccess(), true);
        t3 = Try<int>(150); QCOMPARE(t3.get(), 150);
        Try<int> t4(applyTry<int>([]() -> int { return 2525; })); QCOMPARE(t4.get(), 2525); QCOMPARE(t4.isSuccess(), true);
        Try<int> t5(applyTry<int>([]() -> int { throw new vsampler::util::Exception; /* unreachable  */ return 0; }));
        QVERIFY_EXCEPTION_THROWN(t5.get(), Exception*); QCOMPARE(t5.isFailure(), true);
    };
    void map_should_properly_apply_the_given_function() {
        Try<int> t1(10);
        QCOMPARE(t1.map<int>([](const int &t) -> int { return t * 20; }).get(), 200);
        QCOMPARE(t1.map<QString>([](const int &t) -> QString { return QString::number(t); }).get(), QString("10"));
        QVERIFY_EXCEPTION_THROWN(t1.map<int>([](const int &t) -> int { throw new Exception; return t * 20; }).get(), Exception*);
    }
    void flatMap_should_properly_apply_the_given_function() {
        Try<int> t1(10);
        QCOMPARE(t1.flatMap<int>([](const int &t) -> Try<int> { return Try<int>(2000); }).get(), 2000);
        QCOMPARE(t1.flatMap<QString>([](const int &t) -> Try<QString> { return Try<QString>("flatMap"); }).get(), QString("flatMap"));
        QVERIFY_EXCEPTION_THROWN(t1.flatMap<int>([](const int &t) -> Try<int> { throw new Exception; }).get(), Exception*);
    }
};

DECLARE_TEST(TrySpec);

#endif //VSAMPLER_TRYSPEC_H
