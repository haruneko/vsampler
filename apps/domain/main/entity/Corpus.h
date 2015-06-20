/**
 * Created by Hal@shurabaP on 2015/06/07.
 * This code is under The BSD 3-Clause License.
 * See more Licence.txt.
 * Copyright (c) 2015 Hal@shurabaP. All rights reserved.
 */
#ifndef VSAMPLER_CORPUS_H
#define VSAMPLER_CORPUS_H

#include <QSharedData>
#include <QSharedDataPointer>
#include <QSharedPointer>
#include "repsoitory/CorpusRepository.h"

#include "value/CorpusProperty.h"
#include "Entity.h"
#include "util/Try.h"

namespace vsampler {
namespace domain {

    extern const QSharedPointer<CorpusRepository> DefaultCorpusRepository;

    class Corpus : public QObject, public Entity<CorpusId, corpus::CorpusProperty> {
        Q_OBJECT
    private:
        bool dirty;
    public:
        Corpus(QObject *parent = 0) : QObject(parent), Entity<CorpusId, corpus::CorpusProperty>(), dirty(false) { }
        Corpus(const CorpusId& id, const corpus::CorpusProperty &value, QObject *parent = 0)
                : QObject(parent), Entity<CorpusId, corpus::CorpusProperty>(id, value), dirty(false) { }
        Corpus(const Corpus &other) : QObject(other.parent()), Entity<CorpusId, corpus::CorpusProperty>(other), dirty(other.dirty) { }

        bool isDirty() const { return dirty; }
        util::Try<util::Unit> save(
                QSharedPointer<CorpusRepository> repository = DefaultCorpusRepository) const;
        util::Try<util::Unit> saveAs(
                const CorpusId &newId,
                QSharedPointer<CorpusRepository> repository = DefaultCorpusRepository) const;
    public slots:
        void setCorpusMetaInfo(const corpus::CorpusMetaInfo corpusMetaInfo);
        void insertPhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeMetaInfo phoneme);
        void deletePhoneme(const corpus::Pronounce pronounce, const corpus::PhonemeMetaInfo phoneme);
    signals:
        void corpusMetaInfoChanged(const corpus::CorpusMetaInfo corpusMetaInfo);
        void phonemeInserted(const corpus::Pronounce pronounce, const corpus::PhonemeMetaInfo phoneme);
        void phonemeDeleted(const corpus::Pronounce pronounce, const corpus::PhonemeMetaInfo phoneme);
    };
}
}



#endif //VSAMPLER_CORPUS_H
